#include "complex.h"


void complexCalculate::findComplexRoot(complex x)//���㸴���Ŀ�����
{
	float length;
	float angle;
	float ratio;
	length=sqrt((x.real)*(x.real)+(x.img)*(x.img));
	ratio=x.img/x.real;
	angle=atan(ratio);
	length=sqrt(length);
	angle=angle/2;
	consequence.real=length*cos(angle);
	consequence.img=length*sin(angle);
}
void complexCalculate::findComplexMulConst(complex x,float coefficient)//���㸴������һ������
{
	consequence.real=x.real*coefficient;
	consequence.img=x.img*coefficient;

}
void complexCalculate::findComplexAddConst(complex x,float coefficient)//���㸴������һ������
{
	consequence.real=x.real+coefficient;
	consequence.img=x.img;
}
void complexCalculate::findComplexDivid(complex x,complex y)//���������������
{
	consequence.real=(x.real*y.real+x.img*y.img)/(y.real*y.real+y.img*y.img);
	consequence.img=(x.img*y.real-x.real*y.img)/(y.real*y.real+y.img*y.img);
}
float complexCalculate::findComplexLength(complex x)//���㸴���Ŀ�����
{
	float length;
	length=sqrt((x.real)*(x.real)+(x.img)*(x.img));
	return length;
}
void complexCalculate::findComplexMulComplex(complex x,complex y)//���ڼ��������������
{
	consequence.real=x.real*y.real-x.img*y.img;
	consequence.img=x.img*y.real+x.real*y.img;

}
void complexCalculate::findComplexAddComplex(complex x,complex y)//���ڼ��������������
{
	consequence.real=x.real+y.real;
	consequence.img=x.img+y.img;

}