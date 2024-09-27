//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#pragma once
#include "iappframework.h"
#include "isource2_client.h"

// the original client dll we are built on
static ISource2Client* g_pClientDLL = nullptr;

class CSource2Client: public CBaseAppSystem<ISource2Client> {
public:

	virtual bool Connect(CreateInterfaceFn factory);
	virtual void Disconnect();

	virtual void* QueryInterface(const char* pInterfaceName) { return 0; }

	virtual void Init(CreateInterfaceFn facotry);
	virtual void Shutdown(long long par1);

	virtual void PreShutdown()							{ }
	virtual const AppSystemInfo_t* GetDependencies()	{ return 0; }
	virtual AppSystemTier_t GetTier()					{ return APP_SYSTEM_TIER3; }

	virtual void Reconnect(CreateInterfaceFn factory, const char* pInterfaceName)	{ }
	virtual bool IsSingleton()														{ return 1; }
	virtual AppSystemBuildType_t GetBuildType()										{ return BUILDTYPE_2; }


	virtual void SetGlobals(/*uint64 par1, */CGlobalVarsBase* par2) { }
	virtual void thunk_FUN_10382e710() { }
	virtual void FUN_1039028a0() { }
	virtual void FUN_10390c660(uint64 par1, uint64 par2, uint64 par3) { }
	virtual void FUN_10390a610(uint64 par1, int par2) { }
	virtual void FUN_103901760() { }

	virtual void FUN_103902000(undefined8 param_1, undefined4 param_2, undefined4 param_3, undefined param_4) { }
	virtual void FUN_10390a740(undefined8 param_1, undefined4 param_2, undefined4 param_3, byte param_4) { }

	virtual void FUN_10390e590() { }
	virtual void FUN_103902680() { }
	virtual void FUN_103902270() { }

	virtual void FUN_1039039f0(undefined8 param_1, undefined4 param_2, undefined8 param_3) { }
	virtual void FUN_1039039e0(undefined8 param_1, undefined4 param_2) { }

	virtual void* FUN_103903fb0() { return nullptr; }
	virtual void FUN_103908b30(undefined8 param_1, undefined** param_2, undefined4* param_3, int param_4) { }
	
	virtual undefined8 FUN_103903510() { return 1; }
	virtual undefined8 FUN_10390b4d0(long long param_1, long long param_2, undefined8 param_3) { return 0; }

	virtual void FrameStageNotify(undefined8 param_1, int param_2) { }
	virtual void FUN_1039065d0() { }
	virtual void FUN_103906200(undefined8 param_1, undefined param_2) { }
	virtual void FUN_103905f20() { }
	virtual void FUN_103906090(undefined8 param_1, undefined8 param_2) { }
	virtual void FUN_103906750() { }

	virtual undefined8 FUN_103906770(undefined8 param_1, undefined4 param_2, undefined8 param_3, byte* param_4) { return 0; }
	virtual void FUN_103902100(undefined8 param_1, undefined4 param_2, undefined8 param_3, float* param_4, undefined8 param_5, undefined4 param_6, float* param_7) { }
	virtual void FUN_10390a500(undefined8 param_1, undefined4 param_2, undefined8 param_3, undefined8 param_4, undefined8 param_5, undefined4 param_6, undefined4 param_7, undefined8 param_8) { }

	virtual void FUN_1039098c0() { }
	virtual void FUN_103901530() { }
	virtual void FUN_10390dc20(undefined8 param_1, long long param_2) { }
	virtual void FUN_103909ab0() { }

	virtual void FUN_10390bf20() { }
	virtual byte FUN_103903ff0() { return 1; }
	virtual byte FUN_10390d400() { return 0; }
	virtual byte FUN_103907ec0() { return 0; }
	virtual void FUN_1039014b0() { }

	virtual byte FUN_103901520() { return 1; }
	virtual void FUN_1039096e0() { }
	virtual void FUN_103909aa0() { }
	virtual void FUN_10390c650() { }

	virtual void FUN_103908d90(undefined8 param_1, undefined8 param_2, long long* param_3) { }
	virtual void FUN_10390df90(undefined8 param_1, undefined4 param_2, undefined4 param_3, int param_4) { }
	virtual undefined8 FUN_103903bd0(undefined8 param_1, undefined4 param_2) { return 0; }
	virtual void FUN_10390d8f0(undefined8 param_1, undefined4* param_2, undefined4 param_3) { }
	virtual void thunk_FUN_103a000f0() { }

