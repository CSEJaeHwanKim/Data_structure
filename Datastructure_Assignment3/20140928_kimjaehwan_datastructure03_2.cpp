//2.피보나치 수열 출력
#include <iostream>
#include <cmath>

using namespace std;

int count[100]; //fibo[n]값을 출력을 위해 선언

int hkdFiboIter(int n); //반복
int hkdFiboRecur(int n); //순환

int main(void)
{
	int num1,i;
	
	while(1)
	{
	cout<<"수를 입력하시오"<<endl;
	scanf("%d",&num1);
	for(i=0;i<=num1;i++)
	{
		printf("반복: %d\n",hkdFiboIter(i));
		printf("순환: %d\n",hkdFiboRecur(i));
	}
	cout<<endl;
	printf("*fibo[n]*\n");
	for(int x=0;x<=num1;x++)
	{
		printf("fibo[%d]:%d\n",x,count[x]);
	}
	system("pause");
	system("cls");
	}
	
	return 0;

}

int hkdFiboIter(int n) //반복
{ 
	if(n<2)
		{
			return n;
		}
	else 
	{ 
		int i, tmp, current=1, last=0; 
		for(i=2;i<=n;i++)
		{ 
			tmp = current; current += last; 
			last = tmp; 
		} 
		return current; 
	} 
}

int hkdFiboRecur(int n) //순환
{ 
	count[n]++;//순환에서의 얼마나 많이 반복이 되었는지 알기위해 숫자를 세기 위해 위에서 선언
	
	if( n==0 )
		return 0; 
	if( n==1 ) 
		return 1;
	return (hkdFiboRecur(n-1) + hkdFiboRecur(n-2)); 
}
