//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: A higher level link library for general use in the game and tools.
//
//=============================================================================//

/* This is totally reverse-engineered code and may be wrong */

#include "interfaces\interfaces.h"

extern ISource2Client* g_pSource2Client;
extern ISource2ClientConfig* g_pSource2ClientConfig;
extern IPrediction2* g_pSource2ClientPrediction;

struct InterfaceGlobals_t
{
	const char *m_pInterfaceName;
	void *m_ppGlobal;
};

struct ConnectionRegistration_t
{
	void *m_ppGlobalStorage;
	int m_nConnectionPhase;
};

static const InterfaceGlobals_t g_pInterfaceGlobals[] =
{
	{ SOURCE2CLIENTCONFIG_INTERFACE_VERSION, &g_pSource2ClientConfig },
	{ SOURCE2CLIENT_INTERFACE_VERSION, &g_pSource2Client },
	{ SOURCE2CLIENTPREDICTION_INTERFACE_VERSION, &g_pSource2ClientPrediction },
};

static const int NUM_INTERFACES = sizeof(g_pInterfaceGlobals) / sizeof(InterfaceGlobals_t);

static int s_nConnectionCount;
static int s_nRegistrationCount;

static ConnectionRegistration_t s_pConnectionRegistration[NUM_INTERFACES + 1];

void ReconnectInterface(CreateInterfaceFn factory, char const *pInterfaceName, void **ppGlobal);

void ConnectInterfaces(CreateInterfaceFn *pFactoryList, int nFactoryCount)
{
	if (s_nRegistrationCount < 0)
	{
		//Error("APPSYSTEM: In ConnectInterfaces(), s_nRegistrationCount is %d!\n", s_nRegistrationCount);
		//Plat_ExitProcess(1);
		s_nConnectionCount++;
		return;
	}

	if (s_nRegistrationCount)
	{
		for (int i = 0; i < nFactoryCount; i++)
		{
			for (int j = 0; j < NUM_INTERFACES; j++)
			{
				ReconnectInterface(pFactoryList[i],  g_pInterfaceGlobals[j].m_pInterfaceName, (void **)g_pInterfaceGlobals[j].m_ppGlobal);
			}
		}

		s_nConnectionCount++;
		return;
	}

	for (int i = 0; i < nFactoryCount; i++)
	{
		for (int j = 0; j < NUM_INTERFACES; j++)
		{
			const InterfaceGlobals_t &iface = g_pInterfaceGlobals[j];

			if (!(*(void **)iface.m_ppGlobal))
			{
				void *ptr = pFactoryList[i](iface.m_pInterfaceName, NULL);
				*(void **)iface.m_ppGlobal = ptr;
				if (ptr)
				{
					ConnectionRegistration_t &reg = s_pConnectionRegistration[s_nRegistrationCount++];
					reg.m_ppGlobalStorage = iface.m_ppGlobal;
					reg.m_nConnectionPhase = s_nConnectionCount;
				}
			}
		}
	}

	s_nConnectionCount++;
}

void DisconnectInterfaces()
{
	if (--s_nConnectionCount >= 0)
	{
		for (int i = 0; i < s_nRegistrationCount; i++)
		{
			ConnectionRegistration_t &reg = s_pConnectionRegistration[i];
			if (reg.m_nConnectionPhase == s_nConnectionCount)
				reg.m_ppGlobalStorage = NULL;
		}
	}
}

void ReconnectInterface(CreateInterfaceFn factory, char const *pInterfaceName, void **ppGlobal)
{
	bool got = false;

	*ppGlobal = factory(pInterfaceName, NULL);

	for (int i = 0; i < s_nRegistrationCount; i++)
	{
		if (s_pConnectionRegistration[i].m_ppGlobalStorage == ppGlobal)
		{
			got = true;
			break;
		}
	}

	if ((s_nRegistrationCount <= 0 || !got) && *ppGlobal)
	{
		ConnectionRegistration_t &reg = s_pConnectionRegistration[s_nRegistrationCount++];
		reg.m_ppGlobalStorage = ppGlobal;
		reg.m_nConnectionPhase = s_nConnectionCount;
	}
}

void ReconnectInterface(CreateInterfaceFn factory, const char *pInterfaceName)
{
	if (pInterfaceName == nullptr)
		return;

	for (int i = 0; i < NUM_INTERFACES; i++)
	{
		const InterfaceGlobals_t &iface = g_pInterfaceGlobals[i];

		if (strcmp(iface.m_pInterfaceName, pInterfaceName) == 0)
			ReconnectInterface(factory, iface.m_pInterfaceName, (void **)iface.m_ppGlobal);
	}
}

// ------------------------------------------------------------------------------------ //
// InterfaceReg.
// ------------------------------------------------------------------------------------ //
InterfaceReg *s_pInterfaceRegs = NULL;

InterfaceReg::InterfaceReg(InstantiateInterfaceFn fn, const char *pName) :
	m_pName(pName)
{
	m_CreateFn = fn;
	m_pNext = s_pInterfaceRegs;
	s_pInterfaceRegs = this;
}

// ------------------------------------------------------------------------------------ //
// CreateInterface.
// This is the primary exported function by a dll, referenced by name via dynamic binding
// that exposes an opqaue function pointer to the interface.
// ------------------------------------------------------------------------------------ //
void* CreateInterface(const char *pName, int *pReturnCode)
{
	InterfaceReg *pCur;

	for (pCur = s_pInterfaceRegs; pCur; pCur = pCur->m_pNext)
	{
		if (strcmp(pCur->m_pName, pName) == 0)
		{
			if (pReturnCode)
			{
				*pReturnCode = IFACE_OK;
			}
			return pCur->m_CreateFn();
		}
	}

	if (pReturnCode)
	{
		*pReturnCode = IFACE_FAILED;
	}
	return NULL;
}
