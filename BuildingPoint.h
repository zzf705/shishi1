#pragma once
#include "ChangeTypeTool.h"
#include <vector>
#include<algorithm>
#include <sstream>
#include <map>
using namespace std;

class BuildingPoint {
public:
	int id;
	double longitude;
	double latitude;
	double height;
	//�������ڽڵ㿼�ǵ��˶�������ﹲ������   
	//��������㣬vector�Ĵ�СΪ1
	/*
	vector<int> leftPointId;
	vector<int> leftPointMaterialId;
	vector<int> rightPointId;
	vector<int> rightPointMaterialId;
	*/
	//δ�������������
	int gridId;
	//�������ڽڵ㿼�ǵ��˶�������ﹲ������   
	//��������㣬vector�Ĵ�СΪ1
	int buildingId;
	double px;
	double py;
public:
	//���캯��
	BuildingPoint(){};
	BuildingPoint(vector<string> param,string sepOut) {
		vector<string>::iterator iter = param.begin();
		this->setId(ChangeTypeTool::stringToInt(*iter++));
		this->setLongtitude(ChangeTypeTool::stringToDouble(*iter++));
		this->setLatitude(ChangeTypeTool::stringToDouble(*iter++));
		this->setHeight(ChangeTypeTool::stringToDouble(*iter++));
		/*
		this->setLeftPointId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		this->setLeftPointMaterialId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		this->setRightPointId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		this->setRightPointMaterialId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		*/
		this->setGridId(ChangeTypeTool::stringToInt(*iter++));
		this->setPx(ChangeTypeTool::stringToDouble(*iter++));
		this->setPy(ChangeTypeTool::stringToDouble(*iter));
	}

	//�õ�����
	static BuildingPoint  getObject(vector<string> param,string sepOut);
	static vector<BuildingPoint> getObjectSet(vector<vector<string>> param,string sepOut);
	//set����
	void setId(int id) {
		this->id = id;
	}

	void setLongtitude(double longitude) {
		this->longitude = longitude;
	}

	void setLatitude(double latitude) {
		this->latitude = latitude;
	}

	void setHeight(double height) {
		this->height = height;
	}
	/*
	void setLeftPointId(vector<int> leftPointId) {
		this->leftPointId = leftPointId;
	}

	void setLeftPointMaterialId(vector<int> leftPointMaterialId) {
		this->leftPointMaterialId = leftPointMaterialId;
	}
	void setRightPointId(vector<int> rightPointId) {
		this->rightPointId = rightPointId;
	}

	void setRightPointMaterialId(vector<int> rightPointMaterialId) {
		this->rightPointMaterialId = rightPointMaterialId;
	}
	*/
	void setGridId(int gridId) {
		this->gridId = gridId;
	}

	void setBuildingId(int buildingId) {
		this->buildingId = buildingId;
	}

	void setPx(double px) {
		this->px=px;
	}

	void setPy(double py) {
		this->py=py;
	}
	//get����
	int getId() {
		return this->id;
	}

	double getLongtitude() {
		return this->longitude;
	}

	double getLatitude() {
		return this->latitude;
	}

	double getHeight() {
		return this->height;
	}
	/*
	vector<int> getLeftPointId() {
		return this->leftPointId;
	}

	vector<int> getLeftPointMaterialId() {
		return this->leftPointMaterialId;
	}

	vector<int> getRightPointId() {
		return this->rightPointId;
	}

	vector<int> getRightPointMaterialId() {
		return this->rightPointMaterialId;
	}
	*/
	int getGridId() {
		return this->gridId;
	}
	//�������ڽڵ㿼�ǵ��˶�������ﹲ������   
	//��������㣬vector�Ĵ�СΪ1
	int getBuildingId() {
		return this->buildingId;
	}

	double getPx() {
		return this->px;
	}

	double getPy() {
		return this->py;
	}
};

