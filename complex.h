#pragma once
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class complex
{
public:

	float real;
    float img;
};


class complexCalculate
{
public:
	complex consequence;//������
public:
	void findComplexRoot(complex x);//���㸴���Ŀ�����
	void findComplexMulConst(complex x,float coefficient);//���㸴������һ������
	void findComplexAddConst(complex x,float coefficient);//���㸴������һ������
	void findComplexDivid(complex x,complex y);//���������������
	float findComplexLength(complex x);//���㸴����ģֵ
	void findComplexMulComplex(complex x,complex y);//���ڼ��������������
	void findComplexAddComplex(complex x,complex y);//���ڼ��������������
	
};

