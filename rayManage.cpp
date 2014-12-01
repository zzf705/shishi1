#include "rayManage.h"


void rayManage:: findFinalCrossPoint(float startPointx,float startPointy,float startPointz,float startDirectiona,float startDirectionb,float startDirectionc,int maxGridx,int maxGridy,float coveringDistance,vector<vector<BuildingPoint>> BY,vector<float> HY)//������Ľ��㣬�õ�һЩ����
{   
	float crosspointx, crosspointy, crosspointz; //�뽨������ģ���õ����뽨���Ľ��㣬�����Ϊ���ݺ͵���Ƚϣ�������Ľ���
    int crossBuildingName; //������Ľ������ڵĽ�����ı��
   int f=0;//��־λ���ж������Ƿ������������е�����֮���뽨�����ཻ
   int searchgridnum;//����������ĸ���
   double min_distance=10000;//ʵ���У����ߵľ���һ����10000С
   int crossPointPosition;//��õĽ���λ�ڶ���Ϊ1,λ�ڲ���Ϊ0

   rayInit m( startPointx, startPointy, startPointz,startDirectiona, startDirectionb, startDirectionc); //���߳�ʼ��
   m.rayfinalpointxy(m.get_firstx(),m.get_firsty(),m.get_firstz(),m.get_directiona(),m.get_directionb(),m.get_directionc(), coveringDistance);//�����ߵ��յ�����
   findGrid q;//����һ���������
   m.setfirstgridx(q.findfirstpointgridx(m.get_firstx(),m.get_directiona())); //�����ߵ���ʼ���Ӧ������x
   m.setfirstgridy(q.findfirstpointgridy(m.get_firsty(),m.get_directionb())); //�����ߵ���ʼ���Ӧ������y
   m.setfinalgridx(q.findpointgridx(m.get_finalx(),m.get_directiona()));   //�����ߵ��յ��Ӧ������x
   m.setfinalgridy(q.findpointgridy(m.get_finaly(),m.get_directionb()));   //�����ߵ��յ��Ӧ������y
   q.findallgrid(m.get_firstx(),m.get_firsty(),m.getfirstgridx(),m.getfirstgridy(),m.getfinalgridx(),m.getfinalgridy(),m.get_directiona(),m.get_directionb());//�����߾������е�����
   m.setallgridx(q.get_allgridx());//���õ���ˮƽ�����ŵļ��ϸ���searchgridx[1000]
   m.setallgridy(q.get_allgridy());//���õ���ˮƽ�����ŵļ��ϸ���searchgridy[1000]
   m.setsearchgridnumber();
  
	
	
	//int gridm[1000],gridn[1000];
	memset(gridm,0,sizeof(gridm));//�����������ʼΪ��
	memset(gridn,0,sizeof(gridn));
	memset(gridTruem,0,sizeof(gridTruem));
	memset(gridTruen,0,sizeof(gridTruen));
	int *p=m.getallgridx();
	int *qq=m.getallgridy();
    gridNumberTrue=0;//ʵ���������Ŀ�����ǵ�ʵ�ʵ�ͼ�ķ�Χ�����������޵�
	
	  for(int i=1;i<=m.getsearchgridnumber();i++)
	{       int grid1,grid2;
	        grid1=*p;
			grid2=*qq;

		if( grid1>0&&grid1<maxGridx+1&&grid2>0&&grid2<maxGridy+1)
		{
			gridm[i-1]=grid1;
			gridn[i-1]=grid2;
			   p++;
		       qq++;
		gridNumberTrue++;
		}
		else 
			break;//���������Χ���Ͳ��ڼ�¼
		
	  }
	
	  
	   for(int t=1;t<=gridNumberTrue;t++)
	   {
		     Grid grid1;

           int budnumber=0;//һ����������Ľ�������
		   float gridCenterX,gridCenterY;//����������ĵ������
		   if(gridm[t-1]>0)
		   {
			   gridCenterX=2.5*(2*gridm[t-1]-1);
		   }
		   if(gridm[t-1]<0)
		   {
			   int w;
			   w=-gridm[t-1];
			   gridCenterX=-2.5*(2*w-1);
		   }
		   if(gridn[t-1]>0)
		   {
			   gridCenterY=2.5*(2*gridn[t-1]-1);
		   }
		   if(gridn[t-1]<0)
		   {
			   int w;
			   w=-gridn[t-1];
			   gridCenterY=-2.5*(2*w-1);
		   }

		   grid1.GetThisGirdRecord(gridCenterX,gridCenterY);
		   for(int i=0;i<grid1.GBId.size();i++)
		   {
			   if(grid1.GBId[i]!=0)
			   budnumber++;
		   }
		   //int buildingname[4]; ������ı�ŵ����鼯��,���ڿ�����h.GBIB��ʾ
		   if (budnumber==0)
			   continue;
		   double a[10],b[10],c[10],d[10],e[10],flaH[10],linepoint1x[10],linepoint1y[10],linepoint2x[10],linepoint2y[10];//a b c�������꣬d�����Ƿ��ཻ��e������룬flaH����λ�ڽ������λ��
		   memset(a,0,sizeof(a));
	       memset(b,0,sizeof(b));
		   memset(c,0,sizeof(c));
		   memset(d,0,sizeof(d));
		   memset(e,0,sizeof(e));
		   memset(flaH,0,sizeof(flaH));
		   memset(linepoint1x,0,sizeof(linepoint1x)); //��¼�������ڵ��������������꣬������������
		   memset(linepoint1y,0,sizeof(linepoint1y));
		   memset(linepoint2x,0,sizeof(linepoint2x));
		   memset(linepoint2y,0,sizeof(linepoint2y));


		   for(int i=1;i<=grid1.GBId.size();i++)
		   {
			   if(grid1.GBId[i-1]==0)
				   continue;
			  // Building building1;//����һ���������࣬���ڲ��ҽ�������۵�
			   
			   // building1.GetThisBuildingRecord(grid1.GBId[i-1]);//��ý�������۵�
			   int pointnumber;
			   //pointnumber=building1.BPoint.size();
			   pointnumber=BY[(grid1.GBId[i-1]-1)].size();

			   float buildingheight;
			   //buildingheight= building1.buildingHeight;
			   buildingheight= HY[(grid1.GBId[i-1]-1)];
			   // h1.getHeightRecord;
			   //buildingheight=h1.height;
			   
			   /*int buildingCrossFlag=0;//���󽻺����еõ������Ƿ��뽨�����ཻ���ཻΪ1
			   float crossx;//���󽻺����еõ��Ľ���x����
			   float crossy;//���󽻺����еõ��Ľ���y����
			   float crossz;//���󽻺����еõ��Ľ���z����
			   int roofFlag;//���󽻺����еõ��Ľ����Ƿ�λ�ڶ��棬�ڶ���Ϊ1������Ϊ0
			   float sidepoint1[2],sidepoint2[2];//�������λ�ڲ��棬��������ڵ��߶εĶ���
			   */  //��ʱ��Ϊ��ע�����󽻺����п��Եõ���
			  FirstReflection firstReflection1;
			  firstReflection1.buildingCross( startPointx,startPointy,startPointz,startDirectiona, startDirectionb, startDirectionc,BY[(grid1.GBId[i-1]-1)],buildingheight);
			   if(firstReflection1.buildingCrossFlag==0)
				   continue;
			  a[i-1]=firstReflection1.crossX;
			  b[i-1]=firstReflection1.crossY;
			  c[i-1]=firstReflection1.crossZ;
			  double errorx, errory, errorz;
			  errorx=a[i-1]-startPointx;
			  errory=b[i-1]-startPointy;
			  errorz=c[i-1]-startPointz;
			  if(fabs(errorx)<0.0001&&fabs(errory)<0.0001&&fabs(errorz)<0.0001)
				  continue; //��Ҫ���Ǻͳ�ʼ���غϣ�����Ҳ�ڱ���������
			  if(errorx*startDirectiona<0||errory*startDirectionb<0||errorz*startDirectionc<0)
				  continue;//��������˵�����߰��෴�ķ�������
			   int i0,j0;//�м��������õ����ڵ�������
			   i0=q.findpointgridx(a[i-1],m.get_directiona());
			   j0=q.findpointgridy(b[i-1],m.get_directionb());
			   if(i0==gridm[t-1]&&j0==gridn[t-1])
			   {
				   d[i-1]=1;//��־λ����ʾ���������ڵ�������
				   e[i-1]=sqrt((m.get_firstx()-a[i-1])*(m.get_firstx()-a[i-1])+(m.get_firsty()-b[i-1])*(m.get_firsty()-b[i-1])+(m.get_firstz()-c[i-1])*(m.get_firstz()-c[i-1]));
				   flaH[i-1]=firstReflection1.roofFlag;
				   if( flaH[i-1]==0)
				   {
					   linepoint1x[i-1]=firstReflection1.refPolyPoint[0].x;
					   linepoint1y[i-1]=firstReflection1.refPolyPoint[0].y;
					   linepoint2x[i-1]=firstReflection1.refPolyPoint[1].x;
					   linepoint2y[i-1]=firstReflection1.refPolyPoint[1].y;

			       }
				    }
			   else continue;  //���������ڣ�������������һ��������
		   }//�����ڵĽ�����������
		  
		   for(int i=1;i<=grid1.GBId.size();i++)
		   {
			   if(d[i-1]==1)
			   {
				   if(e[i-1]<min_distance)
				   {
					   min_distance=e[i-1];
					  

		            }
				   }
		   }
			   if(min_distance==10000)
				   continue;//�޽����������У�����������һ������
			   for(int i=1;i<=grid1.GBId.size();i++)
			   {
				   if(e[i-1]==min_distance)
				   {
					   crosspointx=a[i-1];
					   crosspointy=b[i-1];
					   crosspointz=c[i-1];
					   crossBuildingName=grid1.GBId[i-1];
					   crossPointPosition=flaH[i-1];//�ڶ���Ϊ1������Ϊ0
					   f=1;
					   twoPoint[0].x=linepoint1x[i-1];
					   twoPoint[0].y=linepoint1y[i-1];
					   twoPoint[1].x=linepoint2x[i-1];
					   twoPoint[1].y=linepoint2y[i-1];
					   break;//���������ѭ��
					   }
			   }
		   
			   break;//���������ѭ������������뽨����Ľ���
	  }
		   if(f==1&&m.getgroundflag()==1)
		   {
			   if(m.getd1()>min_distance)  //d1Ϊ��ʼ�㵽���潻��ľ���
			   {
				   finalCrossFlag=1;//�н���
				   finalCrossPosition=0;//���ڽ�������
				   finalCrossPointx=crosspointx;
				   finalCrossPointy=crosspointy;
				   finalCrossPointz=crosspointz;
				   finalCrossBuildingname=crossBuildingName;
				  /* if(crossPointPosition==1)
				   stop=1;
				   if(crossPointPosition==0)
					   stop=0;
					   */
					   
				   finalCrossBuildingPosition=crossPointPosition;
				   finalRayLength=min_distance;
		        }
			   else
			   {
				   finalCrossFlag=1;//�н���
				   finalCrossPosition=1;//���ڵ�����
				   finalCrossPointx=m.get_finalx();
				   finalCrossPointy=m.get_finaly();
				   finalCrossPointz=m.get_finalz();
				   finalCrossBuildingname=0;//������ཻ
				   //stop=0;
				   finalRayLength=m.getd1();
			   }
		   }
		    if(f==1&&m.getgroundflag()==0)
			{
				 finalCrossFlag=1;//�н���
				   finalCrossPosition=0;//���ڽ�������
				   finalCrossPointx=crosspointx;
				   finalCrossPointy=crosspointy;
				   finalCrossPointz=crosspointz;
				   finalCrossBuildingname=crossBuildingName;
				  /* if(crossPointPosition==1)
				   stop=1;
				   if(crossPointPosition==0)
					   stop=0;
					   */
					   
				   finalCrossBuildingPosition=crossPointPosition;
				   finalRayLength=min_distance;
			}
			if(f==0&&m.getgroundflag()==1)
			{
				finalCrossFlag=1;//�н���
				finalCrossPosition=1;//���ڵ�����
				finalCrossPointx=m.get_finalx();
				finalCrossPointy=m.get_finaly();
				finalCrossPointz=m.get_finalz();
				finalCrossBuildingname=0;//������ཻ
				//stop=0;
				finalRayLength=m.getd1();
			}
			if(f==0&&m.getgroundflag()==0)
			{
				finalCrossFlag=0;//�޽���
			}

			if(finalCrossFlag==1)
			{
				int gridFinalx,gridFinaly;//�����Ӧ��������
				gridFinalx=q.findpointgridx(finalCrossPointx,startDirectiona);
				gridFinaly=q.findpointgridy(finalCrossPointy,startDirectionb);
				gridNumberStopCross=0;
				for(int i=1;i<=gridNumberTrue;i++)
				{
					gridTruem[i-1]=gridm[i-1];
					gridTruen[i-1]=gridn[i-1];
					gridNumberStopCross++;
					if(gridm[i-1]==gridFinalx&&gridn[i-1]==gridFinaly)
						break;
				}





			}
			}
			float rayManage:: findBuildingRefCofficient(float cosAngle,float frequence)//������ķ���ϵ��
			{


				float sinAngle;
				float jiezhi;//��������ʵĲ���
				sinAngle=sqrt(1-cosAngle*cosAngle);
				jiezhi=90000*(-1)/frequence;
				complex temp={0.05-sinAngle*sinAngle,jiezhi};
				complex temp1,temp2,temp3;
				complexCalculate complexCalcu1;
				complexCalcu1.findComplexRoot(temp);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexMulConst(temp1,-1);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp1,cosAngle);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexRoot(temp);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp2,cosAngle);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexDivid(temp1,temp2);
				temp3=complexCalcu1.consequence;

				return complexCalcu1.findComplexLength(temp3);
			}
			int rayManage::findPathStop( float pathDistance,float antennaGain,float frequence )//��һ�θ��ݾ����ж����ߵ������Ƿ񽵵�ĳһ��ֵ��0��ʾ��ֹͣ��1��ʾֹͣ
			{
				float antennaPower=46;//��վ�������ʼ����Ϊ46dbm�������Ǹ��������ǿɵ���
				float baseStationloss=0;//��վ����ģ������ȿ���Ϊ0
				float waveLength;//���岨��
				waveLength=300/frequence;//Ƶ����MHZΪ��λ
				float receivePower;//���չ���
				receivePower=antennaPower-10.9921*2-20*log10( pathDistance)+20*log10(waveLength)+10*log10(antennaGain);//10.9921����10log4pai
				if(receivePower<-110)//���ն˵���������-109����ʱ��Ϊ���ն˹��ʵ�10��֮һ
					return 1;
				else return 0;
			}
			int rayManage:: findPathRefStop( float pathDistance,float antennaGain,float reflectCofficient,float frequence)//���ݾ���ͷ���ϵ���ж����ߵ������Ƿ񽵵�ĳһ��ֵ��0��ʾ��ֹͣ��1��ʾֹͣ
			{
				float antennaPower=46;//��վ�������ʼ����Ϊ46dbm�������Ǹ��������ǿɵ���
				float baseStationloss=0;//��վ����ģ������ȿ���Ϊ0
				float receivePower;//���չ���
				float waveLength;//���岨��
				waveLength=300/frequence;//Ƶ����MHZΪ��λ
				receivePower=antennaPower-10.9921*2-20*log10( pathDistance)+20*log10(waveLength)+10*log10(antennaGain)+20*log10(reflectCofficient);//10.9921����10log4pai
				if(receivePower<-110)//���ն˵���������-109����ʱ��Ϊ���ն˹��ʵ�10��֮һ
					return 1;
				else return 0;

			}
			void rayManage::findGroundRefDirection(float shootingStartX,float shootingStartY,float shootingStartZ,float shootingDirectionX,float shootingDirectionY,float shootingDirectionZ)//���������ֵ

			{
				float shootingFinalX;
				float shootingFinalY;
				float shootingFinalZ;
				shootingFinalX=shootingStartX-shootingStartZ*shootingDirectionX/shootingDirectionZ;
				shootingFinalY=shootingStartY-shootingStartZ*shootingDirectionY/shootingDirectionZ;
				shootingFinalZ=0;

				float normalVectorX;
				float normalVectorY;
				float normalVectorZ;
				normalVectorX=0;
				normalVectorY=0;
				normalVectorZ=1;

				float symmetryPointX;
				float symmetryPointY;
				float symmetryPointZ;
				symmetryPointX=2*shootingFinalX-shootingStartX;
				symmetryPointY=2*shootingFinalY-shootingStartY;
				symmetryPointZ=shootingStartZ;


				groundRefDirectionA=symmetryPointX-shootingFinalX;
				groundRefDirectionB=symmetryPointY-shootingFinalY;
				groundRefDirectionC=symmetryPointZ-shootingFinalZ;


				groundRefAngleCos=(shootingDirectionX*normalVectorX+shootingDirectionY*normalVectorY+shootingDirectionZ*normalVectorZ)/sqrt(pow(shootingDirectionX, 2) + pow(shootingDirectionY, 2) + pow(shootingDirectionZ, 2));
				if(groundRefAngleCos<0)
					groundRefAngleCos=-groundRefAngleCos;
			}

			void  rayManage::findBuildingRefDirection( float shootingStartX,float shootingStartY,float shootingStartZ,float shootingFinalX,float shootingFinalY,float shootingFinalZ,float startDirectionA,float startDirectionB,float startDirectionC,TwoDimPointZhang refPolyPoint0,TwoDimPointZhang refPolyPoint1) //������ķ��䷽��ϵ�����������Ѿ��������ǵ�����ֵ

			{
				struct Line                         /*ֱ��һ�㷽�̵�����ϵ��*/
				{
					double a;
					double b;
					double c;
				};
				Line NormalLine;                   //����������ֱ��
				float normalVectorX;
				float normalVectorY;
				float normalVectorZ;
				normalVectorX=refPolyPoint1.y-refPolyPoint0.y;
				normalVectorY=refPolyPoint0.x-refPolyPoint1.x;
				normalVectorZ=0;

				NormalLine.a=refPolyPoint0.x-refPolyPoint1.x;
				NormalLine.b=refPolyPoint0.y-refPolyPoint1.y;
				NormalLine.c=-NormalLine.b*shootingFinalY-NormalLine.a*shootingFinalX;

				float A,B,C;
				A=NormalLine.a*NormalLine.a-NormalLine.b*NormalLine.b;
				B=2*NormalLine.a*NormalLine.b;
				C=NormalLine.a*NormalLine.a+NormalLine.b*NormalLine.b;

				float symmetryPointX;
				float symmetryPointY;
				float symmetryPointZ;
				symmetryPointX=(-A*shootingStartX-B*shootingStartY-2*NormalLine.a*NormalLine.c)/C;
				symmetryPointY=(A*shootingStartY-B*shootingStartX-2*NormalLine.b*NormalLine.c)/C;
				symmetryPointZ=2*shootingFinalZ-shootingStartZ;


				buildingRefDirectionA=symmetryPointX-shootingFinalX;
				buildingRefDirectionB=symmetryPointY-shootingFinalY;
				buildingRefDirectionC=symmetryPointZ-shootingFinalZ;

				//float buildingRefAngleCos;
				buildingRefAngleCos=(startDirectionA*normalVectorX+startDirectionB*normalVectorY+startDirectionC*normalVectorZ)/((sqrt(pow(startDirectionA, 2) + pow(startDirectionB, 2) + pow(startDirectionC, 2)))*(sqrt(pow(normalVectorX, 2) + pow(normalVectorY, 2) + pow(normalVectorZ, 2))));
				if(buildingRefAngleCos<0)
					buildingRefAngleCos=(-1)*buildingRefAngleCos;

			}
			float rayManage::findGroundRefCofficient(float cosAngle,float frequence)//�����ķ���ϵ����ģֵ������ķ���ϵ����ʱ�ͽ�����Ĳ�����һ���ģ����Ҫ���ݲ������е���
			{
				float sinAngle;
				float jiezhi;//��������ʵĲ���
				sinAngle=sqrt(1-cosAngle*cosAngle);
				jiezhi=36*(-1)/frequence;
				complex temp={5-sinAngle*sinAngle,jiezhi};
				complex temp1,temp2,temp3;
				complexCalculate complexCalcu1;
				complexCalcu1.findComplexRoot(temp);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexMulConst(temp1,-1);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp1,cosAngle);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexRoot(temp);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp2,cosAngle);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexDivid(temp1,temp2);
				temp3=complexCalcu1.consequence;

				return complexCalcu1.findComplexLength(temp3);
			}
			float rayManage:: findPointToLineDistance(float shootingStartx,float shootingStarty,float shootingStartz,float shootingDirectina,float shootingDirectinb,float shootingDirectinc,float pointx,float pointy,float pointz)//���������ĵ���1.5m��ֱ�ߵľ��룬�������ߵ����ͷ��򣬺��������ĵ������
			{
				struct shootingVector 
				{  
					float x;//������3��������x����
				    float y;
					float z;

				} lineVector1,lineVector2;//������һ�㵽�����������������ߵ�����
				lineVector1.x=pointx-shootingStartx;
				lineVector1.y=pointy-shootingStarty;
				lineVector1.z=pointz-shootingStartz;
				lineVector2.x=shootingDirectina;
				lineVector2.y=shootingDirectinb;
				lineVector2.z=shootingDirectinc;
				float cosValue,sinValue,q1,q2,q3;
				q1=lineVector1.x*lineVector2.x+lineVector1.y*lineVector2.y+lineVector1.z*lineVector2.z;
				q2=sqrt(lineVector1.x*lineVector1.x+lineVector1.y*lineVector1.y+lineVector1.z*lineVector1.z);
				q3=sqrt(lineVector2.x*lineVector2.x+lineVector2.y*lineVector2.y+lineVector2.z*lineVector2.z);
				cosValue=q1/(q2*q3);
				sinValue=sqrt(1-cosValue*cosValue);
				
				float d;
				d=q2*sinValue;
				return d;

			}
			float rayManage::  findShootingLineLength(float shootingStartx,float shootingStarty,float shootingStartz,float shootingDirectina,float shootingDirectinb,float shootingDirectinc,float pointx,float pointy,float pointz)//��㵽ֱ�ߵľ������Ҫ�����ߵĳ���
			{
				struct shootingVector 
				{  
					float x;//������3��������x����
					float y;
					float z;

				} lineVector1,lineVector2;//������һ�㵽�����������������ߵ�����
				lineVector1.x=pointx-shootingStartx;
				lineVector1.y=pointy-shootingStarty;
				lineVector1.z=pointz-shootingStartz;
				lineVector2.x=shootingDirectina;
				lineVector2.y=shootingDirectinb;
				lineVector2.z=shootingDirectinc;
				float cosValue,sinValue,q1,q2,q3;
				q1=lineVector1.x*lineVector2.x+lineVector1.y*lineVector2.y+lineVector1.z*lineVector2.z;
				q2=sqrt(lineVector1.x*lineVector1.x+lineVector1.y*lineVector1.y+lineVector1.z*lineVector1.z);
				q3=sqrt(lineVector2.x*lineVector2.x+lineVector2.y*lineVector2.y+lineVector2.z*lineVector2.z);
				cosValue=q1/(q2*q3);
				if(cosValue<0)
					cosValue=-cosValue;
				

				float d;
				d=q2*cosValue;
				return d;
			}
			float rayManage:: findGridCenterxy(int gridNumber)//���������ţ�������ĵ�����꣬ˮƽ�ʹ�ֱ��һ����
			{
				float gridCenterXY;
				if(gridNumber>0)
				{
					gridCenterXY=2.5*(2*gridNumber-1);
				}
				if(gridNumber<0)
				{
					int w;
					w=-gridNumber;
					gridCenterXY=-2.5*(2*w-1);
				}
				return gridCenterXY;
			}
			complex rayManage::findBuildingComplexCofficient(float cosAngle,float frequence)//������ķ���ϵ��,�Ǹ�������������λ��
			{
				float sinAngle;
				float jiezhi;//��������ʵĲ���
				sinAngle=sqrt(1-cosAngle*cosAngle);
				jiezhi=90000*(-1)/frequence;
				complex temp={0.05-sinAngle*sinAngle,jiezhi};
				complex temp1,temp2,temp3;
				complexCalculate complexCalcu1;
				complexCalcu1.findComplexRoot(temp);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexMulConst(temp1,-1);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp1,cosAngle);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexRoot(temp);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp2,cosAngle);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexDivid(temp1,temp2);
				temp3=complexCalcu1.consequence;
				return temp3;
			}
			complex rayManage::findGroundComplexCofficient(float cosAngle,float frequence)//�����ķ���ϵ��,�Ǹ�������������λ��
			{
				float sinAngle;
				float jiezhi;//��������ʵĲ���
				sinAngle=sqrt(1-cosAngle*cosAngle);
				jiezhi=36*(-1)/frequence;
				complex temp={5-sinAngle*sinAngle,jiezhi};
				complex temp1,temp2,temp3;
				complexCalculate complexCalcu1;
				complexCalcu1.findComplexRoot(temp);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexMulConst(temp1,-1);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp1,cosAngle);
				temp1=complexCalcu1.consequence;
				complexCalcu1.findComplexRoot(temp);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexAddConst(temp2,cosAngle);
				temp2=complexCalcu1.consequence;
				complexCalcu1.findComplexDivid(temp1,temp2);
				temp3=complexCalcu1.consequence;
				return temp3;
			}