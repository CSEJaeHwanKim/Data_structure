#include<iostream>
#include"KJHMyQueue.h"
#include "KJHArray.h"
using namespace std;

void main()
{
	CKJHMyQueue q; //큐 객체생성
	CKJHMyNode * n;//노드 객체 생성(주소값)
	CKJHArray a;//Array큐객체 생성
	
	a.ArrEnQ1("박순자",1);
	a.ArrEnQ1("김순자",4);
	a.ArrEnQ1("이순자",9);
	a.ArrEnQ1("도순자",8);
	a.ArrEnQ1("백순자",7);
	
	a.Print();
	n=a.ArrDeQ();
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		cout<<endl;
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.",n->name,n->w_time);
	}
	n=a.ArrDeQ();
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		cout<<endl;
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.",n->name,n->w_time);
	}
	n=a.ArrDeQ();
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		cout<<endl;
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.",n->name,n->w_time);
	}
	n=a.ArrDeQ();
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		cout<<endl;
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.",n->name,n->w_time);
		cout<<endl;
	}
	a.Print();
	n=a.ArrDeQ();
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		cout<<endl;
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.",n->name,n->w_time);
	}


	q.EnQ("홍길동",1);
	q.EnQ("김길동",5);
	q.EnQ("고길동",4);
	q.EnQ("이길동",3);
	q.EnQ("박길동",9);
	q.EnQ("성길동",10);
	cout<<endl<<endl;
	fprintf(stdout,"             ********대기중인 고객********\n");
	q.Print();

	n=q.DeQ();//큐값을 가져오기
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		cout<<endl;
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.\n",n->name,n->w_time);
		delete n;
	}
	n=q.DeQ();//큐값을 가져오기
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.\n",n->name,n->w_time);
		delete n;
	}	
	n=q.DeQ();//큐값을 가져오기
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.\n",n->name,n->w_time);
		delete n;
	}
	n=q.DeQ();//큐값을 가져오기
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.\n",n->name,n->w_time);
		delete n;
	}
	n=q.DeQ();//큐값을 가져오기
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.\n",n->name,n->w_time);
		delete n;
	}

	q.Print();

	n=q.DeQ();//큐값을 가져오기
	if(n!=NULL)//큐가 비어있지 않을경우
	{
		fprintf(stdout,"%10s 고객님을 %3f분동안 서비스하였습니다.\n",n->name,n->w_time);
		delete n;
		
	}

}