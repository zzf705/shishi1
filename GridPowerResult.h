#pragma once
#include<iostream>
#include "complex.h"
#include<cmath>
#include<vector>
using namespace std;


class GridPowerResult
{
public:

	vector<complex> gridFinalPower;//������
	double gridFinalTotalPower;
	double gridPowerLoss;//������յ��Ӧ��·�����
	void findGridFinalTotalPower( float frequence);//���ÿ������Ĺ��ʣ���vector�еĹ������,Ƶ����mhzΪ��λ
};

