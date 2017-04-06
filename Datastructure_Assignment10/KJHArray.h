#include <iostream>
#include "KJHMyNode.h"
#define MAX 100
using namespace std;
#pragma once

class CKJHArray//배열을 이용한 큐 클래스
{
public:
	CKJHMyNode que[MAX];//노드 클래스를 이용한 큐배열 생성(name,w_time)
	int front,rear;//Q배열의 맨앞과 뒤의 값을 나타냄
	
	CKJHArray(void);
	~CKJHArray(void);
	bool isEmpty()//큐 배열이 비어있는지 여부 판단
	{
		if(front==rear)return true;
		else return false;
	}
	bool isFull()//큐 배열이 꽉차있는지 여부 판단
	{
		if(((rear+1)%MAX)==front) return true;
		else return false;

	}
	void ArrEnQ(CKJHMyNode *q)//ArrEnQ생성
	{
		if(!isFull())//배열이 꽉차있지 않을때 노드에 있는 이름과 시간을 복사하여 저장
		{
			strcpy(que[(rear+1)%MAX].name,q->name);
			que[(rear+1)%MAX].w_time=q->w_time;
			rear=(rear+1)%MAX;
		}
		else 
		{
			printf("큐가 꽉찼습니다");
			
		}
		
	}
	void ArrEnQ1(char *name,int w_time)//큐에 저장 되어있는 값을 불러오기 위해 사용
	{
		CKJHMyNode *q=new CKJHMyNode(name,w_time);
		ArrEnQ(q);
	}
	CKJHMyNode *ArrDeQ()//큐값 삭제
	{
		if(!isEmpty())//큐가 비어있지 않을때
		{
			CKJHMyNode *temp=&que[(front+1)%MAX];
			front=(front+1)%MAX;
			return temp;
		}
		else 
		{
			return NULL;
		}
	}
	
	void Print()//Node에있는 ArrEnQ값을 출력하기 위해 지정되어있는 함수
    {
		fprintf(stdout,"             *****현재 대기 중인 고객*****\n");
        for(int i=(front+1)%MAX;i!=rear+1;i++ )
		printf(	"%10s 고객님은 %3f분의 시간이 걸리십니다\n" ,que[i].name,que[i].w_time);
    }
	
};

