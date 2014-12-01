#pragma once
#include<iostream>
#include "complex.h"
#include<vector>
using namespace std;


class rayPath
{
public:
	rayPath(void);
	~rayPath(void);

	float  firstPointx,firstPointy,firstPointz;//������ʼ�������
	float  firstDirectiona,firstDirectionb,firstDirectionc;
	float  rayGain;

	vector<float>reflecttDirectiona;
	vector<float>reflecttDirectionb;
	vector<float>reflecttDirectionc;
	vector<float>reflecttAngle;
	vector<float>reflecttCoefficient;
	vector<float>crossPointx;
	vector<float>crossPointy;
	vector<float>crossPointz;
	vector<float>rayLength;
	vector<int>searchGridNumberTrue;//��¼ÿ����ģ������ʵ�ʾ���������ĸ���
	vector<int>searchGridTrueX;//��¼ÿ����ģ������ʵ�ʾ����������ˮƽ���
	vector<int>searchGridTrueY;//��¼ÿ����ģ������ʵ�ʾ���������Ĵ�ֱ���
	vector<int>positioniState;
	vector<complex>reflectComplexCoefficient;//���븴�ķ���ϵ��

};

