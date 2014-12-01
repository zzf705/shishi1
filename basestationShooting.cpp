#include "basestationShooting.h"


void basestationShooting:: basestationOperate(int maxGridx,int maxGridy,float shootingInterval,float baseFrequence,float basePositionx,
		 float basePositiony,float basePositionz,float fangWeiJiao,float xiaQingJiao,float shuipingRange,float shuizhiRange,int baseStationNumber,float kuiLength,vector<vector<BuildingPoint>> BX,vector<float> HX)
	 //����ˮƽ����ţ���ֱ����ţ����߼������վƵ�ʣ���վλ�ã���λ�ǣ�����ǣ�ˮƽ���䷶Χ����ֱ���䷶Χ
{

	int mapMaxGridX,mapMaxGridY;//��ͼ��ˮƽ����ʹ�ֱ�����С��������Ϊģ����������
	mapMaxGridX=maxGridx;
	mapMaxGridY=maxGridy;


	float  rayInterval;//�������߼������ʱ��дģ�麯��ʱ��Ҫ�õ�
	rayInterval=shootingInterval;
	float interFrequence;//��վ��Ӧ����������Ƶ��
	interFrequence=baseFrequence;//��mhzΪ��λ
	float baseStationPositionx, baseStationPositiony, baseStationPositionz;//��վ��λ�ü��߶�
	baseStationPositionx=basePositionx;
	baseStationPositiony=basePositiony;
	baseStationPositionz=basePositionz;
	float coveringRange=1000;//����С�����ǰ뾶
	///////////////////////////////////////////////////////////////////////
	

	//ÿ��ִ�л�վ��������GridFieldStrenth�����㣬��Ϊ�����Ľ��ֻ����һ����վ
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
		m_pRecordset->Open("SELECT * FROM  GridFieldStrenth",(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
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
	



	//////////////////////////////////////////////////////////////

	ShootingRay shooting1;
	/*shooting1.shootingGainAllDirection(fangWeiJiao,xiaQingJiao,shuipingRange,shuizhiRange,rayInterval,rayInterval);*/
	//int rayNumber=shooting1.shootingNumber;
	for(int num=0;num<1000;num++)
	{   
		cout<<num<< "        "<<baseStationNumber<<endl;
		int number;
		number=6484;//��Ҫ��д����
		shooting1.GetRecord(number+1);
		
		float sita,fai;

		rayPath shooting;		
		shooting.firstPointx=baseStationPositionx;
		shooting.firstPointy=baseStationPositiony;
		shooting.firstPointz=baseStationPositionz;
	    shooting.firstDirectiona=shooting1.Rx;
		shooting.firstDirectionb=shooting1.Ry;
		shooting.firstDirectionc=shooting1.Rz;		
		shooting.rayGain=shooting1.Rgain;

		shooting.crossPointx.push_back(shooting.firstPointx);
		shooting.crossPointy.push_back(shooting.firstPointy);
		shooting.crossPointz.push_back(shooting.firstPointz);
		shooting.reflecttDirectiona.push_back(shooting.firstDirectiona);
		shooting.reflecttDirectionb.push_back(shooting.firstDirectionb);
		shooting.reflecttDirectionc.push_back(shooting.firstDirectionc);


		rayManage raymanage1;
		raymanage1.findFinalCrossPoint(shooting.firstPointx,shooting.firstPointy,shooting.firstPointz,shooting.firstDirectiona,shooting.firstDirectionb,shooting.firstDirectionc,mapMaxGridX,mapMaxGridY,coveringRange,BX,HX);
	if(raymanage1.finalCrossFlag==0)
	{
		shooting.searchGridNumberTrue.push_back(raymanage1.gridNumberTrue);
		for(int i=1;i<=raymanage1.gridNumberTrue;i++)
		{ 
			shooting.searchGridTrueX.push_back(raymanage1.gridm[i-1]);
			shooting.searchGridTrueY.push_back(raymanage1.gridn[i-1]);
		}
	}
	if(raymanage1.finalCrossFlag==1)
	{
		shooting.searchGridNumberTrue.push_back(raymanage1.gridNumberStopCross);
		for(int i=1;i<=raymanage1.gridNumberStopCross;i++)
		{ 
			shooting.searchGridTrueX.push_back(raymanage1.gridTruem[i-1]);
			shooting.searchGridTrueY.push_back(raymanage1.gridTruen[i-1]);
		}

	}

	if(raymanage1.finalCrossFlag==0)//�뽨�����޽���
			continue;
		if(raymanage1.finalCrossFlag==1&&raymanage1.finalCrossPosition==0&&raymanage1.finalCrossBuildingPosition==1)//���ڽ�����Ķ���
			
			{
				gridPower  gridPower5;
				gridPower5.gridRayLook(shooting,rayInterval,interFrequence,num, kuiLength);
				continue;
		}
		if(raymanage1.findPathStop(raymanage1.finalRayLength,shooting.rayGain,interFrequence)==1)//·����ĳ���һ��ֵ
			continue;
		//������·���д�ŷ�����λ�úͱ��η���ĳ���
		shooting.crossPointx.push_back(raymanage1.finalCrossPointx);
		shooting.crossPointy.push_back(raymanage1.finalCrossPointy);
		shooting.crossPointz.push_back(raymanage1.finalCrossPointz);
		shooting.positioniState.push_back(raymanage1.finalCrossBuildingname);
		shooting.rayLength.push_back(raymanage1.finalRayLength);
		//���䷽��ͷ���ϵ��
		if(raymanage1.finalCrossFlag==1&&raymanage1.finalCrossPosition==1)//���ڵ���
		{
			raymanage1.findGroundRefDirection(shooting.firstPointx,shooting.firstPointy,shooting.firstPointz,shooting.firstDirectiona,shooting.firstDirectionb,shooting.firstDirectionc);
			float refCoefficientLength;//����ϵ����ģֵ
			refCoefficientLength=raymanage1.findGroundRefCofficient(raymanage1.groundRefAngleCos,interFrequence);
			complex refCoefficient;//���ķ���ϵ��
			refCoefficient=raymanage1.findGroundComplexCofficient(raymanage1.groundRefAngleCos,interFrequence);
			shooting.reflecttDirectiona.push_back(raymanage1.groundRefDirectionA);
			shooting.reflecttDirectionb.push_back(raymanage1.groundRefDirectionB);
			shooting.reflecttDirectionc.push_back(raymanage1.groundRefDirectionC);
			shooting.reflecttCoefficient.push_back(refCoefficientLength);//���뷴��ϵ����ģֵ
			shooting.reflectComplexCoefficient.push_back(refCoefficient);//���븴�ķ���ϵ��
			//gridPower gridpower1;
			//gridpower1.findGroundGridPowerFirst(raymanage1.finalCrossPointx,raymanage1.finalCrossPointy,shooting[num].firstPointx,shooting[num].firstPointy,shooting[num].firstPointz,shooting[num].firstDirectiona,shooting[num].firstDirectionb,shooting[num].firstDirectionc,raymanage1.finalRayLength,shooting[num].rayGain,gridNumber);

		}
		
		if(raymanage1.finalCrossFlag==1&&raymanage1.finalCrossPosition==0)//���ڽ��������
		{
			//������ķ��䷽������ǵ�����ֵ��֪
			raymanage1.findBuildingRefDirection(shooting.firstPointx,shooting.firstPointy,shooting.firstPointz,raymanage1.finalCrossPointx,raymanage1.finalCrossPointy,raymanage1.finalCrossPointz,shooting.firstDirectiona,shooting.firstDirectionb,shooting.firstDirectionc,raymanage1.twoPoint[0],raymanage1.twoPoint[1]);
			float refCoefficientLength;//����ϵ����ģֵ
			refCoefficientLength=raymanage1.findBuildingRefCofficient(raymanage1.buildingRefAngleCos,interFrequence);//�����ﷴ��ϵ����ģֵ
			complex refCoefficient;//���ķ���ϵ��
			refCoefficient=raymanage1.findBuildingComplexCofficient(raymanage1.buildingRefAngleCos,interFrequence);//�����︴�ķ���ϵ��
			shooting.reflecttDirectiona.push_back(raymanage1.buildingRefDirectionA);
			shooting.reflecttDirectionb.push_back(raymanage1.buildingRefDirectionB);
			shooting.reflecttDirectionc.push_back(raymanage1.buildingRefDirectionC);
			shooting.reflecttCoefficient.push_back(refCoefficientLength);//���뷴��ϵ����ģֵ
			shooting.reflectComplexCoefficient.push_back(refCoefficient);//���븴�ķ���ϵ��
		}
			//����ÿ�����ߵĵ�����������������
		int maxRefNum=10;//���ķ������,��ʱ�Ĺ������Ȳ��Ե���
		for(int refNum=1;refNum<=maxRefNum;refNum++)
		{
			rayManage raymanage2;
			//�����
			
			raymanage2.findFinalCrossPoint(shooting.crossPointx[refNum],shooting.crossPointy[refNum],shooting.crossPointz[refNum],shooting.reflecttDirectiona[refNum],shooting.reflecttDirectionb[refNum],shooting.reflecttDirectionc[refNum],mapMaxGridX,mapMaxGridY,coveringRange,BX,HX);
			if(raymanage2.finalCrossFlag==0)
	{
		shooting.searchGridNumberTrue.push_back(raymanage2.gridNumberTrue);
		for(int i=1;i<=raymanage2.gridNumberTrue;i++)
		{ 
			shooting.searchGridTrueX.push_back(raymanage2.gridm[i-1]);
			shooting.searchGridTrueY.push_back(raymanage2.gridn[i-1]);
		}
	}
	if(raymanage2.finalCrossFlag==1)
	{
		shooting.searchGridNumberTrue.push_back(raymanage2.gridNumberStopCross);
		for(int i=1;i<=raymanage2.gridNumberStopCross;i++)
		{ 
			shooting.searchGridTrueX.push_back(raymanage2.gridTruem[i-1]);
			shooting.searchGridTrueY.push_back(raymanage2.gridTruen[i-1]);
			
		}

	}

			//�ж�����ֹͣ����
			if(raymanage2.finalCrossFlag==0)//�뽨�����޽���
				break;
			if(raymanage2.finalCrossFlag==1&&raymanage2.finalCrossPosition==0&&raymanage2.finalCrossBuildingPosition==1)//���ڽ�����Ķ���
				break;
			//����˴η���·��
			shooting.rayLength.push_back(raymanage2.finalRayLength);
			//�ж�·������Ƿ񳬹�һ��ֵ
			float totalDistance=0;//��������ܵ�·��
			int totalNumber=0;
			totalNumber=shooting.rayLength.size();
			for(int i=1;i<=totalNumber;i++)
			
				{
					totalDistance=totalDistance+shooting.rayLength[i-1];
			}
			float totalRefCoefficient=1;//������߷���ϵ���ĳ˻�
			int totalRefNumber;
			totalRefNumber=shooting.reflecttCoefficient.size();
			for(int i=1;i<=totalRefNumber;i++)
				{
					 totalRefCoefficient= totalRefCoefficient*shooting.reflecttCoefficient[i-1];

			}
			if(raymanage2.findPathRefStop(totalDistance,shooting.rayGain,totalRefCoefficient,interFrequence)==1)
				
				{
					break;
			}
			//������·���д�ŷ�����λ��
			shooting.crossPointx.push_back(raymanage2.finalCrossPointx);
			shooting.crossPointy.push_back(raymanage2.finalCrossPointy);
			shooting.crossPointz.push_back(raymanage2.finalCrossPointz);
			shooting.positioniState.push_back(raymanage2.finalCrossBuildingname);
			//���䷽��ͷ���ϵ��
			if(raymanage2.finalCrossFlag==1&&raymanage2.finalCrossPosition==1)//���ڵ���
			{
				//������䷽�򣬲��Ѿ��������ǵ�����ֵ
				raymanage2.findGroundRefDirection(shooting.crossPointx[refNum],shooting.crossPointy[refNum],shooting.crossPointz[refNum],shooting.reflecttDirectiona[refNum],shooting.reflecttDirectionb[refNum],shooting.reflecttDirectionc[refNum]);
				//��˴ε���ķ���ϵ������Ҫ֪�������
				float refCoefficientLength;//����ϵ����ģֵ
				refCoefficientLength=raymanage2.findGroundRefCofficient(raymanage2.groundRefAngleCos,interFrequence);
				complex refCoefficient;//���ķ���ϵ��
				refCoefficient=raymanage2.findGroundComplexCofficient(raymanage2.groundRefAngleCos,interFrequence);
				shooting.reflecttDirectiona.push_back(raymanage2.groundRefDirectionA);
				shooting.reflecttDirectionb.push_back(raymanage2.groundRefDirectionB);
				shooting.reflecttDirectionc.push_back(raymanage2.groundRefDirectionC);
				shooting.reflecttCoefficient.push_back(refCoefficientLength);//���뷴��ϵ����ģֵ
				shooting.reflectComplexCoefficient.push_back(refCoefficient);//���븴�ķ���ϵ��


				//gridPower gridpower1;
				//gridpower1.findGroundGridPowerSecond(raymanage2.finalCrossPointx,raymanage2.finalCrossPointy,shooting[num].crossPointx[refNum-1],shooting[num].crossPointy[refNum-1],shooting[num].crossPointz[refNum-1],
				//	shooting[num].reflecttDirectiona[refNum-1],shooting[num].reflecttDirectionb[refNum-1],shooting[num].reflecttDirectionc[refNum-1],totalDistance,shooting[num].rayGain,totalRefCoefficient,gridNumber);

			}
			if(raymanage2.finalCrossFlag==1&&raymanage2.finalCrossPosition==0)//���ڽ��������
			{
				//������ķ��䷽������ǵ�����ֵ��֪
				raymanage2.findBuildingRefDirection(shooting.crossPointx[refNum],shooting.crossPointy[refNum],shooting.crossPointz[refNum],raymanage2.finalCrossPointx,raymanage2.finalCrossPointy,raymanage2.finalCrossPointz,shooting.reflecttDirectiona[refNum],shooting.reflecttDirectionb[refNum],shooting.reflecttDirectionc[refNum],raymanage2.twoPoint[0],raymanage2.twoPoint[1]);
				float refCoefficientLength;//����ϵ����ģֵ
				refCoefficientLength=raymanage2.findBuildingRefCofficient(raymanage2.buildingRefAngleCos,interFrequence);//�����ﷴ��ϵ����ģֵ
				complex refCoefficient;//���ķ���ϵ��
				refCoefficient=raymanage2.findBuildingComplexCofficient(raymanage2.buildingRefAngleCos,interFrequence);//�����︴�ķ���ϵ��
				shooting.reflecttDirectiona.push_back(raymanage2.buildingRefDirectionA);
				shooting.reflecttDirectionb.push_back(raymanage2.buildingRefDirectionB);
				shooting.reflecttDirectionc.push_back(raymanage2.buildingRefDirectionC);
				shooting.reflecttCoefficient.push_back(refCoefficientLength);//���뷴��ϵ����ģֵ
				shooting.reflectComplexCoefficient.push_back(refCoefficient);//���븴�ķ���ϵ��
			}
		}

		gridPower  gridPower4;
			int shootingRecordFlag;//���ڼ�¼����
			shootingRecordFlag=num;
			//gridPower4.gridRayLook(shooting,rayInterval,interFrequence,shootingRecordFlag, kuiLength);

		gridPower4.gridAllPowerCalculate(shooting,rayInterval,interFrequence,shootingRecordFlag, kuiLength);


	}//������������ִ����ķֺ�

	//����һ����վ����������ĳ�ǿֵ

	////����һ����վ����������ĳ�ǿֵ

	//
	vector<int>haveCalculateNumberGrid;//�Ѿ�������������ŵ��б��ŵ�vector�У�ÿ�μ���ʱ����һ���Ƚ�
	haveCalculateNumberGrid.clear();
	int sameFlag;//�Ƿ��ظ��ı�־λ������ظ�����Ϊ1�����ظ���Ϊ0
	int havePowerNumber=0;//������������¼�й��ʵ��������

	if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
	{
		cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
		return;
	}
	try
	{
		m_pRecordset->Open("SELECT * FROM  GridFieldStrenth",(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF) 
		{
			sameFlag=0;
			int GID;//������
			GID=int(m_pRecordset->GetCollect("GId"));
			for(int i=0;i<haveCalculateNumberGrid.size();i++)
			{
				if(GID==haveCalculateNumberGrid[i])
				{
					sameFlag=1;
					break;

				}

			}
			if(sameFlag==0)
			{
				_RecordsetPtr m_pRecordset1;
				if(FAILED(m_pRecordset1.CreateInstance( _uuidof( Recordset ))))
				{
					cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
					return;
				}
				string Ext;
				string medm;
				int mBid1,mBid2;
				stringstream ss;
				Ext.append("SELECT * FROM  GridFieldStrenth WHERE GId=");
				ss<<GID;
				Ext.append(ss.str());
				complex receiveElecFiledStrength;	
				GridPowerResult gridNumber;
				try
				{
					m_pRecordset1->Open(Ext.c_str(),(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
					Ext.clear();
					ss.str("");
					ss.clear();
					m_pRecordset1->MoveFirst();
					while(!m_pRecordset1->adoEOF) 
					{

						receiveElecFiledStrength.real=double(m_pRecordset1->GetCollect("GCReal"));
						receiveElecFiledStrength.img=double(m_pRecordset1->GetCollect("GCImg"));
						gridNumber.gridFinalPower.push_back(receiveElecFiledStrength);
						m_pRecordset1->MoveNext();
					}
				}
				catch (_com_error &e)
				{
					cout << e.Description()<<endl;
				}
				cout<<GID<<endl;	
				gridNumber.findGridFinalTotalPower(interFrequence);

				Grid grid2;
				grid2.addThisGridStrengthToNew(GID,gridNumber.gridFinalTotalPower,baseStationNumber);
				havePowerNumber++;
				haveCalculateNumberGrid.push_back(GID);
				m_pRecordset1->Close();
			}
			m_pRecordset->MoveNext();
		}

	}
	catch (_com_error &e)
	{
		cout << e.Description()<<endl;
	}


}