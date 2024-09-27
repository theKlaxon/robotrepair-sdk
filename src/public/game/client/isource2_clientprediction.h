#pragma once
#include "iappframework.h"

// TODO: gather from CDOTAPrediction in libclient.dylib, double check vtable against client_vr.dll (original client.dll for vrgdc)
class CSplitScreenSlot;

class IPrediction2 : public IAppSystem {
public:

	virtual ~IPrediction2() {}
	
	// IPrediction
	virtual void Update(int param_1, bool param_2, int param_3, int param_4) = 0;
	virtual void PreEntityPacketReceived(class CSplitScreenSlot* param_1, int param_2, int param_3) = 0;
	virtual void NetUpdateStart(class CSplitScreenSlot* param_1) = 0;
	virtual void PostEntityPacketReceived(class CSplitScreenSlot* param_1) = 0;
	virtual void PostNetworkDataReceived(class CSplitScreenSlot* param_1, int param_2) = 0;
	virtual void OnReceivedUncompressedPacket() = 0;

	virtual void GetViewOrigin(class CSplitScreenSlot* param_1, class Vector* param_2) = 0;
	virtual void GetViewAngles(class CSplitScreenSlot* param_1, class QAngle* param_2) = 0;
	virtual void SetViewOriginAngles(class CSplitScreenSlot* param_1, class Vector* param_2, class QAngle* param_3) = 0;
	virtual void GetLocalViewAngles(class CSplitScreenSlot* param_1, class QAngle* param_2) = 0;
	virtual void SetLocalViewAngles(class CSplitScreenSlot* param_1, class QAngle* param_2) = 0;
	virtual bool HasAnyPredictables() = 0;
	
	virtual bool InPrediction() const = 0;
	virtual bool IsFirstTimePredicted() const = 0;

	virtual int GetIncomingPacketNumber() = 0;
	virtual void CheckMovingGround(class C_BasePlayer* param_1, double param_2) = 0;
	virtual void RunCommand(class C_BasePlayer* param_1, class CUserCmd* param_2, class IMoveHelper* param_3) = 0;
	virtual void SetupMove(class C_BasePlayer* param_1, class CUserCmd* param_2, class IMoveHelper* param_3, class CMoveData* param_4) = 0;
	virtual void FinishMove(class C_BasePlayer* param_1, class CUserCmd* param_2, class CMoveData* param_3) = 0;
	virtual void CheckError(class CSplitScreenSlot* param_1, class C_BasePlayer* param_2, int param_3) = 0;
	virtual void _Update(class CSplitScreenSlot* param_1, bool param_2, bool param_3, int param_4, int param_5) = 0;

};