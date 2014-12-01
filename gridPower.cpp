#include "gridPower.h"


//void gridPower::findGroundGridPowerFirst(float groundCrossPointx,float groundCrossPointy,float shootingStartx,float shootingStarty,float shootingStartz,
//	float shootingDirectiona,float shootingDirectionb,float shootingDirectionc,float shootingLength,float antennaGain,gridPowerResult gridNumber[])//���߸տ�ʼ����ؼ���������
//{
//	findGrid findgrid1;
//	int q1,q2;
//	q1=findgrid1.findpointgridx(groundCrossPointx,shootingDirectiona);
//	q2=findgrid1.findpointgridy(groundCrossPointy,shootingDirectionb);
//	float gridCenterX, gridCenterY;
//	rayManage raymanage1;
//	gridCenterX=raymanage1.findGridCenterxy(q1);//����������ĵ�ĺ�����
//	gridCenterY=raymanage1.findGridCenterxy(q2);//����������ĵ��������
//	float receiveBallR;
//	receiveBallR=3.14*shootingLength*3/(180*sqrt(3.0));
//	float pointDistance;//�㵽ֱ�ߵľ���
//	pointDistance=raymanage1.findPointToLineDistance(shootingStartx,shootingStarty,shootingStartz,shootingDirectiona,shootingDirectionb,shootingDirectionc,gridCenterX,gridCenterY,0);
//	if(pointDistance<receiveBallR)
//	{
//		float antennaPower=46;//��վ�������ʼ����Ϊ46dbm�������Ǹ��������ǿɵ���
//		float baseStationloss=0;//��վ����ģ������ȿ���Ϊ0
//		float receivePower;//���չ���
//		receivePower=antennaPower-10.9921-20*log10( shootingLength)+antennaGain;//10.9921����10log4pai
//		receivePower=exp(log(10.0)*(receivePower/10));
//		int gridId;
//		//Grid grid1;
//		//gridId=grid1.findGridId(gridCenterX,gridCenterY);
//		 //gridId=3;//��ʱ��ֵ����Ҫ�ĵ�
//		//ֻ���ڼ��������ĵ�ͼ��Χ�ڲſ����������д�ȡ����
//		//�������Ҫ���ݵ�ͼ�Ĵ�С���ı��
//		if(gridCenterX>0&&gridCenterX<55&&gridCenterY>0&&gridCenterY<75)
//		{
//			Grid grid1;
//		grid1.GetThisGirdRecord(gridCenterX,gridCenterY);
//		gridId=grid1.id;
//		//cout<<gridId<<endl;
//		 
//
////		gridNumber[gridId].gridFinalPower.push_back(receivePower);//��������غ�������ʷ��뵽�����У��Ա�������
//		}
//		
//	}
//	
//
//
//}
////���ߵ���ʱ����䵽���棬����Ե�������Ĺ���
//void gridPower::findGroundGridPowerSecond(float groundCrossPointx,float groundCrossPointy,float shootingStartx,float shootingStarty,float shootingStartz,
//	float shootingDirectiona,float shootingDirectionb,float shootingDirectionc,float shootingLength,float antennaGain,float totalRefCoefficient,gridPowerResult gridNumber[])
//{
//	
//	findGrid findgrid1;
//	int q1,q2;
//	q1=findgrid1.findpointgridx(groundCrossPointx,shootingDirectiona);
//	q2=findgrid1.findpointgridy(groundCrossPointy,shootingDirectionb);
//	float gridCenterX, gridCenterY;
//	rayManage raymanage1;
//	gridCenterX=raymanage1.findGridCenterxy(q1);//����������ĵ�ĺ�����
//	gridCenterY=raymanage1.findGridCenterxy(q2);//����������ĵ��������
//	float receiveBallR;
//	receiveBallR=3.14*shootingLength*3/(180*sqrt(3.0));
//	float pointDistance;//�㵽ֱ�ߵľ���
//	pointDistance=raymanage1.findPointToLineDistance(shootingStartx,shootingStarty,shootingStartz,shootingDirectiona,shootingDirectionb,shootingDirectionc,gridCenterX,gridCenterY,0);
//	if(pointDistance<receiveBallR)
//	{
//		float antennaPower=46;//��վ�������ʼ����Ϊ46dbm�������Ǹ��������ǿɵ���
//		float baseStationloss=0;//��վ����ģ������ȿ���Ϊ0
//		float receivePower;//���չ���
//		receivePower=antennaPower-10.9921-20*log10(shootingLength)+antennaGain+20*log10(totalRefCoefficient);//10.9921����10log4pai
//		receivePower=exp(log(10.0)*(receivePower/10));
//		int gridId;
//		//ֻ���ڼ��������ĵ�ͼ��Χ�ڲſ����������д�ȡ����
//		//�������Ҫ���ݵ�ͼ�Ĵ�С���ı��
//		if(gridCenterX>0&&gridCenterX<55&&gridCenterY>0&&gridCenterY<75)
//		{
//		Grid grid1;
//		grid1.GetThisGirdRecord(gridCenterX,gridCenterY);
//		gridId=grid1.id;
//		//cout<<gridId<<endl;
////		gridNumber[gridId].gridFinalPower.push_back(receivePower);//��������غ�������ʷ��뵽�����У��Ա�������
//		}
//	}
//	 
//
//
//}

