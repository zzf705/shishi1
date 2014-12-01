#pragma once
#include"rayInit.h"
#include"findGrid.h"
#include"Grid.h"
#include"Building.h"
#include "firstReflectionNew.h"
#include"complex.h"
#include<cmath>
#include"BuildingPoint.h"
#include<iostream>
using namespace std;

/*struct TwoDimPointZhang
{
	double x;
	double y;
};
*/

class  rayManage
{
public:
	
	float finalCrossPointx, finalCrossPointy, finalCrossPointz; //�뽨������ģ���õ������յĽ���
	int finalCrossFlag;//�ж������Ƿ��н��㣬1��ʾ�У�0��ʾ��
	int finalCrossPosition;//���յĽ����־λ��0˵�������ڽ������ϣ�1˵�����ڵ���
	int finalCrossBuildingname; //�뽨������ģ���õ������յĽ������ڵĲ���,0��ʾ���棬��Ϊ0��Ϊ��ŵĻ���ʾ�������ţ����������齨�������
	int finalCrossBuildingPosition;//0��ʾ�����ڲ��棬1��ʾ�����ڶ���
	int stop;//��־λ���ж��Ƿ�ֹͣ����
	float finalRayLength;//������õ����߳���
	int gridm[1000],gridn[1000];//�����޽����������ڵ�ͼ��Χ������������
	int gridNumberTrue;//ʵ���������Ŀ�����ǵ�ʵ�ʵ�ͼ�ķ�Χ�����������޵�
	int gridTruem[1000], gridTruen[1000];//�����н����������ڵ�ͼ��Χ������������
	int gridNumberStopCross;//�����н�������,�������ֹͣ��¼��ʵ���������Ŀ�����ǵ�ʵ�ʵ�ͼ�ķ�Χ�����������޵�
	


	struct TwoDimPointZhang
	{
		double x;
		double y;
	};
	TwoDimPointZhang twoPoint[2];//����������ڽ������϶�Ӧ�ıߵ������㣬Ϊ����������,ע�����������ķ��䷽��ϵ��ʱҪtwoPoint[0]��twoPoint[1]��������
	float groundRefDirectionA,groundRefDirectionB,groundRefDirectionC;//����ķ��䷽��
	float groundRefAngleCos;//���������ǵ�����ֵ
	//float groundRefCofficient;//����ķ���ϵ��
	float buildingRefDirectionA,buildingRefDirectionB,buildingRefDirectionC;//������ķ��䷽��
	float buildingRefAngleCos;//����������ǵ�����ֵ
	//float buildingRefCofficient;//������ķ���ϵ��
public:
	void findFinalCrossPoint(float startPointx,float startPointy,float startPointz,float startDirectiona,float startDirectionb,float startDirectionc,int maxGridx,int maxGridy,float coveringDistance,vector<vector<BuildingPoint>> BY,vector<float> HY);//������Ľ��㣬�õ�һЩ����,����������������ָ���ǵ�ͼ��ˮƽ�����С�ʹ�ֱ�����С
	void findGroundRefDirection( float shootingStartX,float shootingStartY,float shootingStartZ,float shootingDirectionA,float shootingDirectionB,float shootingDirectionC);//�����ķ��䷽��ϵ�����������Ѿ��������ǵ�����ֵ
	float findGroundRefCofficient(float cosAngle,float frequence);//�����ķ���ϵ����ģֵ������ķ���ϵ����ʱ�ͽ�����Ĳ�����һ���ģ����Ҫ���ݲ������е���
	complex findGroundComplexCofficient(float cosAngle,float frequence);//�����ķ���ϵ��,�Ǹ�������������λ��


	void findBuildingRefDirection( float shootingStartX,float shootingStartY,float shootingStartZ,float shootingFinalX,float shootingFinalY,float shootingFinalZ,float startDirectionA,float startDirectionB,float startDirectionC,TwoDimPointZhang refPolyPoint0,TwoDimPointZhang refPolyPoint1);//������ķ��䷽��ϵ�����������Ѿ��������ǵ�����ֵ
	float findBuildingRefCofficient(float cosAngle,float frequence);//������ķ���ϵ����ģֵ
	complex findBuildingComplexCofficient(float cosAngle,float frequence);//������ķ���ϵ��,�Ǹ�������������λ��
	int findPathStop( float pathDistance,float antennaGain,float frequence ); //��һ�θ��ݾ����ж����ߵ������Ƿ񽵵�ĳһ��ֵ��0��ʾ��ֹͣ��1��ʾֹͣ
	int findPathRefStop( float pathDistance,float antennaGain,float reflectCofficient,float frequence); //���ݾ���ͷ���ϵ���ж����ߵ������Ƿ񽵵�ĳһ��ֵ��0��ʾ��ֹͣ��1��ʾֹͣ
	float findPointToLineDistance(float shootingStartx,float shootingStarty,float shootingStartz,float shootingDirectina,float shootingDirectinb,float shootingDirectinc,float pointx,float pointy,float pointz);//���������ĵ���1.5m��ֱ�ߵľ��룬�������ߵ����ͷ��򣬺��������ĵ������
	float findGridCenterxy(int gridNumber);//���������ţ�������ĵ�����꣬ˮƽ�ʹ�ֱ��һ����
	float findShootingLineLength(float shootingStartx,float shootingStarty,float shootingStartz,float shootingDirectina,float shootingDirectinb,float shootingDirectinc,float pointx,float pointy,float pointz);//��㵽ֱ�ߵľ������Ҫ�����ߵĳ���






};
