//�ϳ���ž
#include <iostream>
using namespace std;
int count=0;//�������� �� ��ȸ�� ������ �Ǿ����� �������� count
void hanoi_tower(int n, char from, char tmp, char to)//�ϳ���ž �Լ�
{
 if( n==1 )
 {
	printf("%c => %c(ũ�Ⱑ 1�ο���) \n",from,to);
	count++;
 }
 else 
 {
	hanoi_tower(n-1, from, to, tmp);
	printf("%c => %c(ũ�Ⱑ %d�� ����) \n", from, to,n);
	hanoi_tower(n-1, tmp, from, to);
	count++;
 }
}
void main()
{
	
	while(1)//����ؼ� �ݺ�
	{
		count=0;
		printf("������ �Է��ϼ���\n");
		int a;
		cin>>a;
		hanoi_tower(a, 'A', 'B', 'C');
		
		printf("��Ƚ��: %d\n",count);
		cout<<endl;
		system("pause");
		system("cls");
	}
}