void gridPower::gridAllPowerCalculate(rayPath raypath1,float rayInterval,float frequence,int rayRecord,float kuixian)//�������߶���������Ĺ���
{
	int Id=1;
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
			_bstr_t strConnect="Driver={sql server};server=ZHANGZHE-PC;uid=sa;pwd=123456;database=test25;";
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
		
	}
	catch (_com_error &e)
	{
		cout << e.Description()<<endl;
	}

	int lineNumber;//һ�����ߵ��߶���
	lineNumber=raypath1.searchGridNumberTrue.size();
	for(int i=1;i<=lineNumber;i++)
	{
		int lineGridNumber;//һ���߶ΰ�����������
		lineGridNumber=raypath1.searchGridNumberTrue[i-1];
		float lineLengthBefore=0;//�ڼ��������뾶ʱ���ڼ���֮ǰ��·������
		int totalNumber;
		int lineGridNumberBefore=0;//������������ʱ�ܹ���֤���߶α�Ŵ�����
		complex totalCoefficienrt={1,0};//������¼���ķ���ϵ��,��ʼֵ����Ϊ1
		totalNumber=i-1;
		for(int q=1;q<=totalNumber;q++)
		{
			lineLengthBefore=lineLengthBefore+raypath1.rayLength[q-1];
			complexCalculate complexcalculate2;
			complexcalculate2.findComplexMulComplex(totalCoefficienrt,raypath1.reflectComplexCoefficient[q-1]);
			totalCoefficienrt=complexcalculate2.consequence;
			lineGridNumberBefore=lineGridNumberBefore+raypath1.searchGridNumberTrue[q-1];
		}
		for(int j=1;j<=lineGridNumber;j++)
		{
			int gridX,gridY;//���ڼ�¼������
			gridX=raypath1.searchGridTrueX[lineGridNumberBefore+j-1];
			gridY=raypath1.searchGridTrueY[lineGridNumberBefore+j-1];
			rayManage raymanage3;
			float gridCenterX, gridCenterY;
			gridCenterX=raymanage3.findGridCenterxy(gridX);//����������ĵ�ĺ�����
			gridCenterY=raymanage3.findGridCenterxy(gridY);//����������ĵ��������
			float pointDistance;//�㵽ֱ�ߵľ���
			pointDistance=raymanage3.findPointToLineDistance(raypath1.crossPointx[i-1],raypath1.crossPointy[i-1],raypath1.crossPointz[i-1],
				raypath1.reflecttDirectiona[i-1],raypath1.reflecttDirectionb[i-1],raypath1.reflecttDirectionc[i-1],gridCenterX,gridCenterY,1.5);
			float lineLengthAfter;//��Ա������ߵĳ���
			lineLengthAfter=raymanage3.findShootingLineLength(raypath1.crossPointx[i-1],raypath1.crossPointy[i-1],raypath1.crossPointz[i-1],
				raypath1.reflecttDirectiona[i-1],raypath1.reflecttDirectionb[i-1],raypath1.reflecttDirectionc[i-1],gridCenterX,gridCenterY,1.5);
			float lineLengthFinal;//����·�����ܳ���
			lineLengthFinal=lineLengthAfter+lineLengthBefore;
			float receiveBallR;
			receiveBallR=3.14*lineLengthFinal*rayInterval/(180*sqrt(3.0));
			if(pointDistance<receiveBallR)
			{
				/*
				float antennaPower=46;//��վ�������ʼ����Ϊ46dbm�������Ǹ��������ǿɵ���
				float baseStationloss=0;//��վ����ģ������ȿ���Ϊ0
				float receivePower;//���չ���
				receivePower=antennaPower-10.9921-20*log10( lineLengthFinal)+raypath1.rayGain;//10.9921����10log4pai
				receivePower=exp(log(10.0)*(receivePower/10));				
				*/
				//Grid grid1;
				//gridId=grid1.findGridId(gridCenterX,gridCenterY);
				//gridId=3;//��ʱ��ֵ����Ҫ�ĵ�
				//ֻ���ڼ��������ĵ�ͼ��Χ�ڲſ����������д�ȡ����
				//�������Ҫ���ݵ�ͼ�Ĵ�С���ı��
				//if(gridCenterX>0&&gridCenterX<55&&gridCenterY>0&&gridCenterY<75)
				float waveLength;//���岨��
				waveLength=300/frequence;//Ƶ����MHZΪ��λ
				double shootingGain;//���ߵ�����ֵ�ɷֱ�����ʵ��ֵ��2.302585����ln10
				shootingGain=exp(2.302585*raypath1.rayGain/10);
				float kuixianLoss;//���������ֵ��Ȼ�����ɷֱ�ת����ʵ��ֵ
				if(frequence==900)
					 
					{
						kuixianLoss=kuixian/100*7.22;
				     kuixianLoss=exp(2.302585*kuixianLoss/10);
				}
				if(frequence==1800)
					 
					{
						kuixianLoss=kuixian/100*11.3;
				     kuixianLoss=exp(2.302585*kuixianLoss/10);
				}

				complex receiveElecFiledStrength;//�õ����յ��ĵ糡ǿ��ֵ�����书����Ȼ��46dbmΪ�ο�������ĵ�λ����w,39.8w
				float m,n;
				m=(sqrt(30*39.8*shootingGain/kuixianLoss))/lineLengthFinal;
				n=cos(6.28*lineLengthFinal/waveLength);
				receiveElecFiledStrength.real=(sqrt(30*39.8*shootingGain/kuixianLoss))*cos(6.28*lineLengthFinal/waveLength)/lineLengthFinal;
				receiveElecFiledStrength.img=(-1)*(sqrt(30*39.8*shootingGain/kuixianLoss))*sin(6.28*lineLengthFinal/waveLength)/lineLengthFinal;
				complexCalculate complexcalculate3;
				complexcalculate3.findComplexMulComplex(receiveElecFiledStrength,totalCoefficienrt);//���յ��ĵ糡ǿ�ȳ��Է���ϵ��
				receiveElecFiledStrength=complexcalculate3.consequence;//�õ����յĵ糡ǿ��
				    int gridId;
					Grid grid1;
					grid1.GetThisGirdRecord(gridCenterX,gridCenterY);
					gridId=grid1.id;
					//cout<<gridId<<endl;
					if(gridId==36407)

					{
						int aaa;
					    aaa=1;
					}

					try
	                {	
						m_pRecordset->AddNew();
						m_pRecordset->PutCollect("Id",_variant_t(Id));
						Id++;
						m_pRecordset->PutCollect("GId",_variant_t(gridId));
						m_pRecordset->PutCollect("GCReal",_variant_t(receiveElecFiledStrength.real));
						m_pRecordset->PutCollect("GCImg",_variant_t(receiveElecFiledStrength.img));
						m_pRecordset->PutCollect("GRS",_variant_t(rayRecord));
						m_pRecordset->Update();
						}
					catch (_com_error &e)
	{
		cout << e.Description()<<endl;
	}
	   // 		gridNumber[gridId].gridFinalPower.push_back(receiveElecFiledStrength);//��������غ�������ʷ��뵽�����У��Ա�������
				//gridNumber[gridId].shootingRecord.push_back(rayRecord);//��һ�������й���ֵʱ�����ж����ĸ����ߵĹ���

			}
		}
	}
}
void gridPower::gridRayLook(rayPath raypath1,float rayInterval,float frequence,int rayRecord,float kuixian)//������ͶӰ�켣�ò�ͬ��ɫ������
	{
	
		int color[17]={ COLOR1, COLOR17, COLOR2, COLOR16, COLOR3, COLOR15, COLOR4, COLOR14, COLOR5, COLOR13, COLOR6, COLOR12, COLOR7, COLOR11, COLOR8, COLOR10, COLOR9};
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
			_bstr_t strConnect="Driver={sql server};server=ZHANGZHE-PC;uid=sa;pwd=123456;database=test25;";
			sqlSp->Open(strConnect,"","",adModeUnknown);
		}
			catch(_com_error &e) {
				cout<<e.Description()<<endl;
			}
	}
	_RecordsetPtr m_pRecordset;
	vector<int> RayGridColor;//�����洢ÿ���������ɫ
	vector<int> RayGridNumber;//�����洢���������������������
	int colorBefore;//����֮ǰ����ɫ
	int colorNow;//�������ڵ���ɫ
	int lineNumber;//һ�����ߵ��߶���
	lineNumber=raypath1.searchGridNumberTrue.size();
	for(int i=1;i<=lineNumber;i++)
	{
		int lineGridNumber;//һ���߶ΰ�����������
		lineGridNumber=raypath1.searchGridNumberTrue[i-1];
		float lineLengthBefore=0;//�ڼ��������뾶ʱ���ڼ���֮ǰ��·������
		int totalNumber;
		int lineGridNumberBefore=0;//������������ʱ�ܹ���֤���߶α�Ŵ�����
		complex totalCoefficienrt={1,0};//������¼���ķ���ϵ��,��ʼֵ����Ϊ1
		totalNumber=i-1;
		for(int q=1;q<=totalNumber;q++)
		{			
			lineGridNumberBefore=lineGridNumberBefore+raypath1.searchGridNumberTrue[q-1];
		}
		for(int j=1;j<=lineGridNumber;j++)
		{
			int gridX,gridY;//���ڼ�¼������
			gridX=raypath1.searchGridTrueX[lineGridNumberBefore+j-1];
			gridY=raypath1.searchGridTrueY[lineGridNumberBefore+j-1];
			rayManage raymanage3;
			float gridCenterX, gridCenterY;
			gridCenterX=raymanage3.findGridCenterxy(gridX);//����������ĵ�ĺ�����
			gridCenterY=raymanage3.findGridCenterxy(gridY);//����������ĵ��������
			
				    int gridId;
					Grid grid1;
					grid1.GetThisGirdRecord(gridCenterX,gridCenterY);
					gridId=grid1.id;
					if(gridId==31448)

					{
						int aaa;
					    aaa=1;
					}
					if(gridId==32235)

					{
						int baa;
					    baa=1;
					}
					//cout<<gridId<<endl;
					RayGridNumber.push_back(gridId);
					
	if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
	{
		cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
		return;
	}
	string Ext;
	stringstream ss;
	Ext.append("SELECT * FROM  Grid WHERE GId=");
	ss<<gridId;
	Ext.append(ss.str());
	ss.str("");
	ss.clear();
	try 
	{
		m_pRecordset->Open(Ext.c_str(),(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
	}
	catch (_com_error &e)
	{
		cout << e.Description()<<endl;
	}
	try
		{
			colorBefore=int(m_pRecordset->GetCollect("GColor"));
			colorNow=color[i];
			RayGridColor.push_back(colorBefore);	
              
			   m_pRecordset->PutCollect("GColor",_variant_t(colorNow));
			   m_pRecordset->Update();
			  // m_pRecordset1->MoveNext();

			
	    }
			catch (_com_error &e)
	   {
		cout << e.Description()<<endl;
	   }		
			

			}
		}
	//��ԭ������ɫ�ָ�����
	//for(int i=1;i<=RayGridNumber.size();i++)
	//{
	//	int id=RayGridNumber[i-1];
	//	if(FAILED(m_pRecordset.CreateInstance( _uuidof( Recordset ))))
	//{
	//	cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
	//	return;
	//}
	//	string Ext;
	//	stringstream ss;
	//Ext.append("SELECT * FROM  Grid WHERE GId=");
	//ss<<id;
	//Ext.append(ss.str());
	//ss.str("");
	//ss.clear();
	//try 
	//{
	//	m_pRecordset->Open(Ext.c_str(),(IDispatch*)sqlSp,adOpenDynamic,adLockOptimistic, adCmdText);
	//}
	//catch (_com_error &e)
	//{
	//	cout << e.Description()<<endl;
	//}
	//try
	//	{
	//		
 //             if(RayGridColor[i-1]!=0&&RayGridColor[i-1]!=16777215)
	//		   {
	//			   m_pRecordset->PutCollect("GColor",_variant_t(RayGridColor[i-2]));
	//		  }
	//		  else
	//		  {
	//		  m_pRecordset->PutCollect("GColor",_variant_t(RayGridColor[i-1]));
	//		  }
	//		   m_pRecordset->Update();
	//		  // m_pRecordset1->MoveNext();

	//		
	//    }
	//		catch (_com_error &e)
	//   {
	//	cout << e.Description()<<endl;
	//   }		


	//}




	}





