#pragma once
#include "TVChannel.h"

class CTVNode
	: public CTVChannel
{
public:
	CTVNode		*m_next;	// ��ũ ���

	CTVNode(void)	{ m_next = NULL; }
	~CTVNode(void)	{ }

	CTVNode( char *name, int num, char *www="http://����" )
		: CTVChannel( name, num, www) { m_next = NULL; }

	CTVNode*	Next()	{ return m_next; }

	// ��... �������� ��ũ �ʵ带 ó����... �߿�...
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
