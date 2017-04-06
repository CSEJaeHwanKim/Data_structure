#include <iostream>
using namespace std;
class First //클래스 정의(자기소개,구구단,프로그램종료)
{
public:
	void Introduce()
	{
		cout<<" 이름: 김재환"<<endl;
		cout<<" 나이: 23"<<endl;
		cout<<" 핸드폰번호: 01033968381"<<endl;
		cout<<" 성별: 남자"<<endl;
		cout<<" 취미: 숙면"<<endl;
		cout<<" 혈핵형:A형"<<endl;
		cout<<" 전공: 컴퓨터 공학부"<<endl;
		cout<<" 학년: 2학년"<<endl;
		cout<<" 군복무여부: 예비역 1년차"<<endl;
		cout<<" 앞으로의 각오: 후회없는 삶을 살자~!"<<endl;
	}//자기소개

	void Dan(int n)
	{
		int result=0;//최종결과값 저장
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
	}//구구단

	void Finish()
	{
		cout<<"프로그램을 종료합니다"<<endl;
	}//프로그램종료

};
int main(void)
{
	int num;
	int i=2;
	First f1;
	while(1)//3번을 입력하여 프로그램이 종료되기 전까지 계속해서 처음으로 돌아갈수 있게 한다
	{
    cout<<"1.자기소개  2.구구단  3.프로그램종료"<<endl<<endl;
	cout<<"수행하고자 하는 작업을 선택하세요"<<endl<<endl;
	cin>>num;
	if(num==1)//1번을 입력할경우 자기 소개 출력
	{
		f1.Introduce();
		system("pause");
		system("cls");	
	}
	else if(num==2)//2번을 입력할경우 구구단출력
	{
		f1.Dan(i);
		system("pause");
		system("cls");
		
    }
	else if(num==3)//3번을 입력할경우 프로그램종료
	{
		f1.Finish();
		system("pause");
		system("cls");
		break;
	}
	else//1,2,3을 제외한 숫자입력시 1,2,3숫자를 입력할때까지 재입력
	{
		cout<<"잘못된 입력입니다 다시 입력해주기 바랍니다"<<endl;
		system("pause");
		system("cls");
	}
	}
	return 0;
}