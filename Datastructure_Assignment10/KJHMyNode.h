#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class CKJHMyNode//���class�� ����
{
public:

	CKJHMyNode* m_next; // ���� �׸� ����Ŵ.
	CKJHMyNode* m_pre; // ���� �׸� ����Ŵ.
	
	char name[100];	//�� �̸�
	float w_time;	//���� ��ٸ� �ð�

	CKJHMyNode(void);
	CKJHMyNode(char *name,int w_time)//������ �Լ��� �̸��� ���� �Է�
	{
		strcpy(this->name,name);
		this->w_time=w_time;
	}
	~CKJHMyNode(void);

	void Print()//name w_time ->Print()�Լ�
	{
		fprintf(stdout,"%10s ������ %3f ���� �ð��� �ɸ��ʴϴ�\n",name,w_time);
	}

	void add(CKJHMyNode* n)//ť�� ��� ����
	{
		m_next=n;//add�� next�� b�� �ּҰ��� ����
		n->m_pre=this;//b�� pre�ּҰ��� add(this)�� �ּҰ��� ���� 
		n->m_next=NULL;//b�� next�ּҰ����� NULL����
	}

};