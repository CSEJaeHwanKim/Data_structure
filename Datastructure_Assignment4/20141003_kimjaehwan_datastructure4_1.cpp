//다항식
#include<iostream>
#define MAX_DEGREE 80 //매크로 
#define MAX(a,b)((((a)>(b)?(a):(b)))) //연산식에서 객체에 저장 하기 위해 조건 지정
using namespace std;

class CKJHPoly
{
public:
	int m_degree; //계수
	double m_coef[MAX_DEGREE]; //최고차수   
	CKJHPoly(void) //class CKJHPoly의 생성자 함수로서 초기화
	{
		m_degree=0;
		for(int i=0;i<MAX_DEGREE;i++)
			m_coef[i]=0.0f;
	}
	~CKJHPoly(void){} //소멸자 함수
	void Read()//입력
	{
		int x=0;
		printf("다항식의 최고 차수를 입력하세요:");
		scanf("%d",&m_degree);
		x=m_degree;
		printf(" 각 항의 계수를 입력하시오 <%d>: ",m_degree+1);
		for(int i=0;i<=m_degree;i++)
		{
			//printf("%d",x--);
			scanf("%lf",&m_coef[i]);
		}
	}
	void Print()//출력
	{
		int x=0;
		int y=m_degree;
		printf("   다항식 : ");
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
	CKJHPoly c;//class 객체 선언
	int Apos=0,Bpos=0,Cpos=0;//지역변수
	int degree_a=a.m_degree;//a객체 초기화(최고차수)
	int degree_b=b.m_degree;//b객체 초기화(최고차수)
	c.m_degree=MAX(a.m_degree,b.m_degree);//MAX값 입력
	while(Apos<=a.m_degree&&Bpos<=b.m_degree)//차수끼리 비교
	{
		if(degree_a>degree_b)//a차수가 클경우 a출력
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++];
			degree_a--;
		}

		else if(degree_a==degree_b)//차수가 같을경우 서로 합
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++]+b.m_coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else//b차수가 클경우 b출력
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
	while(Apos<=a.m_degree&&Bpos<=b.m_degree)//차수끼리 비교
	{
		if(degree_a>degree_b)//a차수가 클경우 a출력
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++];
			degree_a--;
		}

		else if(degree_a==degree_b)//차수가 같을경우 서로 뺄샘
		{
			c.m_coef[Cpos++]=a.m_coef[Apos++]-b.m_coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else//b차수가 클경우 b출력
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
	while(Apos<=a.m_degree)//k값을 곱한다
	{
		c.m_coef[Cpos++]=k*(a.m_coef[Apos++]);
			degree_a--;
	}
	return c;
}

int main(void)
{
	float y;
	printf("곱식의 k값을 입력하시오:");//Mul에서의 k값 입력
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