//���׽�
#include<iostream>
#define MAX_DEGREE 80 //��ũ�� 
#define MAX(a,b)((((a)>(b)?(a):(b)))) //����Ŀ��� ��ü�� ���� �ϱ� ���� ���� ����
using namespace std;

class CKJHPoly
{
public:
	int m_degree; //���
	double m_coef[MAX_DEGREE]; //�ְ�����   
	CKJHPoly(void) //class CKJHPoly�� ������ �Լ��μ� �ʱ�ȭ
	{
		m_degree=0;
		for(int i=0;i<MAX_DEGREE;i++)
			m_coef[i]=0.0f;
	}
	~CKJHPoly(void){} //�Ҹ��� �Լ�
	void Read()//�Է�
	{
		int x=0;
		printf("���׽��� �ְ� ������ �Է��ϼ���:");
		scanf("%d",&m_degree);
		x=m_degree;
		printf(" �� ���� ����� �Է��Ͻÿ� <%d>: ",m_degree+1);
		for(int i=0;i<=m_degree;i++)
		{
			//printf("%d",x--);
			scanf("%lf",&m_coef[i]);
		}
	}
	void Print()//���
	{
		int x=0;
		int y=m_degree;
		printf("   ���׽� : ");
		for(int i=0;i<=m_degree;i++)
		{
			if(x!=y)
			{
				printf("%.1lf + x^%d + ",m_coef[i],y--);
			}
			else
			{
				printf("%.1lf \n",m_coef[i]);
			}
		}
	}
	friend CKJHPoly Add(CKJHPoly a,CKJHPoly b);//a+b
	friend CKJHPoly Sub(CKJHPoly a,CKJHPoly b);//a-b
	friend CKJHPoly Mul(CKJHPoly a,float k);//a*k
};
inline CKJHPoly Add(CKJHPoly a,CKJHPoly b)//a+b
{
	CKJHPoly c;//class ��ü ����
	int Apos=0,Bpos=0,Cpos=0;//��������
	int degree_a=a.m_degree;//a��ü �ʱ�ȭ(�ְ�����)
	int degree_b=b.m_degree;//b��ü �ʱ�ȭ(�ְ�����)
	c.m_degree=MAX(a.m_degree,b.m_degree);//MAX�� �Է�
	while(Apos<=a.m_degree&&Bpos<=b.m_degree)//�������� ��
	{
		if(degree_a>degree_b)//a������ Ŭ��� a���
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++];
			degree_a--;
		}

		else if(degree_a==degree_b)//������ ������� ���� ��
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++]+b.m_coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else//b������ Ŭ��� b���
		{
			c.m_coef[Cpos++]=b.m_coef[Bpos++];
			degree_b--;
		}
	}
	return c;

}
inline CKJHPoly Sub(CKJHPoly a,CKJHPoly b)//a-b
{
		CKJHPoly c;
	int Apos=0,Bpos=0,Cpos=0;
	int degree_a=a.m_degree;
	int degree_b=b.m_degree;
	c.m_degree=MAX(a.m_degree,b.m_degree);
	while(Apos<=a.m_degree&&Bpos<=b.m_degree)//�������� ��
	{
		if(degree_a>degree_b)//a������ Ŭ��� a���
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++];
			degree_a--;
		}

		else if(degree_a==degree_b)//������ ������� ���� ����
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++]-b.m_coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else//b������ Ŭ��� b���
		{
			c.m_coef[Cpos++]=b.m_coef[Bpos++];
			degree_b--;
		}
	}
	return c;
}
inline CKJHPoly Mul(CKJHPoly a,float k)//a*k
{
	CKJHPoly c;
	
	int Apos=0,Cpos=0;
	int degree_a=a.m_degree;
	c.m_degree=a.m_degree;
	while(Apos<=a.m_degree)//k���� ���Ѵ�
	{
		c.m_coef[Cpos++]=k*(a.m_coef[Apos++]);
			degree_a--;
	}
	return c;
}

int main(void)
{
	float y;
	printf("������ k���� �Է��Ͻÿ�:");//Mul������ k�� �Է�
	scanf("%f",&y);
	CKJHPoly a,b,c,d,e;

	a.Read();
	a.Print();
	
	b.Read();
	b.Print();

	c=Add(a,b);
	d=Sub(a,b);
	e=Mul(a,y);
    printf(" a+b "); 	
	c.Print();
	printf(" a-b ");
	d.Print();
	printf(" a*k ");
	e.Print();

	return 0;
}