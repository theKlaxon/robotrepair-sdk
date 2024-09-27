//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#pragma once
#include "isource2_clientconfig.h"
#include "interfaces.h"

class CSource2ClientConfig : public ISource2ClientConfig {
public:

    virtual byte GetMaxSplitscreenPlayers() { return 1; }
    virtual void FUN_1011e5ab0() { return; }
    virtual byte FUN_1011ec470() { return 0; }

    virtual undefined8 FUN_1011e7f50() { return 1; }

    virtual void FUN_1011ed080() {}
    virtual void FUN_1011eb5b0() {}

    virtual undefined8 FUN_1011e68c0() { return 0; }
    virtual undefined8 FUN_1011e6c40() { return 6; }

    virtual void FUN_1011ec620(undefined8 par1, undefined8 par2, undefined8 par3) { return; }

    virtual byte FUN_1011e8830() { return 1; }
    virtual undefined8 FUN_1011e6890() { return 1; }
    virtual undefined8 FUN_1011e6a40() { return 4; }

    virtual void FUN_1011e39e0(undefined8 par1, undefined8 par2, undefined8 par3, unsigned int par4) { return; }
    virtual undefined4* FUN_1011e68e0(undefined8 par1, undefined4* par2) { *par2 = 0x1afdd6d2; return par2; }

    virtual byte FUN_1011e8820() { return 1; }
    virtual byte FUN_1011e8810() { return 0; }

};

class CDefaultGameConfig : public CBaseAppSystem<CSource2ClientConfig> {
public:


};