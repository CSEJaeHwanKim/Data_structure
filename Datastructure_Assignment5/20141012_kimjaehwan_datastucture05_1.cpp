//���׽�
#include <iostream>
#include <stdio.h>

#define MAX_DEGREE 80 //��ũ�� 

using namespace std;

class CKJHPoly
{
public:
   int m_degree; //���
   double *m_coef; //�ְ�����(�����Ҵ�)   

   CKJHPoly(int m_degree1 = 0) //class CKJHPoly�� ������ �Լ��μ� �ʱ�ȭ
   {
      m_degree = 0;
	  Init(m_degree1);
   }
   CKJHPoly(CKJHPoly &p)//��������� ����
   {
      m_degree = 0;
      Clone(p);
   }
   CKJHPoly operator=(CKJHPoly &p)//���� ������ �����ε�
   {
      Clone(p);
      return *this;
   }
   void Init(int m_degree1) //�޸��� ���� �Ҵ� �κ�
   {
      Reset();
      m_degree = m_degree1;
      m_coef = new double[m_degree1 + 1];
      for (int i = 0; i <= m_degree1; i++)
         m_coef[i] = 0.0f;
   }

   void Clone(CKJHPoly &p)//���� ������
   {
      this->Init(p.m_degree);
      for (int i = 0; i <= p.m_degree; i++)
         m_coef[i] = p.m_coef[i];
   }

   ~CKJHPoly(void)//�Ҹ��� �Լ�
   {
	   Reset();
   } 
   void Reset() //�޸��� ���� �Ҵ� �κ��� delete�ϱ����� ������ �Ǿ��� �κ� 
   {
      if (m_degree != 0)
      {
         m_degree = 0;
		//delete[] m_coef;
      }
   }
   void Read()//�Է�
   {
      int x;
      printf("���׽��� �ְ� ������ �Է��ϼ���:");
      scanf("%d", &x);
      Init(x);
      printf(" �� ���� ����� �Է��Ͻÿ� <%d>: ", m_degree + 1);
      for (int i = 0; i <= m_degree; i++)
      {
         scanf("%lf", &m_coef[i]);
      }
   }
   void Print()//���
   {
      int x = 0;
      int mdegree = m_degree;
      printf("   ���׽� : ");
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
   CKJHPoly operator+ (CKJHPoly b)   { return Add(*this,b); }//+������ �����ε�
   CKJHPoly operator- (CKJHPoly b)   { return Sub(*this, b); }//-������ �����ε�
   CKJHPoly operator* (float k)      { return Mul(*this, k); }//*������ �����ε�
};
inline CKJHPoly Mul(CKJHPoly a, float k)//a*k
{
   CKJHPoly c;
   c.Clone(a);//���� ������ ����

   for (int i = 0; i <= c.m_degree; i++)
   {
      c.m_coef[i] *= k;
   }
   return c;
}

inline CKJHPoly Add(CKJHPoly a,CKJHPoly b)//a+b
{
	CKJHPoly c;//class ��ü ����
	int Apos=0,Bpos=0,Cpos=0;//��������
	int degree_a=a.m_degree;//a��ü �ʱ�ȭ(�ְ�����)
	int degree_b=b.m_degree;//b��ü �ʱ�ȭ(�ְ�����)
	    if(a.m_degree>=b.m_degree)
       c.m_degree=a.m_degree;
   else 
      c.m_degree=b.m_degree;
 
   c.m_coef=new double[c.m_degree];
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
 
   c.m_coef=new double[c.m_degree];//�޸� �����Ҵ�

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