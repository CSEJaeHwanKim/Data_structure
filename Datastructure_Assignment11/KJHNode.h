#pragma once
#include<iostream>
using namespace std;
class CKJHNode//��� ����
{
public:
	int m_data;//��忡 �� �����Ͱ� 
	CKJHNode *m_left;//����
	CKJHNode *m_right;//������
	CKJHNode(int data=0);//������ �Լ��� ���� ���� �ʱ�ȭ
	~CKJHNode(void);
	int Height()//����
	{
		int height1=0;
		int height2=0; 
		if(m_left!=NULL&&m_right!=NULL)//���ʰ� �������� ������� �������
		{
			height1=1+m_left->Height();//height1�� ������ �� ����
			height2=1+m_right->Height();//height2�� ������ �� ����
			if(height1<height2)//���� �񱳸� ���� ���̴� �� ū���� �������Ѵ�
			{
				return height2;
			}
			else
			{
				return height1;
			}
			
		}
		else if(m_left!=NULL)//���ʿ� ���ڰ� �����Ұ��
		{
			height1=1+m_left->Height();
			return height1;
		}
		else if(m_right!=NULL)//�����ʿ� ���ڰ� �����Ұ��
		{
			height2=1+m_right->Height();
			return height2;
		}
		else// ���� ������ �ƹ��͵� ���� NULL�ϰ�� 1��ȯ
			return 1;
	}
	int Count()// ����� ���� ���� ���� �Լ�
	{
		int count=0;
		if(m_left!=NULL&&m_right!=NULL)//���� �������� ���� �����Ҷ�
		{
			count=1+m_left->Count()+m_right->Count();//����+������+1
			return count;
		}
			
		else if(m_left!=NULL)//������ �����Ҷ�
		{
			count=1+m_left->Count();
			return count;
		}
		else if(m_right!=NULL)//�������� �����Ҷ�
		{
			count=1+m_right->Count();
			return count;
		}
		else //�ƹ��͵� ������
			return 1;
	}
	
			
	void InOrder()//����ǥ��
	{
		if(m_left!=NULL)//����
		{
			m_left->InOrder();
		}

		printf("%d ",m_data);//�߰�

		if(m_right!=NULL)//������
		{
			m_right->InOrder();
		}
		
	}
	void PreOrder()//����ǥ��
	{
		printf("%d ",m_data);//root
		if(m_left!=NULL)//����
		{
			m_left->PreOrder();
		}
		if(m_right!=NULL)//������
		{
			m_right->PreOrder();
		}
		
	}
	void PostOrder()//����ǥ��
	{
		if(m_left!=NULL)//����
		{
			m_left->PostOrder();
		}
		if(m_right!=NULL)//������
		{
			m_right->PostOrder();
		}
		printf("%d ",m_data);//root
		
	}
	void Add(CKJHNode*n)//add
	{
		if (n->m_data<m_data)//����
		{
			if(m_left==NULL)
				m_left=n;
			else 
				m_left->Add(n);
		}
		else //������
		{
			if(m_right==NULL)
				m_right=n;
			else 
				m_right->Add(n);
		}
	}
};

