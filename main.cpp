#pragma once
#include"basestationShooting.h"



void main()
{
	int mapMaxGridX,mapMaxGridY;//��ͼ��ˮƽ����ʹ�ֱ�����С��������Ϊģ����������
	/*mapMaxGridX=275;
	mapMaxGridY=261;*/
	//��������ŵ����ֵ����Сֵ
	
	
	//float interFrequence;//��վ��Ӧ����������Ƶ��
	//interFrequence=900;//��mhzΪ��λ
	//float  rayInterval;//�������߼������ʱ��дģ�麯��ʱ��Ҫ�õ�
	//rayInterval=2;
	//float baseStationPositionx, baseStationPositiony, baseStationPositionz;//��վ��λ�ü��߶�
	//baseStationPositionx=621.5;
	//baseStationPositiony=655.5;
	//baseStationPositionz=25;
	//float coveringRange=1000;//����С�����ǰ뾶
	/////////////////////////////////////////////////////////////////////



	//GridFieldStrenthAddBaseNum���߹��ʼ�¼��һ��������ܶ�Ӧ�����վ�Ľ������ʼ������
	CoInitialize(NULL);
	_ConnectionPtr  sqlSp;
	HRESULT hr=sqlSp.CreateInstance(_uuidof(Connection));
	if(FAILED(hr))
	{
		cout<<"_ConnectionPtr����ָ��ʵ����ʧ�ܣ�����"<<endl;
		return ;
	}
	else 
	{
		try 
		{
			_bstr_t strConnect="Driver={sql server};server=ZHANGZHE-PC;uid=sa;pwd=123456;database=test25;";//�����ݿ�����
			sqlSp->Open(strConnect,"","",adModeUnknown);
		}
			catch(_com_error &e) {
				cout<<e.Description()<<endl;
			}
	}
	_RecordsetPtr m_pRecordset;
	if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
	{
		cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
		return;
	}
	
	try
	{
		m_pRecordset->Open("SELECT * FROM  GridFieldStrenthAddBaseNum",(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF) 
		{
			m_pRecordset->Delete(adAffectCurrent);
			m_pRecordset->Update();
			m_pRecordset->MoveFirst();
		}
	}
	catch (_com_error &e)
	{
		cout << e.Description()<<endl;
	}
	//grid���������ÿ�������Ӧ�ĳ�ǿֵ���㣬ͬʱ�ҵ��������ֵ����Сֵ

	m_pRecordset->Close();
	double GDotX;
	double GDotY;
	double XM=0,YM=0;
	
	try
	{
	m_pRecordset->Open("SELECT * FROM  Grid",(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
	m_pRecordset->MoveFirst();
	while(!m_pRecordset->adoEOF)
	{
		m_pRecordset->PutCollect("GRealSNR",double(0));//�������ֵı�ĵģ������Ժ�Ҫ��
		//��������ŵ����ֵ����Сֵ
		GDotX=double(m_pRecordset->GetCollect("GX"));
			if(GDotX>XM)
			{
				XM=GDotX;
			}
			GDotY=double(m_pRecordset->GetCollect("GY"));
			if(GDotY>YM)
			{
				YM=GDotY;
			}
		m_pRecordset->MoveNext();

		m_pRecordset->Update();
	}
	
	}
	catch (_com_error &e)
	{
		cout << e.Description()<<endl;
	}
	m_pRecordset->Close();
	mapMaxGridX=int((XM+2.5)/5);
	mapMaxGridY=int((YM+2.5)/5);
	//���������Ӧ���۵�ȫ���洢��vector��
	vector<vector<BuildingPoint>> allBPoints;//���н�������۵��б�
	vector<BuildingPoint> oneBPoints;//һ����������۵��б�
	BuildingPoint oneBPoint;//һ���۵�
	int Bid;
	int BidM=0;//�����������
	/////////////////�õ������������////////////////////////////////////
	try {
			
			//m_pRecordset->Open("SELECT * FROM  BuildingPoint",(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
			m_pRecordset->Open("SELECT * FROM  Building",(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
		}
		catch (_com_error &e)
		{
			cout << e.Description()<<endl;
		}
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			Bid=int(m_pRecordset->GetCollect("BId"));
			if(Bid>BidM)
			{
				BidM=Bid;
			}
			m_pRecordset->MoveNext();
		}
		m_pRecordset->Close();
		//�����н�������۵�洢����
		
		for(Bid=1;Bid<=BidM;Bid++)
		{
			string Ext1;
			Ext1.append("SELECT * FROM  BuildingPoint WHERE PBuildingId=");
			stringstream sss;
			sss<<Bid;
			Ext1.append(sss.str());	
			Ext1.append("order by PId");
			if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
	{
		cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
		return;
	}
			try {
			m_pRecordset->Open(Ext1.c_str(),(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);		

			sss.str("");
			sss.clear();
			Ext1.clear();
			while((!m_pRecordset->adoEOF))
			{
				oneBPoint.px=double(m_pRecordset->GetCollect("PX"));
				oneBPoint.py=double(m_pRecordset->GetCollect("PY"));
				oneBPoints.push_back(oneBPoint);				
				m_pRecordset->MoveNext();
			}
			allBPoints.push_back(oneBPoints);			
			oneBPoints.clear();
			
			}
			catch (_com_error &e)
		{
			cout << e.Description()<<endl;
		}

		}
		m_pRecordset->Close();
		//�����н�����ĸ߶ȼ�¼����
		vector<float> allBuildingHeight;
		for(Bid=1;Bid<=BidM;Bid++)
		{
			string Ext1;
			Ext1.append("SELECT * FROM  Building WHERE BId=");
			stringstream sss;
			sss<<Bid;
			Ext1.append(sss.str());	
			if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
	{
		cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
		return;
	}
			try {
			m_pRecordset->Open(Ext1.c_str(),(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);		

			sss.str("");
			sss.clear();
			Ext1.clear();
			while((!m_pRecordset->adoEOF))
			{
				
				allBuildingHeight.push_back(float(m_pRecordset->GetCollect("BHeight")));	
				m_pRecordset->MoveNext();
				
			}
						
			}
			catch (_com_error &e)
		{
			cout << e.Description()<<endl;
		}

		}
		m_pRecordset->Close();
		


		//��С������վ�����ж�ȡ��վ����Ϣ�����л�վ����

	//CoInitialize(NULL);
	//_ConnectionPtr  sqlSp;
	//HRESULT hr=sqlSp.CreateInstance(_uuidof(Connection));
	//if(FAILED(hr))
	//{
	//	cout<<"_ConnectionPtr����ָ��ʵ����ʧ�ܣ�����"<<endl;
	//	return ;
	//}
	//else {
	//	try {
	//		_bstr_t strConnect="Driver={sql server};server=ZHANGZHE-PC;uid=sa;pwd=123456;database=test25;";
	//		//_bstr_t strConnect="Provider=SQLOLEDB;Server=127.0.0.1,1433;Database=PBMS;uid=sa;pwd=pp471006459;";
	//		//_bstr_t strConnect="Provider=SQLOLEDB.1;Password=pp471006459;Persist Security Info=True;User ID=sa;"
	//			//"Initial Catalog=PBMS;Data Source=127.0.0.1,1433";
	//		//����������strConnect��䶼�����ã������Լ�ϲ��ѡ���ð�
	//		//Ҫע���޸��û���uid������pwd�����ݿ���database�������������������Լ�sql server�����ݿ���Ϣ
	//		sqlSp->Open(strConnect,"","",adModeUnknown);
	//	}
	//	catch(_com_error &e) {
	//		cout<<e.Description()<<endl;
	//	}
	//	_RecordsetPtr m_pRecordset; //��¼������ָ�룬����ִ��SQL��䲢��¼��ѯ���
	//	if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
	//	{
	//		cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
	//		return;
	//	}

		try
		{
			m_pRecordset->Open("SELECT * FROM  Area",(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
		}
		catch (_com_error &e)
		{
			cout << e.Description()<<endl;
		}
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			float AHeight;
			AHeight=float(m_pRecordset->GetCollect("AHeight"));
			if(AHeight!=0)
			{
			    float AFreq,AAspectAngle,ADeclineAngle,AX,AY,ALength;
				int AId;
				AFreq=float(m_pRecordset->GetCollect("AFreqType"));
				AAspectAngle=float(m_pRecordset->GetCollect("AAspectAngle"));
				ADeclineAngle=float(m_pRecordset->GetCollect("ADeclineAngle"));
				AX=float(m_pRecordset->GetCollect("AX"));
				AY=float(m_pRecordset->GetCollect("AY"));
				AId=int(m_pRecordset->GetCollect("AId"));
				ALength=float(m_pRecordset->GetCollect("ALength"));//���߳���
				basestationShooting basestationshooting1;
	basestationshooting1.basestationOperate(mapMaxGridX,mapMaxGridY,1,AFreq,AX,AY,AHeight,AAspectAngle,ADeclineAngle,220,110,AId,ALength,allBPoints,allBuildingHeight);
				
			}
			
			m_pRecordset->MoveNext();
		}


	/*basestationShooting basestationshooting1;
	basestationshooting1.basestationOperate(mapMaxGridX,mapMaxGridY,2,900,285,286,25,0,45,360,80,1);
	basestationShooting basestationshooting2;
 	basestationshooting2.basestationOperate(mapMaxGridX,mapMaxGridY,2,900,285,851,25,0,45,360,80,2);
	basestationShooting basestationshooting3;
 	basestationshooting2.basestationOperate(mapMaxGridX,mapMaxGridY,2,900,851,285,25,0,45,360,80,3);
	basestationShooting basestationshooting4;
 	basestationshooting2.basestationOperate(mapMaxGridX,mapMaxGridY,2,900,851,851,25,0,45,360,80,4);*/

	//////////////////////////////////////////////////////////

	
	//��GridFieldStrenthAddBaseNum�����ҵ�ÿ�������Ӧ�����ǿֵ

	int havePowerNumber=0;


	for(int num=0;num<mapMaxGridX*mapMaxGridY;num++)
		{   
			double maxStrength=-9999999;//Ϊ���ҵ�ÿ�������Ӧ�����ǿֵ
			int number=0;
			/*CoInitialize(NULL);
			_ConnectionPtr  sqlSp;
			HRESULT hr=sqlSp.CreateInstance(_uuidof(Connection));
			if(FAILED(hr))
			{
				cout<<"_ConnectionPtr����ָ��ʵ����ʧ�ܣ�����"<<endl;
				return ;
			}
			else 
			{
				try {
					_bstr_t strConnect="Driver={sql server};server=ZHANGZHE-PC,1433;uid=sa;pwd=123456;database=MapData6;";
					sqlSp->Open(strConnect,"","",adModeUnknown);
				}
				catch(_com_error &e) {
					cout<<e.Description()<<endl;
				}
			}
			_RecordsetPtr m_pRecordset;
			*/
			if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
				{
					cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
					return;
				}

			
			string Ext;
			string medm;
			int mBid1,mBid2;
			stringstream ss;
			Ext.append("SELECT * FROM GridFieldStrenthAddBaseNum WHERE GId=");
			ss<<num+1;
			Ext.append(ss.str());			
			try
			{
				m_pRecordset->Open(Ext.c_str(),(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
				Ext.clear();
				ss.str("");
				ss.clear();
				m_pRecordset->MoveFirst();
				while(!m_pRecordset->adoEOF) 
				{
					number++;	
					double gridPower;
					gridPower=double(m_pRecordset->GetCollect("GFieldStrength"));
					if(gridPower>=maxStrength)
						maxStrength=gridPower;
					m_pRecordset->MoveNext();
				}
			}
			catch (_com_error &e)
			{
				cout << e.Description()<<endl;
			}


			if(number==0)
				continue;
			cout<<num<<endl;

			Grid grid2;
			grid2.PutThisGridStrength(num+1,maxStrength);
			havePowerNumber++;
		}

	//ʹ�þ��鹫ʽ���ÿ�������·�����ֵ,��������뵽grid���еĳ�ǿֵ��

	//�Ƚ����֮ǰ���߸��ٵĽ������



	m_pRecordset->Close();
	








}