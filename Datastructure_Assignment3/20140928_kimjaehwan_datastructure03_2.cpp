//2.�Ǻ���ġ ���� ���
#include <iostream>
#include <cmath>

using namespace std;

int count[100]; //fibo[n]���� ����� ���� ����

int hkdFiboIter(int n); //�ݺ�
int hkdFiboRecur(int n); //��ȯ

int main(void)
{
	int num1,i;
	
	while(1)
	{
	cout<<"���� �Է��Ͻÿ�"<<endl;
	scanf("%d",&num1);
	for(i=0;i<=num1;i++)
	{
		printf("�ݺ�: %d\n",hkdFiboIter(i));
		printf("��ȯ: %d\n",hkdFiboRecur(i));
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

int hkdFiboIter(int n) //�ݺ�
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

int hkdFiboRecur(int n) //��ȯ
{ 
	count[n]++;//��ȯ������ �󸶳� ���� �ݺ��� �Ǿ����� �˱����� ���ڸ� ���� ���� ������ ����
	
	if( n==0 )
		return 0; 
	if( n==1 ) 
		return 1;
	return (hkdFiboRecur(n-1) + hkdFiboRecur(n-2)); 
}
