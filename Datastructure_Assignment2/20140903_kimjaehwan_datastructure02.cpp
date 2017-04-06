/*//�ڷᱸ��2��°����_1������
#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <time.h>
using namespace std;
int main(void)
{
	int n; //�Է¹޴� ����
	double duration1,duration2,duration3; //�� �˰��� �ð� ���� 
	clock_t start,finish; //�ð� ����� ���� clock
	int hkd_sum_01,hkd_sum_0n=0,hkd_sum_0nn=0; //������ �˰���
    int m=1; //����° �˰��� ���Ǵ� m���� �ʱ�ȭ ��
	
	    
		while(1) //���� ����ؼ� ����ϱ� ���� ���� ����
		{
			cout<<"n���� �Է� �����ÿ�"<<endl;
			
			cin>>n;
			cout<<endl;

			start=clock();
			hkd_sum_01=n*(n+1)/2;
			finish=clock();
			duration1=(double)(finish-start);
			Sleep(10); //�˰��� A {O(n^2)}

			hkd_sum_0n=0;
			start=clock();
			for(int i=1;i<=n;i++)
			{
				hkd_sum_0n+=i;
			}
			finish=clock();
			duration2=(double)(finish-start);
			Sleep(10); //�˰��� B {O(n)}

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
			Sleep(10); //�˰��� C {O(1)}

			cout<<"n���� ��"<<endl;
			printf(" A:%3d\n B:%3d\n C:%3d\n\n",hkd_sum_01,hkd_sum_0n,hkd_sum_0nn); //n���� �Է� �޾� n�������� ��
			//cout<<hkd_sum_01<<endl<<hkd_sum_0n<<endl<<hkd_sum_0nn<<endl;
			cout<<"�˰����� �ɸ��� �ð�"<<endl;
			printf(" A:%7lf\n B:%7lf\n C:%7lf\n",duration1,duration2,duration3); //������ �˰��� ���ڸ� �Է� �޾� �ɸ��� �ð�
			//cout<<(double)duration1<<endl<<(double)duration2<<endl<<(double)duration3<<endl;
			cout<<endl;
			system("pause");
			system("cls");
		}
	return 0;
}*/

//�ڷᱸ��2��°����_2������
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
int main(void)
{
	int mul = 1;
    int i,j; //�ݺ��� ����� ���� ����
    int n=1;
    clock_t start,finish; // �ð� ���
	double time1,time2; // �� �˰����� �ð� ����
	printf("**�˰��� A�� �˰��� B�� �ð� ����**\n\n");
    while(1)
	{
		
	start=clock();
	for(i=0;i<n;i++)
	{
		for(j=1;j<1000;j++)
		{
			mul=mul*j;
		}
    } //�˰��� A
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
    } //�˰��� B
	Sleep(100);
	finish=clock();
  
    time2=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("�˰���A: %3lf �˰���B: %3lf\n",time1,time2); //�ð����
	
	//cout<<time1<<endl<<time2<<endl;
	//system("pause");
	
	if(time1<time2)
	{
		printf("�˰���B�� %d ��° ���� ������ �ɸ��ϴ�\n\n",n);
		break;
	}
	else
	{
		n++;
	} //�˰��� �ΰ��� ���� ���ϸ鼭 �˰���B�� Ŀ����� �׶������� Ƚ���� n�� �����Ͽ� �������� ����Ѵ�
}

 return 0;
}

