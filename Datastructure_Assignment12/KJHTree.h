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
	void Delete(int val)//��� ����
	{
		//case:1==>�ܸ� ����� ���
		if(m_root==NULL)return ;
		//case:2==> ������ ��常 ������ ���� ���
		CKJHNode*n=m_root->Search(val);
		if(n==NULL)return ;
		if (n->IsTerminal())//���ʴ� �������
		{
			if(n->m_parent == NULL)//root��带 ���ٰ��NULL��ȯ�ϰ� ��� ����
			{
				m_root=NULL;
				delete n;
			}
			else 
			{
				if(n->IsLeft())//����NULL��ȯ
					n->m_parent->m_left=NULL;
				else if(n->IsRight())//������ NULL��ȯ
					n->m_parent->m_right=NULL;
				delete n;//��� ����
			}
			return ;
		}
		else if (n->NoRight())//�������� ���� ���
		{
			if(n->m_parent == NULL)//root��带 ���ٰ��NULL��ȯ�ϰ� ��� ����
			{ 
				m_root = n->m_left;//�������� �����Ƿ� ������ ����Ų��
				n->m_left->m_parent = NULL;//���� NULL
				delete n;
			}
			else//NULL�� �ƴҰ��
			{
				n->m_left->m_parent=n->m_parent;//������ ����Ű���Ѵ�
				if(n->IsLeft())//������ ����
				{
					n->m_parent->m_left=n->m_left;
				}
				else//������ ������
				{
					n->m_parent->m_right=n->m_left;
				}
				delete n;
			}
		}
		else if (n->NoLeft())//������ ������� �� �������� ����Ų��
		{
			if(n->m_parent == NULL)//��Ʈ�� NULL�ϰ��
			{ 
				m_root =n->m_right;//������ �����Ƿ� �������� ����Ų��
				n->m_right->m_parent = NULL;//������ NULL����
				delete n;//��� ����
			}
			else//NULL�� �ƴҰܿ�
			{
				n->m_right->m_parent=n->m_parent;//������ ���/
				if(n->IsLeft())//������ ����� ����
				{
					n->m_parent->m_left=n->m_right;
				}
				else//������ ����� ������
				{
					n->m_parent->m_right=n->m_right;
				}
				delete n;
			}
		}
		//case:3==>������ ��带 ������ ���� ���
		else
		{
			CKJHNode *n1=n->m_right->GetMinNode();//�������� ����̹Ƿ� ���� �������� ���� ���� ���� �����´�
			if(n1->IsLeft())//������ �������
			{
				n1->m_parent->m_left=n1->m_right;
			}
			else//�������� �������
			{
				n1->m_parent->m_right=n1->m_right;
			}
			if(n1->m_right!=NULL)//�������� NULL�� �ƴҰ��
			{
				n1->m_right->m_parent=n1->m_parent;
			}
			n->m_data=n1->m_data;//���� ���� ���ش�
			delete n1;//��� ����
		}
		
	}
	CKJHNode *Search(int val)//��� Ž��
	{
		if(m_root!=NULL)//root�� ������ ���� �ƴҰ�� ã��
			return m_root->Search(val);
		else//root�� NULL�ϰ�� NULL��ȯ
			return NULL;
	}
};

