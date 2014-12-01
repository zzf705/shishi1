#pragma once
#include"ChangeTypeTool.h"
#include<iostream>
#include <vector>
#include<algorithm>
#include <sstream>
#include <map>
#define COLOR1 16776960
#define COLOR2 14276889
#define COLOR3 13612347
#define COLOR4 13467442
#define COLOR5 14390128
#define COLOR6 16744192
#define COLOR7 16711680
#define COLOR8 9315107
#define COLOR9 16777215
using namespace std;
#import "C:\\program files\\common files\\system\\ado\\msado15.dll"  no_namespace rename("EOF", "adoEOF")
class Grid {
public:
	int id;
	vector<int> GBId;
	double longitude;
	double latitude;
	double GPX;
	double GPY;
	//vector<int> baseStationId;
	//vector<int> buildingPointId; //����ʹ��vector�����Բ���Ҫָ��vector�Ĵ�С
	int areaId;  //��ǿ���Ǹ�С���ı�� 
	vector<map<string,double>> fieldStrength;  //
	//double fieldRealStength;
	map<int,double> fieldRealStrength;
	//int flag;
	//mmm
public:
	//���캯��
	Grid(){};
	
	Grid(vector<string> param,string sepOut,string sepIn) {
		vector<string>::iterator iter = param.begin();
		//if(*iter!="")  {
			this->setId(ChangeTypeTool::stringToInt(*iter++));
		//} 
		//if(*iter!="") {
			this->setLongtitude(ChangeTypeTool::stringToDouble(*iter++));
		//}
		//if(*iter!="") {
			this->setLatitude(ChangeTypeTool::stringToDouble(*iter++));
		//}
		//if(*iter!="") {
		//	this->setBuildingPointId(ChangeTypeTool::stringToIntVector(*iter++,sepOut));
		//}
		//if(*iter!="") {
			this->setAreaId(ChangeTypeTool::stringToInt(*iter++));
		//}
		//this->setBaseStationId(ChangeTypeTool::stringToIntVector(*iter++));
		//if(*iter!="") {
			this->setFieldStrength(ChangeTypeTool::stringToStringMapVector(*iter++,sepOut,sepIn));
		//}
		//if(*iter!="") {
			this->setFieldRealStrength(ChangeTypeTool::stringToIntMap(*iter,sepIn));
		//}
		//this->setFlag(ChangeTypeTool::stringToInt(*iter++));
		//this->setFieldStrength(ChangeTypeTool::stringToStringVector(ChangeTypeTool::stringToMap(*iter++,d)));
	}
	
	
	//��ö���
	static Grid getObject(vector<string> param,string sepOut,string sepIn);
	//static Grid getObject(vector<string> param);
	static vector<Grid> getObjectSet(vector<vector<string>> param,string sepOut,string sepIn);
	//set����
	void setId(int id) {
		this->id = id;
	}

	void setLongtitude(double longtitude) {
		this->longitude = longtitude;
	}

	void setLatitude(double latitude) {
		this->latitude = latitude;
	}
	/*
	void setBaseStationId(vector<int> baseStation) {
		this->baseStationId = baseStation;
	}
	*/
	/*
	void setBuildingPointId(vector<int> buildingPointId) {
		this->buildingPointId = buildingPointId;
	}
	*/
	void setAreaId(int areaId) {
		this->areaId=areaId;
	}

	void setFieldStrength(vector<map<string,double>> fieldStrength) {
		this->fieldStrength = fieldStrength;
	}

	void setFieldRealStrength(map<int,double>  fieldRealStrength) {
		this->fieldRealStrength = fieldRealStrength;
	}
	/*
	void setFlag(int flag) {
		this->flag = flag;
	}
	*/
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
	/*
	vector<int> getBaseStationId() {
		return this->baseStationId;
	}
	
	vector<int> getBuildingPointId() {
		return this->buildingPointId;
	}
	*/

	int getAreaId() {
		return this->areaId;
	}

	vector<map<string,double>> getFieldStrength() {
		return this->fieldStrength;
	}

	 map<int,double> getFieldRealStrength() {
		return this->fieldRealStrength;
	}
	/*
	int getFlag() {
		return this->flag;
	}
	*/
		//************************************
		/**
		* @brief	ʹ��ʱ�ṩ����ID�������ݿ�����ȡ�����й���Grid����Ϣ
		* @fullName	Grid::GetThisGirdRecord
		* @param	GId
		* @return	void
		* @author	����
		* @date		2014/04/22
		* @warning  ��ע��˴���������
		*/
		
		//************************************
		void GetThisGirdRecord(int GId);
	//************************************
	/**
	* @brief	ʹ��ʱ�ṩ����ĺ���XY���꣬�����ݿ�����ȡ�����й���Grid����Ϣ
	* @fullName	Grid::GetThisGirdRecord
	* @param	GX
	* @param	GY
	* @return	void
	* @author	����
	* @date		2014/04/22
	* @warning	�˴�Ϊ�����Ĳ���˵��
	*/
	
	//************************************
	void GetThisGirdRecord(double GX, double GY);
	void PutThisGridStrength(int GId, double GStrength);//��ÿ������ǿֵ�����ֵ�ŵ�grid����
	void addThisGridStrengthToNew(int GId, double GStrength,int AId);//����ǿ����ŵ�GridFieldStrenthAddBaseNum����
};
