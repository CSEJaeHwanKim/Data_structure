#include <iostream>
#include "KJHMyNode.h"
#define MAX 100
using namespace std;
#pragma once

class CKJHArray//�迭�� �̿��� ť Ŭ����
{
public:
	CKJHMyNode que[MAX];//��� Ŭ������ �̿��� ť�迭 ����(name,w_time)
	int front,rear;//Q�迭�� �Ǿհ� ���� ���� ��Ÿ��
	
	CKJHArray(void);
	~CKJHArray(void);
	bool isEmpty()//ť �迭�� ����ִ��� ���� �Ǵ�
	{
		if(front==rear)return true;
		else return false;
	}
	bool isFull()//ť �迭�� �����ִ��� ���� �Ǵ�
	{
		if(((rear+1)%MAX)==front) return true;
		else return false;

	}
	void ArrEnQ(CKJHMyNode *q)//ArrEnQ����
	{
		if(!isFull())//�迭�� �������� ������ ��忡 �ִ� �̸��� �ð��� �����Ͽ� ����
		{
			strcpy(que[(rear+1)%MAX].name,q->name);
			que[(rear+1)%MAX].w_time=q->w_time;
			rear=(rear+1)%MAX;
		}
		else 
		{
			printf("ť�� ��á���ϴ�");
			
		}
		
	}
	void ArrEnQ1(char *name,int w_time)//ť�� ���� �Ǿ��ִ� ���� �ҷ����� ���� ���
	{
		CKJHMyNode *q=new CKJHMyNode(name,w_time);
		ArrEnQ(q);
	}
	CKJHMyNode *ArrDeQ()//ť�� ����
	{
		if(!isEmpty())//ť�� ������� ������
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
	
	void Print()//Node���ִ� ArrEnQ���� ����ϱ� ���� �����Ǿ��ִ� �Լ�
    {
		fprintf(stdout,"             *****���� ��� ���� ��*****\n");
        for(int i=(front+1)%MAX;i!=rear+1;i++ )
		printf(	"%10s ������ %3f���� �ð��� �ɸ��ʴϴ�\n" ,que[i].name,que[i].w_time);
    }
	
};

