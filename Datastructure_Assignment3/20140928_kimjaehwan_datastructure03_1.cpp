//1.���� �Է¹޾� �׼��� �������� ���Ǵ� �˰����� �ɸ��� �ð��� �����ϴ� �˰���
#include <iostream>
#include <cmath>
#include <time.h>
#include <windows.h>
using namespace std;
double hkdPowerIter( double x, int n);//�˰���A
double hkdPowerRecur( double x, int n);//�˰���B
int main(void)
{
	double a;
	int n1;
	double duration1,duration2;
	clock_t start,finish;
	printf("�ΰ��� ���� �Է� �ϼ���\n");
	scanf("%lf",&a);//�Ϲݼ�
	scanf("%d",&n1);//������
	printf("\n");

	start=clock();
	hkdPowerIter(a,n1);//�˰���A
	finish=clock();
	duration1=(double)(finish-start)/CLOCKS_PER_SEC;
	
	start=clock();
	hkdPowerRecur(a,n1);//�˰���B
	finish=clock();

	duration2=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("�ð�����\n");
	printf("�˰���A:%lf\n�˰���B:%lf\n",duration1,duration2);//�ð� ���
	printf("\n");
	printf("��갪\n");
	printf("�˰���A:%lf\n",hkdPowerIter(a,n1));//A�� ���
	printf("�˰���B:%lf\n\n",hkdPowerRecur(a,n1));//B�� ���
	return 0;
}
 double hkdPowerIter( double x, int n) //�˰���A
 {
	 int i;
	 double result=1.0;
	 
	 for(i=1;i<=n;i++)
	 {
		 result = result * x;
	 }
	 Sleep(10);

	  return result;
 }
 double hkdPowerRecur( double x, int n) //�˰���A
 {
	 
	 if( n==0 )
	 {
		 Sleep(10);
			 return 1;
	 }
	 else if ( (n%2)==0 ) 
	 { Sleep(10);
		 return  hkdPowerRecur(x*x, n/2); 
	 } 
	 else 
	 { Sleep(10);
		 return  x*hkdPowerRecur(x*x, (n-1)/2); 
	 }
	 
 }