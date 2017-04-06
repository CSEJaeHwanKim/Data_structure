#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class CKJHMyNode//노드class스 생성
{
public:

	CKJHMyNode* m_next; // 다음 항목 가리킴.
	CKJHMyNode* m_pre; // 이전 항목 가리킴.
	
	char name[100];	//고객 이름
	float w_time;	//고객이 기다린 시간

	CKJHMyNode(void);
	CKJHMyNode(char *name,int w_time)//생성자 함수로 이름과 고객을 입력
	{
		strcpy(this->name,name);
		this->w_time=w_time;
	}
	~CKJHMyNode(void);

	void Print()//name w_time ->Print()함수
	{
		fprintf(stdout,"%10s 고객님은 %3f 분의 시간이 걸리십니다\n",name,w_time);
	}

	void add(CKJHMyNode* n)//큐의 노드 생성
	{
		m_next=n;//add의 next와 b의 주소값을 연결
		n->m_pre=this;//b의 pre주소값과 add(this)의 주소값을 연결 
		n->m_next=NULL;//b의 next주소값에는 NULL저장
	}

};