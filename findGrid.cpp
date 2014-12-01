#include "findGrid.h"

findGrid::findGrid()
{
	x[0+400]=0;
	for(int p=-400;p<=-1;p++)
	{
		x[p+400]=p*5;
	}
	for(int p=1;p<=401;p++)
	{
		x[p+400]=(p-1)*5;
	}
	y[0+400]=0;
	for(int p=-400;p<=-1;p++)
	{
		y[p+400]=p*5;
	}
	for(int p=1;p<=401;p++)
	{
		y[p+400]=(p-1)*5;
	}
	gridx0=0;  //�����ŵĲο�����xy.ÿ�ζ�Ҫ��
	gridy0=0;  //�����ŵĲο�����xyÿ�ζ�Ҫ��
	memset(m,0,sizeof(m));
	memset(n,0,sizeof(n));
	//m[1000]={0,0};
	//n[1000]={0,0};
}
int findGrid::findpointgridx (float x0,float a)   //x0��ֵ���ڸ�����
{
	int i;
	float t; 
	x0=x0-gridx0;
	//�ж�x0�Ƿ��ܱ�5����
	if(x0<0)
		t=-x0;
	else t=x0;
	int a1;
	a1=(int) t;
	float c1;
	c1=a1-t;
	int d1=1;
	if(c1==0&&a1%5==0)
		d1=0;
	if(d1==0)  //�ڶ�������
	{           
		int b1;   //���x����ı��
		b1=(int) x0;
		b1=b1/5;
		if(b1>0)
		{
			if(a<0)
				i=b1+1;
			else if(a>0)
				i=b1;
		}
		if(b1==0)
		{
			if(a<0)
				i=b1+1;
			else if(a>0)
				i=b1-1;
		}
		if(b1<0)
		{
			if(a<0)
				i=b1;
			else if(a>0)
				i=b1-1;
		}
	}
	if(d1!=0) //���ڶ�������
	{

		if(x0>0)      //���x����ı��
		{
			int b1;  
			b1=(int) x0;
			b1=b1/5;
			i=b1+1;
		}
		if(x0<0)
		{
			int b1;  
			float x3;
			x3=-x0;
			b1=(int) x3;
			b1=b1/5;
			i=b1+1;
			i=-i;
		}
	}

	return i;
}
int findGrid::findpointgridy(float y0,float b)  //y0��ֵ���ڸ�����
{        
	int j;
	float m ;
	y0=y0-gridy0;
	//�ж�y0�Ƿ��ܱ�5����
	if(y0<0)
		m=-y0;
	else m=y0;
	int a2;
	a2=(int) m;
	float c2;
	c2=a2-m;
	int d2=1;
	if(c2==0&&a2%5==0)
		d2=0;
	if(d2==0)    //�ڶ�������
	{
		int b2;   //���y����ı��
		b2=(int) y0;
		b2=b2/5;
		if(b2>0)
		{
			if(b<0)
				j=b2+1;
			else if(b>0)
				j=b2;
		}
		if(b2==0)
		{
			if(b<0)
				j=b2+1;
			else if(b>0)
				j=b2-1;
		}
		if(b2<0)
		{
			if(b<0)
				j=b2;
			else if(b>0)
				j=b2-1;
		}
	}
	if(d2!=0)
	{  
		if(y0>0)      //���y����ı��
		{
			int b2;  
			b2=(int) y0;
			b2=b2/5;
			j=b2+1;
		}
		if(y0<0)
		{
			int b2;  
			float y3;
			y3=-y0;
			b2=(int) y3;
			b2=b2/5;
			j=b2+1;
			j=-j;
		}
		return j;
	} 
}

