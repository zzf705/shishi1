#pragma once
#include<iostream>
#include "findGrid.h"
#include "rayManage.h"
#include"gridPowerResult.h"
#include "Grid.h"
#include <sstream>
#include "rayPath.h"
#include "complex.h"
#include<cmath>
using namespace std;
#import "C:\\program files\\common files\\system\\ado\\msado15.dll"  no_namespace rename("EOF", "adoEOF")
#define COLOR1  188*256*256+31*256+102
#define COLOR2  217*256*256+25*256+102 
#define COLOR3  237*256*256+28*256+36 
#define COLOR4  238*256*256+72*256+34 
#define COLOR5  254*256*256+120*256+8
#define COLOR6  245*256*256+158*256+29
#define COLOR7  255*256*256+217*256+1
#define COLOR8  255*256*256+242*256  
#define COLOR9  231*256*256+255*256+5
#define COLOR10  194*256*256+255*256+3
#define COLOR11  104*256*256+253*256+23
#define COLOR12  7*256*256+203*256+17
#define COLOR13  151*256+58
#define COLOR14  145*256+124
#define COLOR15  145*256+200
#define COLOR16  101*256+171
#define COLOR17  72*256+144
class gridPower
{
public:
	   //void findGroundGridPowerFirst(float groundCrossPointx,float groundCrossPointy,float shootingStartx,float shootingStarty,
		  // float shootingStartz,float shootingDirectiona,float shootingDirectionb,float shootingDirectionc,float shootingLength,float antennaGain,gridPowerResult gridNumber[]);//���߸տ�ʼ����ؼ���������
	   ////���ߵ���ʱ����䵽���棬����Ե�������Ĺ���
	   //void findGroundGridPowerSecond(float groundCrossPointx,float groundCrossPointy,float shootingStartx,float shootingStarty,float shootingStartz,float shootingDirectiona,float shootingDirectionb,float shootingDirectionc,float shootingLength,float antennaGain,float totalRefCoefficient,gridPowerResult gridNumber[]);
	  void gridAllPowerCalculate(rayPath raypath1,float rayInterval,float frequence,int rayRecord,float kuixian);//���ڼ������߶���������Ĺ���,���һ�������������߼�������ڼ��������,Ƶ����MHZΪ��λ,rayRecord���ڼ���������ֵ���ĸ����߹��׵�
	  void gridRayLook(rayPath raypath1,float rayInterval,float frequence,int rayRecord,float kuixian);//������ͶӰ�켣�ò�ͬ��ɫ������
};

