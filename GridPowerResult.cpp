#include "GridPowerResult.h"




void GridPowerResult:: findGridFinalTotalPower(float frequence)//���ÿ������Ĺ��ʣ���vector�еĹ�����ӣ�Ƶ����mhzΪ��λ
{
	complex totalReiceiveElecFiledStrength={0,0};
	complexCalculate complexcalculate4;
	int s;
	s=gridFinalPower.size();
	if(s>0)
	{	
	for( int i=1;i<=s;i++)//��������ж������ߵĵ糡ǿ�ȵĺͣ�������λ
	{
		 complexcalculate4.findComplexAddComplex(totalReiceiveElecFiledStrength,gridFinalPower[i-1]);
		 totalReiceiveElecFiledStrength=complexcalculate4.consequence;
			
	}	
	float waveLength;
	waveLength=300/frequence;
	//Ҫ����յ�Ĺ��ʣ��öԳ�ǿ����ģƽ��
	gridFinalTotalPower=complexcalculate4.findComplexLength(totalReiceiveElecFiledStrength);//����糡�͵�ģֵ
	gridFinalTotalPower=gridFinalTotalPower*gridFinalTotalPower;//���г�ǿģƽ��
	gridFinalTotalPower=gridFinalTotalPower*waveLength*waveLength/(480*3.14*3.14);
	gridPowerLoss=10*log10(39.8/gridFinalTotalPower);
	

	}
}
