
#pragma once
#include <iostream>
#include<vector>
#include <windows.h>
#include <math.h>
#include "BuildingPoint.h"
#include "line.h"
using namespace std;

//ȫ�ֱ�����ò�Ҫ���壬���࣬���Զ���һ������
/*struct TwoDimPoint{
	float x;
	float y;
};
 struct line
{
	TwoDimPoint point1;
	TwoDimPoint point2;
};
 vector<TwoDimPoint> polyPoint;

 */

class FirstReflection
{
	public:
		vector<TwoDimPoint> polyPoint;
		float crossX;
		float crossY;
		float crossZ;
		TwoDimPoint	refPolyPoint[2];//���������ƽ���Ӧ���ߵ������˵�
		int buildingCrossFlag;
		int roofFlag;
		void buildingCross(float shootingStartX,float shootingStartY,float shootingStartZ,float shootingDirectionX,float shootingDirectionY,float shootingDirectionZ,vector<BuildingPoint>BPoint,float buildingHeight);
		
	private:
		TwoDimPoint getCross(line line1, line line2);
		//int vertex_triangle(TwoDimPoint pa, TwoDimPoint pb, TwoDimPoint pc, TwoDimPoint vertex0);	
		//int vertex_polygon(TwoDimPoint vertex0);                               //�Ѷ���ηֽ�ɶ��������		
		int vertexInside(TwoDimPoint vertex);//�жϵ��Ƿ��ڶ������
};

