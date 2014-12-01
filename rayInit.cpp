#include "rayInit.h"



void rayInit::rayfinalpointxy(float x0,float y0,float z0,float a,float b,float c,float coveringLength)
{
	float groundx,groundy;//������������ཻ�Ľ�������
	float d; //���潻����Դ���ˮƽ����finalx��finaly�������������յ�����
	if(c>=0)
	{

		finalx=x0+a*coveringLength/(sqrt(a*a+b*b));
		finaly=y0+b*coveringLength/(sqrt(a*a+b*b));
		groundflag=0;
	}
	if(c<0)
	{
		groundx=(-a)*z0/c+x0;//������������ཻ�Ľ�������
		groundy=(-b)*z0/c+y0;
		//
		
		
		d=sqrt((groundx-x0)*(groundx-x0)+(groundy-y0)*(groundy-y0));
		if (d>=coveringLength)//����ֻ��1km����
		{

			finalx=x0+a*coveringLength/(sqrt(a*a+b*b));
			finaly=y0+b*coveringLength/(sqrt(a*a+b*b));
			groundflag=0;
		}
		else
		{
			finalx=groundx;
			finaly=groundy;
			groundflag=1;
			d1=sqrt((groundx-x0)*(groundx-x0)+(groundy-y0)*(groundy-y0)+(finalz-z0)*(finalz-z0));
		}
		
		//else groundflag=0;

	}
}
int rayInit::getgroundflag()//�����Ƿ�������ཻ�ı�־
{
	return groundflag;
}

void rayInit::setsearchgridnumber() //�õ���Ҫ����������ĸ���
{

	for(int i=1;i<=1000;i++)
	{
		if(searchgridx[i-1]!=0&&searchgridy[i-1]!=0)
			num=num+1;
		else break;
	}

}


float rayInit::get_firstx()
{
	return firstx;
}
float rayInit::get_firsty()
{
	return firsty;
}
float rayInit::get_firstz()
{
	return firstz;
}
float rayInit::get_finalx()
{
	return finalx;
}
float rayInit::get_finaly()
{
	return finaly;
}
float rayInit::get_finalz()
{
	return finalz;
}
void rayInit::setfirstgridx(int n)
{
	firstgridx=n;
}
void rayInit::setfirstgridy(int n)
{
	firstgridy=n;
}
void rayInit::setfinalgridx(int n)
{
	finalgridx=n;
}
void rayInit::setfinalgridy(int n)
{
	finalgridy=n;
}
int rayInit::getfirstgridx()
{
	return firstgridx;
}
int rayInit::getfirstgridy()
{
	return firstgridy;
}
int rayInit::getfinalgridx()
{
	return finalgridx;
}
int rayInit::getfinalgridy()
{
	return finalgridy;
}
float rayInit::get_directiona() //������߷���ϵ��a
{
	return directiona;
}
float rayInit::get_directionb() //������߷���ϵ��b
{
	return directionb;
}

float rayInit::get_directionc() //������߷���ϵ��c
{
	return directionc;
}
void rayInit::setallgridx(int *p)  //�ҵ���������������ˮƽ��ż��ϣ�����ֵ���� searchgridx[1000]
{
	for(int i=1;i<=1000;i++)
	{
		searchgridx[i-1]=*p;
		p++;
	}
}
void rayInit::setallgridy(int *p) //�ҵ���������������ֱ��ż��ϣ�����ֵ���� searchgridy[1000]
{ 
	for(int i=1;i<=1000;i++)
	{
		searchgridy[i-1]=*p;
		p++;
	}
}
int* rayInit::getallgridx()  //�������е�����ˮƽ���
{
	return &searchgridx[0];
}
int* rayInit::getallgridy() //�������е�����ֱ���
{
	return &searchgridy[0];
}


rayInit::rayInit( float a,float b,float c,float d,float e,float f)
{
	firstx=a;
	firsty=b;
	firstz=c;    
	directiona=d;
	directionb=e;
	directionc=f;
	num=0;//���߷���ϵ��
	d1=0;
	finalz=0;//��������ཻzֵΪ0
	memset(searchgridx,0,sizeof(searchgridx));
	memset(searchgridy,0,sizeof(searchgridy));
	//searchgridx[1000]={0};
	//searchgridy[1000]={0};
}
int rayInit:: getsearchgridnumber()//������Ҫ����������ĸ���
{
	return num;
}
float rayInit::getd1()//���������������潻��ľ���
{
	return d1;
}

