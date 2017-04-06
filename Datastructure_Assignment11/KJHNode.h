#pragma once
#include<iostream>
using namespace std;
class CKJHNode//노드 생성
{
public:
	int m_data;//노드에 들어갈 데이터값 
	CKJHNode *m_left;//왼쪽
	CKJHNode *m_right;//오른쪽
	CKJHNode(int data=0);//생성자 함수를 통한 값의 초기화
	~CKJHNode(void);
	int Height()//높이
	{
		int height1=0;
		int height2=0; 
		if(m_left!=NULL&&m_right!=NULL)//왼쪽과 오른쪽이 비어있지 않을경우
		{
			height1=1+m_left->Height();//height1에 왼쪽의 값 저장
			height2=1+m_right->Height();//height2에 오른쪽 값 저장
			if(height1<height2)//값의 비교를 통해 높이는 더 큰값이 나오게한다
			{
				return height2;
			}
			else
			{
				return height1;
			}
			
		}
		else if(m_left!=NULL)//왼쪽에 숫자가 존재할경우
		{
			height1=1+m_left->Height();
			return height1;
		}
		else if(m_right!=NULL)//오른쪽에 숫자가 존재할경우
		{
			height2=1+m_right->Height();
			return height2;
		}
		else// 왼쪽 오른쪽 아무것도 없는 NULL일경우 1반환
			return 1;
	}
	int Count()// 노드의 수를 세기 위한 함수
	{
		int count=0;
		if(m_left!=NULL&&m_right!=NULL)//왼쪽 오른쪽이 전부 존재할때
		{
			count=1+m_left->Count()+m_right->Count();//왼쪽+오른쪽+1
			return count;
		}
			
		else if(m_left!=NULL)//왼쪽이 존재할때
		{
			count=1+m_left->Count();
			return count;
		}
		else if(m_right!=NULL)//오른쪽이 존재할때
		{
			count=1+m_right->Count();
			return count;
		}
		else //아무것도 없을때
			return 1;
	}
	
			
	void InOrder()//중위표기
	{
		if(m_left!=NULL)//왼쪽
		{
			m_left->InOrder();
		}

		printf("%d ",m_data);//중간

		if(m_right!=NULL)//오른쪽
		{
			m_right->InOrder();
		}
		
	}
	void PreOrder()//전위표기
	{
		printf("%d ",m_data);//root
		if(m_left!=NULL)//왼쪽
		{
			m_left->PreOrder();
		}
		if(m_right!=NULL)//오른쪽
		{
			m_right->PreOrder();
		}
		
	}
	void PostOrder()//후의표기
	{
		if(m_left!=NULL)//왼쪽
		{
			m_left->PostOrder();
		}
		if(m_right!=NULL)//오른쪽
		{
			m_right->PostOrder();
		}
		printf("%d ",m_data);//root
		
	}
	void Add(CKJHNode*n)//add
	{
		if (n->m_data<m_data)//왼쪽
		{
			if(m_left==NULL)
				m_left=n;
			else 
				m_left->Add(n);
		}
		else //오른쪽
		{
			if(m_right==NULL)
				m_right=n;
			else 
				m_right->Add(n);
		}
	}
};

