#pragma once
#include "BuildingPoint.h"
#include "ChangeTypeTool.h"
#include <vector>
#include<iostream>
using namespace std;
#import "C:\\program files\\common files\\system\\ado\\msado15.dll"  no_namespace rename("EOF", "adoEOF")
class Building{
public:
	int id;
	vector<int> areaId;
	vector<BuildingPoint> BPoint;
	//vector<int> gridId;
	vector<int> pointId;
	vector<map<double,double>> param;
	float buildingHeight;

public:
	//���캯��
	Building(){};
	Building(vector<string> param,string sepOut,string sepIn) {
		vector<string>::iterator iter = param.begin();
		this->setId(ChangeTypeTool::stringToInt(*iter++));
		this->setAreaId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		//this->setGridId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		this->setPointId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		this->setParam(ChangeTypeTool::stringToDoubleMapVector(*iter,sepOut,sepIn));
		//ChangeTypeTool::stringToVectorMap(*iter++,";");
	}

	//��������
	static Building getObject(vector<string> param,string sepOut,string sepIn);
	static vector<Building> Building::getObjectSet(vector<vector<string>> param,string sepOut,string sepIn);


	//set����
	void setId(int id) {
		this->id =id;
	}
	
	void setAreaId(vector<int> areaId) {
		this->areaId=areaId;
	}
	/*
	void setGridId(vector<int> gridId) {
		this->gridId=gridId;
	}
	*/
	void setPointId(vector<int> pointId) {
		this->pointId = pointId;
	}
	
	void setParam(vector<map<double,double>> param) {
		this->param = param;
	}
	/*  ����set����
	*******
	*/
	
	//get����

	int getId() {
		return id;
	}
	
	vector<int> getAreaId() {
		this->areaId;
	}
	/*
	vector<int> getGridId() {
		this->gridId;
	}
	*/
	vector<int> getPointId() {
		this->pointId;
	}
	
	vector<map<double,double>> getParam() {
		this->param;
	}
	//��������
	void GetThisBuildingRecord(int BId);
};
