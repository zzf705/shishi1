#include "ChangeTypeTool.h"

int ChangeTypeTool::stringToInt(string str) {
		int info;
		if(str!="") {
			info = atoi(str.c_str());
		} else{
			info=0;
		}
		return info;
	}

	 //string to double 
	 double ChangeTypeTool::stringToDouble(string str) {
		double info;
		if(str!="") {
			info =  atof(str.c_str());
		} else{
			info=0.0;
		}
		return info;
	 }
	 //string to char 
	 char* ChangeTypeTool::stringToChar(string str) {
		char* p;
		if(str!="") {
			 p = const_cast<char*>(str.c_str());
		} else{
			p=NULL;
		}
		return p;
	 }

	const char* ChangeTypeTool::stringToConstChar(string str) {
		const char *p;
		if(str!="") {
			p = str.c_str();
		}else {
			p=NULL;
		}
		 return p;
	 }

	//int to string
	string ChangeTypeTool::intToString(int i) {
		string info;
		stringstream ss;
		//int n = 123;
		ss<<i;
		info=ss.str();
		ss.clear();
		return info;
	}

	//double to string
	string ChangeTypeTool::doubleToString(double d) {
		string info;
		stringstream ss;
		ss<<d;
		info=ss.str();
		ss.clear();
		return info;
	}

	 //const char to string
	 string ChangeTypeTool::constCharToString(const char *c) {
		string str(c);
		return str;
	 }

	 //string to int vector  ֻ�õ��ֺš�����
	 vector<int> ChangeTypeTool::stringToIntVector(string str,string sep) {
		vector<int> intVector;
		//string d = ";";
		//�������ã�
		vector<string> stringVector = ChangeTypeTool::stringToStringVector(str,sep);
		vector<string>::iterator iter=stringVector.begin( ); 
		for(;iter!=stringVector.end();)
		{
			intVector.push_back(ChangeTypeTool::stringToInt(*iter));
			iter++;
		}
		return intVector;
	 }

	 //string to string vector
	vector<string> ChangeTypeTool::stringToStringVector(string str,string sep) {
		//string sep = ":";
		vector<string> stringVector;
		stringVector = ChangeTypeTool::strSplit(str,sep);
		return stringVector;
	}

	/*
		//strtok ��һ�ε��ô�string  ֮�󴫵�null
		char *p=strtok(ChangeTypeTool::stringToChar(str),d);   //��ʼ���зָ�  ��dΪ�ָ���  
		while(p) {
			stringVector.push_back(p);
			p=strtok(NULL,d);
		}
		return stringVector;
	 }
	 */

	//��һ��stringMap ���һ��map
	//ֻ�õ�ð�š�:��
	map<int,double> ChangeTypeTool::stringToIntMap(string str,string sep) {
		map<int,double> objectMap;
	    //string sep1 = ";";
		vector<string> stringMap=ChangeTypeTool::strSplit(str,sep);
		vector<string>::iterator iter = stringMap.begin();
		//int id =0;
		//double idValue=0;
		for(;iter!=stringMap.end();) {
			int id = ChangeTypeTool::stringToInt(*iter++);
			double idValue = ChangeTypeTool::stringToDouble(*iter);
			objectMap.insert(pair<int,double>(id,idValue));
		}
		return objectMap;
	}

	//ֻ�õ�������
	map<string,double> ChangeTypeTool::stringToStringMap(string str,string sep) {
		map<string,double> objectMap;
		// string sep1 = ";";
		vector<string> stringMap=ChangeTypeTool::strSplit(str,sep);
		vector<string>::iterator iter = stringMap.begin();
		string idFreq = *iter++;
		double idValue = ChangeTypeTool::stringToDouble(*iter);
		objectMap.insert(pair<string,double>(idFreq,idValue));
		return objectMap;
	}


	vector<map<int,double>> ChangeTypeTool::stringToIntMapVector(string str,string sepOut,string sepIn) {
		vector<map<int,double>> finalData;
		vector<string> stringVector = ChangeTypeTool::stringToStringVector(str,sepOut);
		vector<string>::iterator iter = stringVector.begin();
		for(;iter!=stringVector.end();iter++) {
			map<int,double> mapData = ChangeTypeTool::stringToIntMap(*iter,sepIn);
			finalData.push_back(mapData);
		}
		return finalData;
	}

	vector<map<string,double>> ChangeTypeTool::stringToStringMapVector(string str,string sepOut,string sepIn) {
		vector<map<string,double>> finalData;
		vector<string> stringVector = ChangeTypeTool::stringToStringVector(str,sepOut);
		vector<string>::iterator iter = stringVector.begin();
		for(;iter!=stringVector.end();iter++) {
			map<string,double> mapData = ChangeTypeTool::stringToStringMap(*iter,sepIn);
			finalData.push_back(mapData);
		}
		return finalData;
	}

	//��ð��":"�ָ�
	map<double,double> ChangeTypeTool::stringToDoubleMap(string str,string sep) {
		map<double,double> objectMap;
		// string sep1 = ";";
		vector<string> stringMap=ChangeTypeTool::strSplit(str,sep);
		vector<string>::iterator iter = stringMap.begin();
		double id =  ChangeTypeTool::stringToInt(*iter++);
		double idValue = ChangeTypeTool::stringToDouble(*iter);
		objectMap.insert(pair<double,double>(id,idValue));
		return objectMap;
	}
	/*
	//ר�����ڳ�ǿ
	map<double,double> ChangeTypeTool::stringToDoubleMap(string str,string sep) {
		map<double,double> objectMap;
		// string sep1 = ";";
		vector<string> stringMap=ChangeTypeTool::strSplit(str,sep);
		vector<string>::iterator iter = stringMap.begin();
		double id =  ChangeTypeTool::stringToInt(*iter++);
		double idValue = ChangeTypeTool::stringToDouble(*iter);
		objectMap.insert(pair<double,double>(id,idValue));
		return objectMap;
	}
	*/
	//�����ã��ڲ���:
	vector<map<double,double>> ChangeTypeTool::stringToDoubleMapVector(string str,string sepOut,string sepIn) {
		vector<map<double,double>> finalData;
		vector<string> stringVector = ChangeTypeTool::stringToStringVector(str,sepOut);
		vector<string>::iterator iter = stringVector.begin();
		for(;iter!=stringVector.end();iter++) {
			map<double,double> mapData = ChangeTypeTool::stringToDoubleMap(*iter,sepIn);
			finalData.push_back(mapData);
		}
		return finalData;
	}


	/*
	 //��һ��stringMap ���һ��map
	map<int,double> ChangeTypeTool::stringToMap(string str,string sep) {
		 map<int,double> objectMap;
		// string sep1 = ";";
		 vector<string> stringMap=ChangeTypeTool::strSplit(str,sep);
		 vector<string>::iterator iter = stringMap.begin();
		 int id = ChangeTypeTool::stringToInt(*iter++);
		 double idValue = ChangeTypeTool::stringToDouble(*iter);
		 objectMap.insert(pair<int,double>(id,idValue));
		
		 return objectMap;
	 }

	vector<map<int,double>> ChangeTypeTool::stringToVectorMap(string str,string sep) {
		vector<map<int,double>> finalData;
		vector<string> stringVector = ChangeTypeTool::stringToStringVector(str);
		vector<string>::iterator iter = stringVector.begin();
		for(;iter!=stringVector.end();iter++) {
			map<int,double> mapData = ChangeTypeTool::stringToMap(*iter,sep);
			finalData.push_back(mapData);
		}
		return finalData;
	}

	*/

	vector<string> ChangeTypeTool::strSplit(string text,string sep){
		int last_pos=0;
		//string sep = ":";
		int pos=0;
		vector<string> vectorWords;
		if(text!=""&&text!=" ") {
			while(true){
				pos=text.find_first_of(sep,last_pos);
				if(pos==string::npos){
					if(!text.substr(last_pos).empty()) 
						vectorWords.push_back(text.substr(last_pos));
					break;
				}else{
					if(pos-last_pos!=0) {
						vectorWords.push_back(text.substr(last_pos,pos-last_pos));
						last_pos=pos+1;
					} else{
						last_pos=pos+1;
					}
				}
			}
		}
		return vectorWords;
	}