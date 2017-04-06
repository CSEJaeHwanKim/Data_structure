#pragma once
#include "KJHNode.h"
#include <iostream>
using namespace std;
class CKJHTree//트리 생성
{
public:
	CKJHNode *m_root;//root
	CKJHTree(void);
	~CKJHTree(void);
	void Insert(int data)//삽입
	{
		CKJHNode *n=new CKJHNode(data);
		if(m_root==NULL)
			m_root=n;
		else
			m_root->Add(n);
	}
	int GetHeight()//높이를 얻기위한 함수
	{
		if(m_root==NULL)return 0;
		else return m_root->Height();
	}
	int GetCount()//노드의 수를 얻기위한 함수
	{
		if(m_root==NULL)return 0;
		else return m_root->Count();
	}
	void PrintInOrder()//중위 표기 프린트
	{
		if(m_root!=NULL)
			m_root->InOrder();
			cout<<endl;
	}
	void PrintPreOrder()//전위 표기
	{
		if(m_root!=NULL) 
			m_root->PreOrder();
			cout<<endl;
	}
	void PrintPostOrder()//후위 표기
	{
		if(m_root!=NULL)
			m_root->PostOrder();
			cout<<endl;
	}
};

