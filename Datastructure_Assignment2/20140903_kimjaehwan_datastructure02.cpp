/*//자료구조2번째과제_1번문제
#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <time.h>
using namespace std;
int main(void)
{
	int n; //입력받는 정수
	double duration1,duration2,duration3; //각 알고리즘 시간 저장 
	clock_t start,finish; //시간 계산을 위한 clock
	int hkd_sum_01,hkd_sum_0n=0,hkd_sum_0nn=0; //각각의 알고리즘
    int m=1; //세번째 알고리즘에 사용되는 m값의 초기화 값
	
	    
		while(1) //값을 계속해서 출력하기 위한 무한 루프
		{
			cout<<"n값을 입력 받으시오"<<endl;
			
			cin>>n;
			cout<<endl;

			start=clock();
			hkd_sum_01=n*(n+1)/2;
			finish=clock();
			duration1=(double)(finish-start);
			Sleep(10); //알고리즘 A {O(n^2)}

			hkd_sum_0n=0;
			start=clock();
			for(int i=1;i<=n;i++)
			{
				hkd_sum_0n+=i;
			}
			finish=clock();
			duration2=(double)(finish-start);
			Sleep(10); //알고리즘 B {O(n)}

			hkd_sum_0nn=0;
			m=1;
			start=clock();
			for(int l=1;l<=n;l++)
			{
				for(int j=1;j<=m;j++)
				{
					hkd_sum_0nn+=1;
				}
				m++;
			}
			finish=clock();
			duration3=(double)(finish-start);
			Sleep(10); //알고리즘 C {O(1)}

			cout<<"n값의 합"<<endl;
			printf(" A:%3d\n B:%3d\n C:%3d\n\n",hkd_sum_01,hkd_sum_0n,hkd_sum_0nn); //n값을 입력 받아 n값까지의 합
			//cout<<hkd_sum_01<<endl<<hkd_sum_0n<<endl<<hkd_sum_0nn<<endl;
			cout<<"알고리즘이 걸리는 시간"<<endl;
			printf(" A:%7lf\n B:%7lf\n C:%7lf\n",duration1,duration2,duration3); //각각의 알고리즘에 숫자를 입력 받아 걸리는 시간
			//cout<<(double)duration1<<endl<<(double)duration2<<endl<<(double)duration3<<endl;
			cout<<endl;
			system("pause");
			system("cls");
		}
	return 0;
}*/

//자료구조2번째과제_2번문제
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
int main(void)
{
	int mul = 1;
    int i,j; //반복문 사용을 위한 인자
    int n=1;
    clock_t start,finish; // 시간 계산
	double time1,time2; // 두 알고리즘의 시간 저장
	printf("**알고리즘 A와 알고리즘 B의 시간 차이**\n\n");
    while(1)
	{
		
	start=clock();
	for(i=0;i<n;i++)
	{
		for(j=1;j<1000;j++)
		{
			mul=mul*j;
		}
    } //알고리즘 A
	Sleep(100);
	finish=clock();
	time1=(double)(finish-start)/CLOCKS_PER_SEC;

	mul=1;
	start=clock();
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			mul = mul *j;
        }
    } //알고리즘 B
	Sleep(100);
	finish=clock();
  
    time2=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("알고리즘A: %3lf 알고리즘B: %3lf\n",time1,time2); //시간출력
	
	//cout<<time1<<endl<<time2<<endl;
	//system("pause");
	
	if(time1<time2)
	{
		printf("알고리즘B가 %d 번째 부터 더많이 걸립니다\n\n",n);
		break;
	}
	else
	{
		n++;
	} //알고리즘 두개를 서로 비교하면서 알고리즘B가 커질경우 그때까지의 횟수를 n에 저장하여 마지막에 출력한다
}

 return 0;
}

