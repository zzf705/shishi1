#pragma once
#include "ShootingRay.h"
#include "rayPath.h"
#include "rayManage.h"
#include"gridPower.h"
#include "GridPowerResult.h"
#include"empiricalFormula.h"
#include"BuildingPoint.h"
class basestationShooting
{
public:
	 void basestationOperate(int maxGridx,int maxGridy,float shootingInterval,float baseFrequence,float basePositionx,
		 float basePositiony,float basePositionz,float fangWeiJiao,float xiaQingJiao,float shuipingRange,float shuizhiRange,int baseStationNumber,float kuiLength,vector<vector<BuildingPoint>> BX,vector<float> HX);
	 //����ˮƽ����ţ���ֱ����ţ����߼������վƵ�ʣ���վλ�ã���λ�ǣ�����ǣ�ˮƽ���䷶Χ����ֱ���䷶Χ
};

