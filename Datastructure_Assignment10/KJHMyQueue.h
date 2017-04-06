#pragma once
#include"KJHMyNode.h"

class CKJHMyQueue//ť ����
{
public:
	
	CKJHMyNode* front; //DeQ�� ��� ��ȯ
	CKJHMyNode* rear;//EnQ�� ��� ��ȯ
	CKJHMyQueue(void);
	~CKJHMyQueue(void);
		
	bool isEmpty()//ť�� ���������� NULL��ȯ
	{
		return front==NULL;//=={return nNodes==0;}
	}

	void EnQ(CKJHMyNode* n)//ť ����
	{
		if(isEmpty())//����������
		{
			front=rear=n;//front��rear�� �������
		}
		else
		{
			rear->add(n);
			rear=n;
		}
	}

	void EnQ(char *name,int count)//ť�� name,w_time�� ���� ���� ���� ���
	{
		CKJHMyNode *n=new CKJHMyNode(name,count);
		EnQ(n);
	}

	CKJHMyNode* DeQ()//ť ����
	{
		if(isEmpty())//���������� NULL��ȯ
		{
			return NULL;
		}
		else//��� ���� ������� ť�� ����Ǿ��ִ� �� ��ȯ 
		{
			CKJHMyNode *temp=front;
			front=front->m_next;
			return temp;
		}
		
	}
	
	void Print()//ť�� ���� �Ǿ��ִ°� �ҷ����� ���� ���
	{
		fprintf(stdout,"             *****���� ��� ���� ��*****\n");
		for(CKJHMyNode *n=front;n!=NULL;n=n->m_next)
			n->Print();
	}
};
