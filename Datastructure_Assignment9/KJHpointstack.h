#include <stdio.h>
#include <stdlib.h>

struct CKJH2DPoint//이차원 배열 
{
	int		x;
	int		y;
	CKJH2DPoint ( int xx=0, int yy=0 ) 
	{
		x = xx; 
		y = yy;
	}
	bool operator==( CKJH2DPoint &p )
	{
		return (p.x==x && p.y==y);
	}
	bool isNeighbor( CKJH2DPoint &p ) 
	{
		int dx = (x > p.x) ? (x - p.x) : (p.x - x); 
		int dy = (y > p.y) ? (y - p.y) : (p.y - y); 
		return ((dx+dy) == 1);
	}
};
class CKJHPointStack
{
public:
	CKJH2DPoint	m_path[10000];
	int			m_top;

	CKJHPointStack(void)	{ m_top = 0; }
	~CKJHPointStack(void)	{ }
	bool isEmpty() { return m_top==0 ; }

	void push( int x, int y ) 
	{
		push( CKJH2DPoint( x, y ) );
	}
	void push( CKJH2DPoint &pt ) //스택에 push
	{
		m_path[m_top++] = pt;
	}
	CKJH2DPoint* pop () //스택에서 pop
	{
		if( m_top==0 ) return NULL;
		else  return &m_path[--m_top];
	}
	CKJH2DPoint* peek () // ???
	{
		if( m_top==0 ) return NULL;
		else  return &m_path[m_top-1];
	}
};
