#pragma once
#include<iostream>
#include <sstream>
#include <string>
#include<math.h>
using namespace std;
#import "C:\\program files\\common files\\system\\ado\\msado15.dll"  no_namespace rename("EOF", "adoEOF")

#define pi 3.14



class ShootingRay
{
public:
	ShootingRay(void);
	~ShootingRay(void);

	float Rx,Ry,Rz,Rgain;
	int shootingNumber;//获得射线的数目
	/*void shootingGain(float directionAngle,float downInclineAngle,float horizonDivision,float verticalDivision);*/
	void shootingGainAllDirection(float directionAngle,float downInclineAngle,float horizonRange, float verticalRange,
		float horizonDivision,float verticalDivision);//射线发射是全向的
	void GetRecord(int id);
};

