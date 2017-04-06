//다항식
#include <iostream>
#include <stdio.h>

#define MAX_DEGREE 80 //매크로 

using namespace std;

class CKJHPoly
{
public:
   int m_degree; //계수
   double *m_coef; //최고차수(동적할당)   

   CKJHPoly(int m_degree1 = 0) //class CKJHPoly의 생성자 함수로서 초기화
   {
      m_degree = 0;
	  Init(m_degree1);
   }
   CKJHPoly(CKJHPoly &p)//복사생성자 생성
   {
      m_degree = 0;
      Clone(p);
   }
   CKJHPoly operator=(CKJHPoly &p)//대입 연산자 오버로딩
   {
      Clone(p);
      return *this;
   }
   void Init(int m_degree1) //메모리의 동적 할당 부분
   {
      Reset();
      m_degree = m_degree1;
      m_coef = new double[m_degree1 + 1];
      for (int i = 0; i <= m_degree1; i++)
         m_coef[i] = 0.0f;
   }

   void Clone(CKJHPoly &p)//복사 생성자
   {
      this->Init(p.m_degree);
      for (int i = 0; i <= p.m_degree; i++)
         m_coef[i] = p.m_coef[i];
   }

   ~CKJHPoly(void)//소멸자 함수
   {
	   Reset();
   } 
   void Reset() //메모리의 동적 할당 부분을 delete하기위해 선언이 되어진 부분 
   {
      if (m_degree != 0)
      {
         m_degree = 0;
		//delete[] m_coef;
      }
   }
   void Read()//입력
   {
      int x;
      printf("다항식의 최고 차수를 입력하세요:");
      scanf("%d", &x);
      Init(x);
      printf(" 각 항의 계수를 입력하시오 <%d>: ", m_degree + 1);
      for (int i = 0; i <= m_degree; i++)
      {
         scanf("%lf", &m_coef[i]);
      }
   }
   void Print()//출력
   {
      int x = 0;
      int mdegree = m_degree;
      printf("   다항식 : ");
      for (int i = 0; i < m_degree+1; i++)
      {
         if (i==m_degree)
         {
            printf("%.1lf \n", m_coef[i]);
         }
         else if (x!= m_degree)
         {
            printf("%.1lf*x^%d + ", m_coef[i], mdegree--);
         }
      }
   }
   friend CKJHPoly Add(CKJHPoly a, CKJHPoly b);//a+b
   friend CKJHPoly Sub(CKJHPoly a, CKJHPoly b);//a-b
   friend CKJHPoly Mul(CKJHPoly a, float k);//a*k
   CKJHPoly operator+ (CKJHPoly b)   { return Add(*this,b); }//+연산자 오버로딩
   CKJHPoly operator- (CKJHPoly b)   { return Sub(*this, b); }//-연산자 오버로딩
   CKJHPoly operator* (float k)      { return Mul(*this, k); }//*연산자 오버로딩
};
inline CKJHPoly Mul(CKJHPoly a, float k)//a*k
{
   CKJHPoly c;
   c.Clone(a);//복사 생성자 생성

   for (int i = 0; i <= c.m_degree; i++)
   {
      c.m_coef[i] *= k;
   }
   return c;
}

inline CKJHPoly Add(CKJHPoly a,CKJHPoly b)//a+b
{
	CKJHPoly c;//class 객체 선언
	int Apos=0,Bpos=0,Cpos=0;//지역변수
	int degree_a=a.m_degree;//a객체 초기화(최고차수)
	int degree_b=b.m_degree;//b객체 초기화(최고차수)
	    if(a.m_degree>=b.m_degree)
       c.m_degree=a.m_degree;
   else 
      c.m_degree=b.m_degree;
 
   c.m_coef=new double[c.m_degree];
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
inline CKJHPoly Sub(CKJHPoly a, CKJHPoly b)//a+b
{

      CKJHPoly c;
   int Apos=0,Bpos=0,Cpos=0;
   int degree_a=a.m_degree;
   int degree_b=b.m_degree;
   
   if(a.m_degree>=b.m_degree)
       c.m_degree=a.m_degree;
   else 
      c.m_degree=b.m_degree;
 
   c.m_coef=new double[c.m_degree];//메모리 동적할당

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

int main(void)
{

   CKJHPoly a, b, c, d;
   a.Read();
   a.Print();


   b.Read();
   b.Print();


   //c = add (a, b);
   c = a + b;
   printf("a + b =");
   c.Print();

   ////d = sub (a, b);
   d = a - b;
   printf("a - b = ");
   d.Print();

   //c = mult (a, 2.0);
   c = a * 2.0;
   printf("a * 2.0 = ");
   c.Print();

   return 0;
}