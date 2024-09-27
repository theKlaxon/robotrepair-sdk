//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#pragma once
#include "iappframework.h"
#include "platform.h"
#include "globalvars_base.h"

class ISource2Client : public IAppSystem {
public:

	virtual void Init(CreateInterfaceFn factory) = 0;
	virtual void Shutdown(long long par1) = 0;

	virtual void SetGlobals(/*uint64 par1, */CGlobalVarsBase* par2) = 0;
	virtual void thunk_FUN_10382e710() = 0;
	virtual void FUN_1039028a0() = 0;
	virtual void FUN_10390c660(uint64 par1, uint64 par2, uint64 par3) = 0;
	virtual void FUN_10390a610(uint64 par1, int par2) = 0;
	virtual void FUN_103901760() = 0;

	virtual void FUN_103902000(undefined8 param_1, undefined4 param_2, undefined4 param_3, undefined param_4) = 0;
	virtual void FUN_10390a740(undefined8 param_1, undefined4 param_2, undefined4 param_3, byte param_4) = 0;

	virtual void FUN_10390e590() = 0;
	virtual void FUN_103902680() = 0;
	virtual void FUN_103902270() = 0;

	virtual void FUN_1039039f0(undefined8 param_1, undefined4 param_2, undefined8 param_3) = 0;
	virtual void FUN_1039039e0(undefined8 param_1, undefined4 param_2) = 0;

	virtual void* FUN_103903fb0() = 0;
	virtual void FUN_103908b30(undefined8 param_1, undefined** param_2, undefined4* param_3, int param_4) = 0;

	virtual undefined8 FUN_103903510() = 0;
	virtual undefined8 FUN_10390b4d0(long long param_1, long long param_2, undefined8 param_3) = 0;

	virtual void FrameStageNotify(undefined8 param_1, int param_2) = 0;
	virtual void FUN_1039065d0() = 0;
	virtual void FUN_103906200(undefined8 param_1, undefined param_2) = 0;
	virtual void FUN_103905f20() = 0;
	virtual void FUN_103906090(undefined8 param_1, undefined8 param_2) = 0;
	virtual void FUN_103906750() = 0;
	virtual undefined8 FUN_103906770(undefined8 param_1, undefined4 param_2, undefined8 param_3, byte* param_4) = 0;
	virtual void FUN_103902100(undefined8 param_1, undefined4 param_2, undefined8 param_3, float* param_4, undefined8 param_5, undefined4 param_6, float* param_7) = 0;
	virtual void FUN_10390a500(undefined8 param_1, undefined4 param_2, undefined8 param_3, undefined8 param_4, undefined8 param_5, undefined4 param_6, undefined4 param_7, undefined8 param_8) = 0;
	virtual void FUN_1039098c0() = 0;
	virtual void FUN_103901530() = 0;
	virtual void FUN_10390dc20(undefined8 param_1, long long param_2) = 0;
	virtual void FUN_103909ab0() = 0;

	virtual void FUN_10390bf20() = 0;
	virtual byte FUN_103903ff0() = 0;
	virtual byte FUN_10390d400() = 0;
	virtual byte FUN_103907ec0() = 0;
	virtual void FUN_1039014b0() = 0;

	virtual byte FUN_103901520() = 0;
	virtual void FUN_1039096e0() = 0;
	virtual void FUN_103909aa0() = 0;
	virtual void FUN_10390c650() = 0;
	virtual void FUN_103908d90(undefined8 param_1, undefined8 param_2, long long* param_3) = 0;
	virtual void FUN_10390df90(undefined8 param_1, undefined4 param_2, undefined4 param_3, int param_4) = 0;
	virtual undefined8 FUN_103903bd0(undefined8 param_1, undefined4 param_2) = 0;
	virtual void FUN_10390d8f0(undefined8 param_1, undefined4* param_2, undefined4 param_3) = 0;
	virtual void thunk_FUN_103a000f0() = 0;

	virtual void FUN_1039067c0() = 0;
	virtual void FUN_10390ddd0(undefined8 param_1, long long param_2) = 0;
	virtual void FUN_10390c6f0(undefined8 param_1, undefined4 param_2) = 0;
	virtual void FUN_1039040d0(undefined8 param_1, undefined4 param_2, undefined8 param_3) = 0;
	virtual void FUN_103908a80() = 0;
	virtual byte FUN_1039014c0(undefined8 param_1, undefined8 param_2, undefined4 param_3) = 0;