void findGrid:: findallgrid(float x0, float y0, int i, int j,int h, int k,float a, float b) //��������ֱ�����������xyֵ����ʼ�����ţ���ֹ�����ţ����ߵ�б��
{    
	m[0]=i;
	n[0]=j;
	int firstEqualFinal=0;//�ж�������ʼ������յ������Ƿ�λ��ͬһ�������ǵĻ�Ϊ1�����ǵĻ�Ϊ0
	if(i==h&&j==k)//������ߵ������յ�λ��ͬһ������Ļ���һ��ʼ��ֹͣ
		firstEqualFinal=1;
	if(firstEqualFinal==0)
	{
		float len;
	len=b/a;
	if(len<0)
		len=-len;
	float x1,D;
	if (a>0&&b>0)
	{
		x1=x0+a/b*(y[j+400]-y0);
		D=b/a*(x[i+1+400]-x1);

		for(int p=1;p<=1000;p++)
		{
			if(D<5)
			{ 
				if (m[p-1]==-1)
				{
					m[p]=m[p-1]+2;
				}
				else m[p]=m[p-1]+1;
				n[p]=n[p-1];
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+len*5;
				continue;
			}
			if(D==5)
			{
				if (m[p-1]==-1)
				{
					m[p]=m[p-1]+2;
				}
				else m[p]=m[p-1]+1;
				if (n[p-1]==-1)
				{
					n[p]=n[p-1]+2;
				}
				else n[p]=n[p-1]+1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+(len-1)*5;
				continue;

			}
			if(D>5)
			{
				m[p]=m[p-1];
				if (n[p-1]==-1)
				{
					n[p]=n[p-1]+2;
				}
				else n[p]=n[p-1]+1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D-5;
				continue;
			}

		}
	}
	if (a!=0&&b==0)
	{
		for(int p=1;p<=1000;p++)
		{
			if(a>0)
			{ 
				if (m[p-1]==-1)
					m[p]=m[p-1]+2;
				else m[p]=m[p-1]+1;
				n[p]=n[p-1];
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
			}
			if(a<0)
			{ 
				if (m[p-1]==1)
					m[p]=m[p-1]-2;
				else m[p]=m[p-1]-1;
				n[p]=n[p-1];
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
			}


		}
	}
	if (a==0&&b!=0)
	{
		for(int p=1;p<=1000;p++)
		{
			if(b>0)
			{ 
				m[p]=m[p-1];
				if (n[p-1]==-1)
					n[p]=n[p-1]+2;
				else n[p]=n[p-1]+1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}

			}
			if(b<0)
			{ 
				m[p]=m[p-1];
				if (n[p-1]==1)
					n[p]=n[p-1]-2;
				else n[p]=n[p-1]-1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}

			}


		}
	}
	if (a>0&&b<0)
	{

		x1=x0+a/b*(y[j+400+1]-y0);
		D=b/a*(x[i+1+400]-x1)*(-1);
		for(int p=1;p<=1000;p++)
		{
			if(D<5)
			{
				if (m[p-1]==-1)
				{
					m[p]=m[p-1]+2;
				}
				else m[p]=m[p-1]+1;
				n[p]=n[p-1];
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+len*5;
				continue;
			}
			if(D==5)
			{
				if (m[p-1]==-1)
				{
					m[p]=m[p-1]+2;
				}
				else m[p]=m[p-1]+1;
				if (n[p-1]==1)
				{
					n[p]=n[p-1]-2;
				}
				else n[p]=n[p-1]-1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+(len-1)*5;
				continue;
			}
			if(D>5)
			{
				m[p]=m[p-1];
				if (n[p-1]==1)
				{
					n[p]=n[p-1]-2;
				}
				else n[p]=n[p-1]-1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D-5;
				continue;
			}

		}
	}
	if (a<0&&b<0)
	{

		x1=x0+a/b*(y[j+400+1]-y0);
		D=b/a*(x[i+400]-x1)*(-1);
		for(int p=1;p<=1000;p++)
		{
			if(D<5)
			{
				if (m[p-1]==1)
				{
					m[p]=m[p-1]-2;
				}
				else m[p]=m[p-1]-1;
				n[p]=n[p-1];
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+len*5;
				continue;
			}
			if(D==5)
			{
				if (m[p-1]==1)
				{
					m[p]=m[p-1]-2;
				}
				else m[p]=m[p-1]-1;
				if (n[p-1]==1)
				{
					n[p]=n[p-1]-2;
				}
				else n[p]=n[p-1]-1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+(len-1)*5;
				continue;
			}
			if(D>5)
			{
				m[p]=m[p-1];
				if (n[p-1]==1)
				{
					n[p]=n[p-1]-2;
				}
				else n[p]=n[p-1]-1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D-5;
				continue;
			}
		}
	}
	
	if (a<0&&b>0)
	{

		x1=x0+a/b*(y[j+400]-y0);
		D=b/a*(x[i+400]-x1);
		for(int p=1;p<=1000;p++)
		{


			if(n[0]<0)
			{
				int mn;
				mn=1;
			}
			if(p==999)
			{
				int aaaaa;
			}
			if(D<5)
			{
				if (m[p-1]==1)
				{
					m[p]=m[p-1]-2;
				}
				else m[p]=m[p-1]-1;
				n[p]=n[p-1];
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+len*5;
				continue;
			}
			if(D==5)
			{
				if (m[p-1]==1)
				{
					m[p]=m[p-1]-2;
				}
				else m[p]=m[p-1]-1;
				if (n[p-1]==-1)
				{
					n[p]=n[p-1]+2;
				}
				else n[p]=n[p-1]+1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D+(len-1)*5;
				continue;
			}
			if(D>5)
			{
				m[p]=m[p-1];
				if (n[p-1]==-1)
				{
					n[p]=n[p-1]+2;
				}
				else n[p]=n[p-1]+1;
				if(m[p]==h&&n[p]==k)
				{
					break;
				}
				D=D-5;
				continue;
			}

		}
	}
}
}
int* findGrid:: get_allgridx()   //���ذ����߷�������ˮƽ���
{
	return &m[0];
}
int* findGrid::get_allgridy()   //���ذ����߷�������ֱ���
{
	return &n[0];
}
int findGrid::findfirstpointgridx(float x0,float a)//��������ʼ�����ڵ������ˮƽ��ţ������������ʼ���x���꣬ˮƽ����ϵ����������ʼ�����������Ķ����ϣ����ϻ�������
{
	int i;
	float t; 
	x0=x0-gridx0;  //�ж�x0�Ƿ��ܱ�5����
	if(x0<0)
		t=-x0;
	else t=x0;
	int a1;
	a1=(int) t;
	float c1;
	c1=a1-t;
	int d1=1;
	if(c1==0&&a1%5==0)
		d1=0;
	if(d1==0)  //�ڶ�������
	{           
		int b1;   //���x����ı��
		b1=(int) x0;
		b1=b1/5;
		if(b1>0)
		{
			if(a>0)
				i=b1+1;
			else if(a<0)
				i=b1;
		}
		if(b1==0)
		{
			if(a>0)
				i=b1+1;
			else if(a<0)
				i=b1-1;
		}
		if(b1<0)
		{
			if(a>0)
				i=b1;
			else if(a<0)
				i=b1-1;
		}
	}
	if(d1!=0) //���ڶ�������
	{

		if(x0>0)      //���x����ı��
		{
			int b1;  
			b1=(int) x0;
			b1=b1/5;
			i=b1+1;
		}
		if(x0<0)
		{
			int b1;  
			float x3;
			x3=-x0;
			b1=(int) x3;
			b1=b1/5;
			i=b1+1;
			i=-i;
		}
	}
	return i;
}
int findGrid::findfirstpointgridy(float y0,float b)//��������ʼ�����ڵ�����Ĵ�ֱ��ţ������������ʼ���y���꣬��ֱ����ϵ��
{        
	int j;
	float m ;
	y0=y0-gridy0;
	//�ж�y0�Ƿ��ܱ�5����
	if(y0<0)
		m=-y0;
	else m=y0;
	int a2;
	a2=(int) m;
	float c2;
	c2=a2-m;
	int d2=1;
	if(c2==0&&a2%5==0)
		d2=0;
	if(d2==0)    //�ڶ�������
	{
		int b2;   //���y����ı��
		b2=(int) y0;
		b2=b2/5;
		if(b2>0)
		{
			if(b>0)
				j=b2+1;
			else if(b<0)
				j=b2;
		}
		if(b2==0)
		{
			if(b>0)
				j=b2+1;
			else if(b<0)
				j=b2-1;
		}
		if(b2<0)
		{
			if(b>0)
				j=b2;
			else if(b<0)
				j=b2-1;
		}
	}
	if(d2!=0)
	{  
		if(y0>0)      //���y����ı��
		{
			int b2;  
			b2=(int) y0;
			b2=b2/5;
			j=b2+1;
		}
		if(y0<0)
		{
			int b2;  
			float y3;
			y3=-y0;
			b2=(int) y3;
			b2=b2/5;
			j=b2+1;
			j=-j;
		}
		return j;
	} 
}

