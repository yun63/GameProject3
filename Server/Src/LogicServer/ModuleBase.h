﻿#ifndef __CMODULE_BASE_H__
#define __CMODULE_BASE_H__
#include "AVLTree.h"
#include "Position.h"
#include "../Message/Msg_LoginDBData.pb.h"
#include "../Message/Msg_LoginCltData.pb.h"
#include "../ServerData/ServerDefine.h"

class CPlayerObject;

class CModuleBase
{
public:
	CModuleBase(CPlayerObject* pOwner);

	~CModuleBase();

	virtual BOOL OnCreate(UINT64 u64RoleID) = 0;

	virtual BOOL OnDestroy() = 0;

	virtual BOOL OnLogin() = 0;

	virtual BOOL OnLogout() = 0;

	virtual BOOL OnNewDay() = 0;

	virtual BOOL ReadFromDBLoginData(DBRoleLoginAck& Ack) = 0;

	virtual BOOL SaveToClientLoginData(RoleLoginAck& Ack) = 0;

	virtual BOOL DispatchPacket(NetPacket* pNetPack);

	virtual BOOL CalcFightValue(INT32 nValue[PROPERTY_NUM], INT32 nPercent[PROPERTY_NUM], INT32& FightValue);

	BOOL SetOwner(CPlayerObject* pOwner);

	CPlayerObject* GetOwner();

public:
	CPlayerObject* m_pOwnPlayer;
};


#endif //__CMODULE_BASE_H__
