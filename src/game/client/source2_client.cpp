//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#include "cbase.h"
#include "source2_client.h"
#include "source2_clientconfig.h"
#include "interfaces.h"

CDefaultGameConfig g_sDefualtClientConfig;
ISource2ClientConfig* g_pSource2ClientConfig = &g_sDefualtClientConfig;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CDefaultGameConfig, ISource2ClientConfig, SOURCE2CLIENTCONFIG_INTERFACE_VERSION, g_sDefualtClientConfig);

CSource2Client g_sSource2Client;
ISource2Client* g_pSource2Client = &g_sSource2Client;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CSource2Client, ISource2Client, SOURCE2CLIENT_INTERFACE_VERSION, g_sSource2Client);

//static CGlobalVarsBase dummyvars(true);

bool CSource2Client::Connect(CreateInterfaceFn factory) {
	
	Msg("Klaxon was here >:)\n");

	return true;
}

void CSource2Client::Disconnect() {

}

void CSource2Client::Init(CreateInterfaceFn factory) {

	Msg("CSource2Client::Init -- Begin\n");

	Msg("CSource2Client::Init -- End\n");
	
	return;
}

void CSource2Client::Shutdown(long long par1) {

	Msg("CSource2Client::Shutdown");

}