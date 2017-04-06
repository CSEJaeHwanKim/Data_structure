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
	void Delete(int val)//노드 삭제
	{
		//case:1==>단말 노드일 경우
		if(m_root==NULL)return ;
		//case:2==> 한쪽의 노드만 가지고 있을 경우
		CKJHNode*n=m_root->Search(val);
		if(n==NULL)return ;
		if (n->IsTerminal())//양쪽다 없을경우
		{
			if(n->m_parent == NULL)//root노드를 없앨경우NULL반환하고 노드 삭제
			{
				m_root=NULL;
				delete n;
			}
			else 
			{
				if(n->IsLeft())//왼쪽NULL반환
					n->m_parent->m_left=NULL;
				else if(n->IsRight())//오른쪽 NULL반환
					n->m_parent->m_right=NULL;
				delete n;//노드 삭제
			}
			return ;
		}
		else if (n->NoRight())//오른쪽이 없을 경우
		{
			if(n->m_parent == NULL)//root노드를 없앨경우NULL반환하고 노드 삭제
			{ 
				m_root = n->m_left;//오른쪽이 없으므로 왼쪽을 가르킨다
				n->m_left->m_parent = NULL;//왼쪽 NULL
				delete n;
			}
			else//NULL이 아닐경우
			{
				n->m_left->m_parent=n->m_parent;//왼쪽을 가르키게한다
				if(n->IsLeft())//왼쪽의 왼쪽
				{
					n->m_parent->m_left=n->m_left;
				}
				else//왼쪽의 오른쪽
				{
					n->m_parent->m_right=n->m_left;
				}
				delete n;
			}
		}
		else if (n->NoLeft())//왼쪽이 없을경우 즉 오른쪽을 가리킨다
		{
			if(n->m_parent == NULL)//루트가 NULL일경우
			{ 
				m_root =n->m_right;//왼쪽이 없으므로 오른쪽을 가리킨다
				n->m_right->m_parent = NULL;//오른쪽 NULL대입
				delete n;//노드 삭제
			}
			else//NULL이 아닐겨우
			{
				n->m_right->m_parent=n->m_parent;//오른쪽 노드/
				if(n->IsLeft())//오른쪽 노드의 왼쪽
				{
					n->m_parent->m_left=n->m_right;
				}
				else//오른쪽 노드의 오른쪽
				{
					n->m_parent->m_right=n->m_right;
				}
				delete n;
			}
		}
		//case:3==>양쪽의 노드를 가지고 있을 경우
		else
		{
			CKJHNode *n1=n->m_right->GetMinNode();//오른쪽일 경우이므로 말단 노드들중의 가장 작은 값을 가져온다
			if(n1->IsLeft())//왼쪽이 있을경우
			{
				n1->m_parent->m_left=n1->m_right;
			}
			else//오른쪽이 있을경우
			{
				n1->m_parent->m_right=n1->m_right;
			}
			if(n1->m_right!=NULL)//오른쪽이 NULL이 아닐경우
			{
				n1->m_right->m_parent=n1->m_parent;
			}
			n->m_data=n1->m_data;//값을 변경 해준다
			delete n1;//노드 삭제
		}
		
	}
	CKJHNode *Search(int val)//노드 탐색
	{
		if(m_root!=NULL)//root즉 조사이 널이 아닐경우 찾기
			return m_root->Search(val);
		else//root가 NULL일경우 NULL반환
			return NULL;
	}
};

