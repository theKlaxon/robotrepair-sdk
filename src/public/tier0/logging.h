//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#pragma once

#include "Color.h"
//void ConMsg(char const* param_1, ...);

enum LoggingResponse_t {
	LR_CONTINUE,
	LR_DEBUGGER,
	LR_ABORT,
};

enum LoggingSeverity_t {
	LS_MESSAGE = 0,
	LS_WARNING = 1,
	LS_ASSERT = 2,
	LS_ERROR = 3,
	LS_HIGHEST_SEVERITY = 4,
};

typedef char* LeafCodeInfo_t;
typedef int LoggingChannelID_t;
typedef void (*RegisterTagsFunc)();

static Color UNSPECIFIED_LOGGING_COLOR(0, 0, 0, 0);

int LoggingSystem_RegisterLoggingChannel(byte* param_1, char** param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5);
LoggingChannelID_t LoggingSystem_RegisterLoggingChannel(const char* pName, RegisterTagsFunc registerTagsFunc, int flags = 0, LoggingSeverity_t severity = LS_MESSAGE, Color color = UNSPECIFIED_LOGGING_COLOR);
LoggingResponse_t LoggingSystem_Log(LoggingChannelID_t chanID, LoggingSeverity_t severity, Color color, char const* param_4, ...);
