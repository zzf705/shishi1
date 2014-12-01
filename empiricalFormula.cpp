
#include "empiricalFormula.h"

float empiricalFormula:: cost231Formula(float frequence,float baseHeight,float buildingHeight,float buldingSpace,float streetWidth,float mobileHeight,float distance,
	float angleStreet,int k)//����cost231����ģ�͵õ�·�����
{   
	int environment=0;//��Kf�����ֳ���,0�����еȳ��л��߽�����������������
	float loss,lossFree,lossRts,lossMsd;
	float lossOri,lossBsh;		
			//��lossRts
		if(angleStreet>=0&&angleStreet<35)
			lossOri=-10+0.354*angleStreet;
		else if(angleStreet>=35&&angleStreet<55)
			lossOri=2.5+0.075*(angleStreet-35);
		else if(angleStreet>=55&&angleStreet<=93)
			lossOri=4.0-0.114*(angleStreet-55);

		if(buildingHeight>mobileHeight)
			lossRts=-16.9-10*log10(streetWidth)+10*log10(frequence)+20*log10(buildingHeight-mobileHeight)+lossOri;
		if(lossRts<0)   
			lossRts=0;

		//��lossMsd
		float Ka,Kd,Kf;


		if(baseHeight>buildingHeight)
		{
			lossBsh=-18*log10(1+baseHeight-buildingHeight);
			Ka=54;
			Kd=18;
		} 
		else if(baseHeight<=buildingHeight&&distance>=0.5)
		{
			lossBsh=0;
			Ka=54-0.8*(baseHeight-buildingHeight);
			Kd=18-15*(baseHeight-buildingHeight)/buildingHeight;
		}
		else if(baseHeight<=buildingHeight&&distance<0.5)
		{
			lossBsh=0;
			Ka=54-0.8*(baseHeight-buildingHeight)*distance/0.5;
			Kd=18-15*(baseHeight-buildingHeight)/buildingHeight;
		}


		if(environment=0)
			Kf=-4+0.7*(frequence/925-1);
		else
			Kf=-4+1.5*(frequence/925-1);

		lossMsd=lossBsh+Ka+Kd*log10(distance)+Kf*log10(frequence)-9*log10(buldingSpace);
		if(lossMsd<0)
			lossMsd=0;

		lossFree=20*log10(frequence)+20*log10(distance)+32.44;//�����������濼�ǳɵ�λ1��
		loss=lossFree+lossRts+lossMsd;
		return loss;
	

}