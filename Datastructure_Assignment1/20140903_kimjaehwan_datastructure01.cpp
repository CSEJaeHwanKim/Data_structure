#include <iostream>
using namespace std;
class First //Ŭ���� ����(�ڱ�Ұ�,������,���α׷�����)
{
public:
	void Introduce()
	{
		cout<<" �̸�: ����ȯ"<<endl;
		cout<<" ����: 23"<<endl;
		cout<<" �ڵ�����ȣ: 01033968381"<<endl;
		cout<<" ����: ����"<<endl;
		cout<<" ���: ����"<<endl;
		cout<<" ������:A��"<<endl;
		cout<<" ����: ��ǻ�� ���к�"<<endl;
		cout<<" �г�: 2�г�"<<endl;
		cout<<" ����������: ���� 1����"<<endl;
		cout<<" �������� ����: ��ȸ���� ���� ����~!"<<endl;
	}//�ڱ�Ұ�

	void Dan(int n)
	{
		int result=0;//��������� ����
		cout<<endl;
		for(n=2;n<10;n++)
		{
			for(int i=1;i<10;i++)
			{
				result=n*i;
				printf("%d*%d=%2d\n",n,i,result);	
			}
			cout<<endl;
	    }
	}//������

	void Finish()
	{
		cout<<"���α׷��� �����մϴ�"<<endl;
	}//���α׷�����

};
int main(void)
{
	int num;
	int i=2;
	First f1;
	while(1)//3���� �Է��Ͽ� ���α׷��� ����Ǳ� ������ ����ؼ� ó������ ���ư��� �ְ� �Ѵ�
	{
    cout<<"1.�ڱ�Ұ�  2.������  3.���α׷�����"<<endl<<endl;
	cout<<"�����ϰ��� �ϴ� �۾��� �����ϼ���"<<endl<<endl;
	cin>>num;
	if(num==1)//1���� �Է��Ұ�� �ڱ� �Ұ� ���
	{
		f1.Introduce();
		system("pause");
		system("cls");	
	}
	else if(num==2)//2���� �Է��Ұ�� ���������
	{
		f1.Dan(i);
		system("pause");
		system("cls");
		
    }
	else if(num==3)//3���� �Է��Ұ�� ���α׷�����
	{
		f1.Finish();
		system("pause");
		system("cls");
		break;
	}
	else//1,2,3�� ������ �����Է½� 1,2,3���ڸ� �Է��Ҷ����� ���Է�
	{
		cout<<"�߸��� �Է��Դϴ� �ٽ� �Է����ֱ� �ٶ��ϴ�"<<endl;
		system("pause");
		system("cls");
	}
	}
	return 0;
}