	virtual void FUN_1039067c0() {  }
	virtual void FUN_10390ddd0(undefined8 param_1, long long param_2) { }
	virtual void FUN_10390c6f0(undefined8 param_1, undefined4 param_2) { }
	virtual void FUN_1039040d0(undefined8 param_1, undefined4 param_2, undefined8 param_3) { }
	virtual void FUN_103908a80() {  }
	virtual byte FUN_1039014c0(undefined8 param_1, undefined8 param_2, undefined4 param_3) { return 0; }

	virtual void FUN_103908f10() { }
	virtual void FUN_103908f20() { }
	virtual void FUN_103908e70(long long* param_1, undefined8 param_2, undefined8* param_3) { }
	virtual void FUN_103908ed0() { }

	virtual void FUN_10390cb80(long long param_1, byte param_2, int param_3, undefined8 param_4, undefined4 param_5) { }

	virtual void FUN_103901850(long long par1) { }
	virtual void FUN_103909a90() {  }
	virtual void FUN_103908f30(long long param_1, int param_2, int param_3, byte param_4) { }
	virtual byte FUN_10390ce90() { return 0; }
	virtual void FUN_103906fe0(long long param_1, undefined8* param_2, undefined4 param_3) { }
	virtual void FUN_103901790(long long par1) { }
	virtual byte FUN_10390d9f0() { return 1; }			// every frame (first)

	virtual void thunk_FUN_103a09d30() { }
	virtual void thunk_FUN_103a0cac0() { }
	virtual void thunk_FUN_103a18df0() { }
	virtual byte FUN_10390ce80() { return 1; }

	virtual void FUN_103903560(undefined8 param_1, undefined4 param_2, undefined8 param_3, undefined8 param_4, undefined8 param_5) { }
	virtual void FUN_1039098b0() { }
	virtual void FUN_10390d3e0() { }
	virtual byte FUN_1039035f0() { return 0; }
	virtual void FUN_103903a20(undefined8 param_1, undefined8 param_2, undefined4* param_3) { }
	virtual void FUN_10390d3c0() { }

	virtual unsigned long long FUN_103903880(undefined8 param_1, undefined4 param_2, undefined4* param_3) { return 0; }
	virtual void FUN_1039037f0(undefined8 param_1, undefined4 param_2, undefined4* param_3) { }
	virtual unsigned long long FUN_103903920(long long* param_1, unsigned long long param_2, long long param_3, int* param_4) { return 0; }
	virtual undefined8 FUN_103903a10() { return 0; }

	virtual void FUN_1039022d0(undefined8 param_1, undefined8 param_2, long long param_3, undefined8 param_4, undefined4 param_5) { }
	virtual void FUN_103909db0(undefined8 param_1, long long* param_2, long long param_3, int* param_4, long long param_5) { }

	virtual void FUN_103904040() { }
	virtual void FUN_103903580() { }

	virtual void FUN_10390dac0(undefined8 param_1, undefined8* param_2, long long** param_3) { }
	virtual void FUN_1039022b0(undefined8 param_1, long long* param_2) { }

	virtual void FUN_10390d970() { }
	virtual void FUN_103902290() { }

	virtual byte FUN_10390d7a0(undefined8 param_1, undefined8 param_2, undefined4* param_3, undefined8 param_4) { return 0; }
	virtual undefined8 FUN_103904060() { return 0; }
	virtual void FUN_103907f40(long long par1) { }
	virtual undefined8 FUN_103902660(undefined8 param_1, undefined8 param_2) { return param_2; }

	virtual byte FUN_103902670() { return 0; }
	virtual void FUN_103908b20() { }				// every frame (second)
	virtual byte FUN_10390df80() { return 0; }

	virtual void FUN_10390dc00(undefined8 param_1, undefined4 param_2) { }

	virtual void FUN_10390d9e0() { }
	virtual byte FUN_103903a70() { return 0; }
	virtual void FUN_103909a70() { }
	virtual void FUN_10390d980() { }

	virtual undefined8 FUN_1039037e0() { return 0; }
	virtual void thunk_FUN_10382ecc0() { }

	virtual void FUN_103908a90(undefined8 param_1, undefined4 param_2, undefined8 param_3) { }
	virtual undefined8 FUN_103903ba0() { return 0; }
	virtual undefined4 FUN_103904100(undefined8 param_1, undefined4* param_2, undefined4* param_3) { return 0; }

};
