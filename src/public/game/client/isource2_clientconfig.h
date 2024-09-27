//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#pragma once
#include "iappframework.h"
#include "platform.h"
#include "interfaces.h"

class ISource2ClientConfig : public IAppSystem {
public:

	virtual byte GetMaxSplitscreenPlayers() = 0;
	virtual void FUN_1011e5ab0() = 0;
    virtual byte FUN_1011ec470() = 0;
    
    virtual undefined8 FUN_1011e7f50() = 0;

    virtual void FUN_1011ed080() = 0;
    virtual void FUN_1011eb5b0() = 0;

    virtual undefined8 FUN_1011e68c0() = 0;
    virtual undefined8 FUN_1011e6c40() = 0;

    virtual void FUN_1011ec620(undefined8 par1, undefined8 par2, undefined8 par3) = 0;

    virtual byte FUN_1011e8830() = 0;
    virtual undefined8 FUN_1011e6890() = 0;
    virtual undefined8 FUN_1011e6a40() = 0;
    
    virtual void FUN_1011e39e0(undefined8 par1, undefined8 par2, undefined8 par3, unsigned int par4) = 0;
    virtual undefined4* FUN_1011e68e0(undefined8 par1, undefined4* par2) = 0;

    virtual byte FUN_1011e8820() = 0;
    virtual byte FUN_1011e8810() = 0;
};