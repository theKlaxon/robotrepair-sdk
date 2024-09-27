#pragma once
#include "isource2_clientprediction.h"

class CPrediction2 : public CBaseAppSystem<IPrediction2> {
public:
	//DECLARE_CLASS_GAMEROOT(CPrediction, IPrediction); // TODO: port networkvar

			CPrediction2(void) {}
	virtual	~CPrediction2(void) {}

	virtual InitReturnVal_t	Init() { return INIT_OK; }
	virtual void			Shutdown() {}

	virtual void Update(int startframe, bool validframe, int incoming_acknowledged, int outgoing_command) {}
	virtual void PreEntityPacketReceived(class CSplitScreenSlot* pSlot, int commands_acknowledged, int current_world_update_packet) {}
	virtual void NetUpdateStart(class CSplitScreenSlot* pSlot) {}
	virtual void PostEntityPacketReceived(class CSplitScreenSlot* pSlot) {}
	virtual void PostNetworkDataReceived(class CSplitScreenSlot* pSlot, int commands_acknowledged) {}
	virtual void OnReceivedUncompressedPacket() {}

	virtual void GetViewOrigin(class CSplitScreenSlot* pSlot, class Vector* org) {}
	virtual void GetViewAngles(class CSplitScreenSlot* pSlot, class QAngle* ang) {}
	virtual void SetViewOriginAngles(class CSplitScreenSlot* pSlot, class Vector* org, class QAngle* ang) {}
	virtual void GetLocalViewAngles(class CSplitScreenSlot* pSlot, class QAngle* ang) {}
	virtual void SetLocalViewAngles(class CSplitScreenSlot* pSlot, class QAngle* ang) {}
	virtual bool HasAnyPredictables() { return false; }

	virtual bool InPrediction() const { return false; }
	virtual bool IsFirstTimePredicted() const { return false; }

	virtual int GetIncomingPacketNumber() { return 0; }
	virtual void CheckMovingGround(class C_BasePlayer* pPlayer, double frametime) {}
	virtual void RunCommand(class C_BasePlayer* pPlayer, class CUserCmd* pCmd, class IMoveHelper* pMoveHelper) {}
	virtual void SetupMove(class C_BasePlayer* pPlayer, class CUserCmd* pCmd, class IMoveHelper* pMoveHelper, class CMoveData* pMoveData) {}
	virtual void FinishMove(class C_BasePlayer* pPlayer, class CUserCmd* pCmd, class CMoveData* move) {}

	virtual void CheckError(class CSplitScreenSlot* pSlot, class C_BasePlayer* pPlayer, int commands_acknowledged) {}
	virtual void _Update(class CSplitScreenSlot* pSlot, bool bReceivedNewWorldUpdate, bool bValidFrame, int incoming_acknowledged, int outgoing_command) {}

};