//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#include "cbase.h"
#include "prediction2.h"
#include "interfaces.h"

CPrediction2 g_sPrediction2;
IPrediction2* g_pSource2ClientPrediction = &g_sPrediction2;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CPrediction2, IPrediction2, SOURCE2CLIENTPREDICTION_INTERFACE_VERSION, g_sPrediction2);
