//하노이탑
#include <iostream>
using namespace std;
int count=0;//마지막에 총 몇회가 실행이 되었는지 세기위한 count
void hanoi_tower(int n, char from, char tmp, char to)//하노이탑 함수
{
 if( n==1 )
 {
	printf("%c => %c(크기가 1인원판) \n",from,to);
	count++;
 }
 else 
 {
	hanoi_tower(n-1, from, to, tmp);
	printf("%c => %c(크기가 %d인 원판) \n", from, to,n);
	hanoi_tower(n-1, tmp, from, to);
	count++;
 }
}
void main()
{
	
	while(1)//계속해서 반복
	{
		count=0;
		printf("정수를 입력하세요\n");
		int a;
		cin>>a;
		hanoi_tower(a, 'A', 'B', 'C');
		
		printf("총횟수: %d\n",count);
		cout<<endl;
		system("pause");
		system("cls");
	}
}
