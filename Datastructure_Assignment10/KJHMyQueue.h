#pragma once
#include"KJHMyNode.h"

class CKJHMyQueue//큐 생성
{
public:
	
	CKJHMyNode* front; //DeQ시 노드 반환
	CKJHMyNode* rear;//EnQ시 노드 반환
	CKJHMyQueue(void);
	~CKJHMyQueue(void);
		
	bool isEmpty()//큐가 비어있을경우 NULL반환
	{
		return front==NULL;//=={return nNodes==0;}
	}

	void EnQ(CKJHMyNode* n)//큐 생성
	{
		if(isEmpty())//비어있을경우
		{
			front=rear=n;//front와rear가 같을경우
		}
		else
		{
			rear->add(n);
			rear=n;
		}
	}

	void EnQ(char *name,int count)//큐의 name,w_time을 가져 오기 위해 사용
	{
		CKJHMyNode *n=new CKJHMyNode(name,count);
		EnQ(n);
	}

	CKJHMyNode* DeQ()//큐 삭제
	{
		if(isEmpty())//비어있을경우 NULL반환
		{
			return NULL;
		}
		else//비어 있지 않을경우 큐에 저장되어있는 값 반환 
		{
			CKJHMyNode *temp=front;
			front=front->m_next;
			return temp;
		}
		
	}
	
	void Print()//큐에 저장 되어있는값 불러오기 위해 사용
	{
		fprintf(stdout,"             *****현재 대기 중인 고객*****\n");
		for(CKJHMyNode *n=front;n!=NULL;n=n->m_next)
			n->Print();
	}
};
