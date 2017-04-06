#pragma once
#include "KJHNode.h"
#include <iostream>
using namespace std;
class CKJHTree//Ʈ�� ����
{
public:
	CKJHNode *m_root;//root
	CKJHTree(void);
	~CKJHTree(void);
	void Insert(int data)//����
	{
		CKJHNode *n=new CKJHNode(data);
		if(m_root==NULL)
			m_root=n;
		else
			m_root->Add(n);
	}
	int GetHeight()//���̸� ������� �Լ�
	{
		if(m_root==NULL)return 0;
		else return m_root->Height();
	}
	int GetCount()//����� ���� ������� �Լ�
	{
		if(m_root==NULL)return 0;
		else return m_root->Count();
	}
	void PrintInOrder()//���� ǥ�� ����Ʈ
	{
		if(m_root!=NULL)
			m_root->InOrder();
			cout<<endl;
	}
	void PrintPreOrder()//���� ǥ��
	{
		if(m_root!=NULL) 
			m_root->PreOrder();
			cout<<endl;
	}
	void PrintPostOrder()//���� ǥ��
	{
		if(m_root!=NULL)
			m_root->PostOrder();
			cout<<endl;
	}
};