	virtual void FUN_103908f10() = 0;
	virtual void FUN_103908f20() = 0;
	virtual void FUN_103908e70(long long* param_1, undefined8 param_2, undefined8* param_3) = 0;
	virtual void FUN_103908ed0() = 0;
	virtual void FUN_10390cb80(long long param_1, byte param_2, int param_3, undefined8 param_4, undefined4 param_5) = 0;
	virtual void FUN_103901850(long long par1) = 0;
	virtual void FUN_103909a90() = 0;
	virtual void FUN_103908f30(long long param_1, int param_2, int param_3, byte param_4) = 0;
	virtual byte FUN_10390ce90() = 0;
	virtual void FUN_103906fe0(long long param_1, undefined8* param_2, undefined4 param_3) = 0;
	virtual void FUN_103901790(long long par1) = 0;
	virtual byte FUN_10390d9f0() = 0;

	virtual void thunk_FUN_103a09d30() = 0;
	virtual void thunk_FUN_103a0cac0() = 0;
	virtual void thunk_FUN_103a18df0() = 0;
	virtual byte FUN_10390ce80() = 0;

	virtual void FUN_103903560(undefined8 param_1, undefined4 param_2, undefined8 param_3, undefined8 param_4, undefined8 param_5) = 0;
	virtual void FUN_1039098b0() = 0;
	virtual void FUN_10390d3e0() = 0;
	virtual byte FUN_1039035f0() = 0;
	virtual void FUN_103903a20(undefined8 param_1, undefined8 param_2, undefined4* param_3) = 0;
	virtual void FUN_10390d3c0() = 0;
	virtual unsigned long long FUN_103903880(undefined8 param_1, undefined4 param_2, undefined4* param_3) = 0;
	virtual void FUN_1039037f0(undefined8 param_1, undefined4 param_2, undefined4* param_3) = 0;
	virtual unsigned long long FUN_103903920(long long* param_1, unsigned long long param_2, long long param_3, int* param_4) = 0;
	virtual undefined8 FUN_103903a10() = 0;
	virtual void FUN_1039022d0(undefined8 param_1, undefined8 param_2, long long param_3, undefined8 param_4, undefined4 param_5) = 0;
	virtual void FUN_103909db0(undefined8 param_1, long long* param_2, long long param_3, int* param_4, long long param_5) = 0;
	virtual void FUN_103904040() = 0;
	virtual void FUN_103903580() = 0;
	virtual void FUN_10390dac0(undefined8 param_1, undefined8* param_2, long long** param_3) = 0;
	virtual void FUN_1039022b0(undefined8 param_1, long long* param_2) = 0;
	virtual void FUN_10390d970() = 0;
	virtual void FUN_103902290() = 0;
	virtual byte FUN_10390d7a0(undefined8 param_1, undefined8 param_2, undefined4* param_3, undefined8 param_4) = 0;
	virtual undefined8 FUN_103904060() = 0;
	virtual void FUN_103907f40(long long par1) = 0;
	virtual undefined8 FUN_103902660(undefined8 param_1, undefined8 param_2) = 0;
	virtual byte FUN_103902670() = 0;
	virtual void FUN_103908b20() = 0;
	virtual byte FUN_10390df80() = 0;
	virtual void FUN_10390dc00(undefined8 param_1, undefined4 param_2) = 0;

	virtual void FUN_10390d9e0() = 0;
	virtual byte FUN_103903a70() = 0;
	virtual void FUN_103909a70() = 0;
	virtual void FUN_10390d980() = 0;
	virtual undefined8 FUN_1039037e0() = 0;
	virtual void thunk_FUN_10382ecc0() = 0;
	virtual void FUN_103908a90(undefined8 param_1, undefined4 param_2, undefined8 param_3) = 0;
	virtual undefined8 FUN_103903ba0() = 0;
	virtual undefined4 FUN_103904100(undefined8 param_1, undefined4* param_2, undefined4* param_3) = 0;
};