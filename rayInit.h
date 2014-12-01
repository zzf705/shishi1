#pragma once
#include<iostream>
#include<cmath>
using namespace std;


class rayInit
{
private:
	float firstx,firsty,firstz;    //������ʼ������
	float directiona,directionb,directionc;   //���߷���ϵ��
	float finalx, finaly,finalz;    //����ֹͣʱ�����յ�����
	int num;  //�������������
	float d1;//�����������潻��ľ���,��ʼֵΪ0
	int groundflag;//�ж��Ƿ�������ཻ�ı�־
	int firstgridx,firstgridy;  //������ʼ�����ڵ�����
	int finalgridx,finalgridy;  //�����յ����ڵ�����
	int searchgridx[1000],searchgridy[1000];//���ߴ���㵽�յ㾭������������ˮƽ��Ŵ�ֱ��ż�������




public:
	rayInit( float,float,float,float,float,float);//������ʼ������,����ϵ��,���������������ʼ��
	float get_firstx();  //���������ʼ��x����
	float get_firsty();  //���������ʼ��y����
	float get_firstz();  //���������ʼ��z����
	float get_directiona();//������߷���ϵ��a
	float get_directionb();//������߷���ϵ��b
	float get_directionc();//������߷���ϵ��c

	void rayfinalpointxy( float,float,float,float,float,float,float coveringLength);//�������յ�����,������� ������ʼ�����꣬����ϵ��,�õ��յ����꣬�Ƿ�������ཻ�ı�־����������潻��ľ���d1

	float get_finalx(); //��������յ�x����
	float get_finaly();  //��������յ�y����
	float get_finalz();  //��������յ�z����,��ʼֵΪ0
	void setfirstgridx(int n); //��������ʼ�����ڵ�����ˮƽ��ţ��÷�������һ�����������q,���߶���m,������д�� q.findpointgridx(m.get_firstx())
	void setfirstgridy(int n); //��������ʼ�����ڵ�����ֱ���
	void setfinalgridx(int n);//�������յ����ڵ�����ˮƽ���
	void setfinalgridy(int n);//�������յ����ڵ�����ֱ���
	int getfirstgridx(); //������������ˮƽ���
	int getfirstgridy();//������������ֱ���
	int getfinalgridx();//�����յ������ˮƽ���
	int getfinalgridy();//�����յ������ֱ���
	//�����ߴ���ʼ�㵽�յ����ڵ�����ˮƽ��� �÷�������һ�����������q,���߶���m,֮ǰ�Ѿ�����������������������ģ���ִ��q.findallgrid(m.get_firstx(),m.get_firsty(),m.getfirstgridx(),m.getfirstgridy(),m.getfinalgridx(),m.getfinalgridy(),
	//m.getfinalgridz(),m. get_directiona(),m. get_directionb()),������������񼯺ϣ�Ȼ��ִ�л�����ߵ�ˮƽ��ţ�Ҳ�����������䣬�÷���m. setdallgridx(q.get_allgridx());
	void setallgridx(int *p);  //�ҵ���������������ˮƽ��ż��ϣ�����ֵ���� searchgridx[1000]
	void setallgridy(int *p);  //�ҵ���������������ֱ��ż��ϣ�����ֵ���� searchgridy[1000]
	int* getallgridx();  //�������е�����ˮƽ���
	int* getallgridy();  //�������е�����ֱ���
	void setsearchgridnumber();//�õ���Ҫ����������ĸ���
	int getsearchgridnumber();//������Ҫ����������ĸ���
	int getgroundflag();//�����Ƿ�������ཻ�ı�־
	float getd1();//���������������潻��ľ���



};


