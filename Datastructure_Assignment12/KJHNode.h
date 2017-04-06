#pragma once
#include<iostream>
using namespace std;
class CKJHNode//노드 생성
{
public:
	int m_data;//노드에 들어갈 데이터값 
	CKJHNode *m_parent;//부모 노드
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
			{
				m_left=n;
				n->m_parent=this;
			}
			else 
				m_left->Add(n);
		}
		else //오른쪽
		{
			if(m_right==NULL)
			{
				m_right=n;
				n->m_parent=this;
			}
			else 
				m_right->Add(n);
		}
	}
	void Removeme()//데이터 제거
	{
		if(IsLeft())//왼쪽일경우 왼쪽 NULL반환
			m_parent->m_left=NULL;
		else//오른쪽일경우 오른쪽 NULL반환
			m_parent->m_right=NULL;
	}
	CKJHNode *Search(int val)//데이터 찾기
	{
		if(val==m_data)//입력 데이터와 비교되는 노드의 값이 같을경우
		{
			printf("데이터가 있습니다\n");
			return this;
		}
		if(val<m_data )////입력 데이터보다 비교되는 노드의 값이 클경우
		{
			if(m_left!=NULL)//왼쪽에 데이터가 있는경우 왼쪽의 값을 찾는다(Search이용)
			{
				printf("데이터가 없습니다\n");
				return m_left->Search(val);
			}
			else //오른쪽에 데이터가 있는경우 NULL
			{
				printf("데이터가 없습니다\n");
				return NULL;
			}
		}
		else
			printf("데이터가 없습니다\n");
			return HasRight()?m_right->Search(val):NULL;
	}
	CKJHNode *GetMinNode(){return HasLeft()?m_left->GetMinNode():this;}//오른쪽 말단노드일경우 그값들중 가장 작은값
	CKJHNode *GetMaxNode(){return HasRight()?m_right->GetMaxNode():this;}//왼쪽 말단노드일경우 그값들중 가장 큰값
	bool HasLeft(){return m_left!=NULL;}//왼쪽을 가지고 있을경우
	bool HasRight(){return m_right!=NULL;}//오른쪽을 가지고 있을경우
	bool NoLeft(){return !HasLeft();}//왼쪽이 없을경우
	bool NoRight(){return !HasRight();}//오른쪽이 없을경우
	bool IsLeft(){return m_parent->m_left==this;}//부모->왼쪽
	bool IsRight(){return m_parent->m_right==this;}//부모->오른쪽
	bool IsTerminal(){return NoLeft()&&NoRight();}//양쪽다 없을 경우
};

