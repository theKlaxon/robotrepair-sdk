//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#pragma once
#include "interfaces/interfaces.h"

struct AppSystemInfo_t
{
	const char* m_pModuleName;
	const char* m_pInterfaceName;
};

enum InitReturnVal_t
{
	INIT_FAILED = 0,
	INIT_OK,

	INIT_LAST_VAL
};

enum AppSystemTier_t
{
	APP_SYSTEM_TIER0 = 0,
	APP_SYSTEM_TIER1,
	APP_SYSTEM_TIER2,
	APP_SYSTEM_TIER3,

	APP_SYSTEM_TIER_OTHER
};

// TODO: populate this with actual values
enum AppSystemBuildType_t
{
	BUILDTYPE_0 = 0,
	BUILDTYPE_1,
	BUILDTYPE_2
};

class IAppSystem {
public:
	virtual bool Connect(CreateInterfaceFn factory) = 0;
	virtual void Disconnect() = 0;
	virtual void* QueryInterface(const char* pInterfaceName) = 0;

	virtual InitReturnVal_t Init() = 0;
	virtual void Shutdown() = 0;
	virtual void PreShutdown() = 0;

	virtual const AppSystemInfo_t* GetDependencies() { return nullptr; }
	virtual AppSystemTier_t GetTier() { return APP_SYSTEM_TIER_OTHER; }

	virtual void Reconnect(CreateInterfaceFn factory, const char* pInterfaceName) {}
	virtual bool IsSingleton() { return true; }
	virtual AppSystemBuildType_t GetBuildType() { return BUILDTYPE_2; } // new for source 2
};

template <class IInterface>
class CBaseAppSystem : public IAppSystem, public IInterface {
public:

	// Here's where the app systems get to learn about each other 
	virtual bool Connect(CreateInterfaceFn factory) { return true; }
	virtual void Disconnect() {}

	// Here's where systems can access other interfaces implemented by this object
	// Returns NULL if it doesn't implement the requested interface
	virtual void* QueryInterface(const char* pInterfaceName) { return nullptr; }

	// Init, shutdown
	virtual InitReturnVal_t Init() { return INIT_OK; }
	virtual void Shutdown() {}
	virtual void PreShutdown() {}

	virtual const AppSystemInfo_t* GetDependencies() { return nullptr; }
	virtual AppSystemTier_t GetTier() { return APP_SYSTEM_TIER_OTHER; }

	virtual void Reconnect(CreateInterfaceFn factory, const char* pInterfaceName)
	{
		ReconnectInterface(factory, pInterfaceName);
	}

};