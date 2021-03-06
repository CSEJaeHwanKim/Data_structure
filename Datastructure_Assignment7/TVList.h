#pragma once
#include "TVNode.h"
#include <iostream>

class CTVList
{
public:
	//CTVNode* m_head;
	CTVNode	m_org;		// m_org.m_next 가 header 포인터임

	CTVList(void);
	~CTVList(void);

	bool IsEmpty()	
	{ 
		return ( Head() == NULL ); 
	}
	CTVNode *Head()		
	{ 
		return m_org.m_next; 
	}
	CTVNode *Tail()		
	{ 
		if( IsEmpty() ) return NULL;
		CTVNode *n;
		for( n = Head() ; n->m_next != NULL ; n=n->m_next ) ; 
		return n;
	}
	int	GetLength()	// ::= 리스트의 길이를 구한다. 
	{ 
		int len = 0;
		for( CTVNode *n = Head() ; n != NULL ; n=n->m_next )
			len++; 
		return len;
	}
	void Display()	// ::= 리스트의 모든 요소를 표시한다. 
	{
		printf(" TV 채널의 갯수 = %d\n", GetLength() );
		if( !IsEmpty() )
			Head()->PrintAll();
	}
	void Clear()// ::= 리스트의 모든 요소를 제거한다.
	{
		while(!IsEmpty())
			m_org.DeleteNext();
	} 
	void Replace(int pos,char *name,int num,char*www)// ::= pos 위치의 요소를 item로 바꾼다.
	{
		CTVNode*n=GetEntry(pos);
		if(n!=NULL){n->Set(name,num,www);}
	}
	void AddTail()// ::= 맨끝에 요소를 추가한다.
	{
		if(IsEmpty())return ;
		CTVNode*n;
		for(n=Head();n->m_next!=NULL;n=n->m_next)
		return ;
	}

	void AddHead(CTVNode*n)// ::= 맨끝에 요소를 추가한다.
	{
		n->m_next=m_org.m_next;
		m_org.m_next=n;
	}
	void Add(int pos, CTVNode*n)// ::= pos 위치에 요소를 추가한다.
	{
		CTVNode *p=Head();
		int i=0;
		while(pos!=++i)
		{
			p=p->m_next;
			n->m_next=p->m_next;
			p->m_next=n;
		}
   
	}
	CTVNode *FindName(char* name) //::= name이 리스트안에 있는지를 검사한다.
	{
		if( IsEmpty() ){return NULL;}
		CTVNode *n=m_org.m_next;
		for( n = Head() ; n!= NULL ; n=n->m_next ) 
		{
			if(strcmp(n->m_name,name)==0)
				return n;
		}
		
	}
	void Delete(int pos)// ::= pos 위치의 요소를 제거한다. 
	{
		CTVNode*n=m_org.m_next;
		CTVNode*temp;
		if(pos<0||pos>=GetLength())
		{
			//m_org.m_next=NULL;
		return ;
		}
		else if(GetLength()==1)
		{
			delete m_org.m_next;
			m_org.m_next=NULL;
		}
		else
		{
			for(int i=1;i<=pos-1;i++)
			{ 
				n=n->m_next;
			}
			temp=n->m_next;
			n->m_next=n->m_next->m_next;
			
		}
		delete temp;
	}
	
	CTVNode* GetEntry(int pos)// ::= pos 위치의 요소를 반환한다. 
	{
		CTVNode*n=m_org.m_next;
		if(pos<0||pos>=GetLength())
		{
			return NULL;
		}
		else
		{
			for(int i=1;i<=pos;i++)
			{ 
				n=n->m_next;
			}
		}
		return n;
	}

};
