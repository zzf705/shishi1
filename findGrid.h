#pragma once
#include<iostream>
class findGrid
{
private:
	int m[1000],n[1000]; //�����߷�������ˮƽ��ţ���ֱ���
	int x[802],y[802];   //����λ��
	float gridx0,gridy0; //�����ŵĲο�����xy,
public:
	findGrid();              //�������е�xy������г�ʼ��
	int findfirstpointgridx(float x0,float a);//��������ʼ�����ڵ������ˮƽ��ţ������������ʼ���x���꣬ˮƽ����ϵ����������ʼ�����������Ķ����ϣ����ϻ�������
	int findfirstpointgridy(float y0,float b);//��������ʼ�����ڵ�����Ĵ�ֱ��ţ������������ʼ���y���꣬��ֱ����ϵ��
	int findpointgridx( float x0,float a); //��һ���յ����ڵ�ˮƽ�����ţ������ڶ˵���������������Ӧ�õ���1�Σ��յ�x����
	int findpointgridy(float y0,float b); //��һ���յ����ڵĴ�ֱ�����ţ������ڶ˵�����������������Ӧ�õ���1�Σ��յ�y����
	void findallgrid(float x0, float y0, int i, int j,int h, int k,float a, float b); // ��������߷�������ˮƽ��ţ���ֱ�����������ֱ�����������xyֵ����ʼ�����ţ���ֹ�����ţ����ߵ�б��
	int* get_allgridx();   //���ذ����߷�������ˮƽ���������׸�Ԫ�ص�ַ
	int* get_allgridy();   //���ذ����߷�������ֱ���

};

