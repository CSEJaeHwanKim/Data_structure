//1.수를 입력받아 그수의 제곱근이 계산되는 알고리즘의 걸리는 시간을 측정하는 알고리즘
#include <iostream>
#include <cmath>
#include <time.h>
#include <windows.h>
using namespace std;
double hkdPowerIter( double x, int n);//알고리즘A
double hkdPowerRecur( double x, int n);//알고리즘B
int main(void)
{
	double a;
	int n1;
	double duration1,duration2;
	clock_t start,finish;
	printf("두개의 수를 입력 하세요\n");
	scanf("%lf",&a);//일반수
	scanf("%d",&n1);//제곱근
	printf("\n");

	start=clock();
	hkdPowerIter(a,n1);//알고리즘A
	finish=clock();
	duration1=(double)(finish-start)/CLOCKS_PER_SEC;
	
	start=clock();
	hkdPowerRecur(a,n1);//알고리즘B
	finish=clock();

	duration2=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("시간측정\n");
	printf("알고리즘A:%lf\n알고리즘B:%lf\n",duration1,duration2);//시간 출력
	printf("\n");
	printf("계산값\n");
	printf("알고리즘A:%lf\n",hkdPowerIter(a,n1));//A값 출력
	printf("알고리즘B:%lf\n\n",hkdPowerRecur(a,n1));//B값 출력
	return 0;
}
 double hkdPowerIter( double x, int n) //알고리즘A
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
 double hkdPowerRecur( double x, int n) //알고리즘A
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