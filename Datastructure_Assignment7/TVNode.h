#pragma once
#include "TVChannel.h"

class CTVNode
	: public CTVChannel
{
public:
	CTVNode		*m_next;	// 링크 멤버

	CTVNode(void)	{ m_next = NULL; }
	~CTVNode(void)	{ }

	CTVNode( char *name, int num, char *www="http://없음" )
		: CTVChannel( name, num, www) { m_next = NULL; }

	CTVNode*	Next()	{ return m_next; }

	// 자... 이제부터 링크 필드를 처리함... 중요...
	void	AddNext ( CTVNode *node ){
		node->m_next = m_next;	// (1)
		m_next = node;			// (2)
	}
	void	DeleteNext ( )
	{
		if( m_next != NULL )
		{
			CTVNode *n = m_next;
			m_next = n->m_next;
			delete n;
		}
	}

	void PrintAll() {
		Print();
		if( m_next != NULL ) 
			m_next->PrintAll();
	}


};
