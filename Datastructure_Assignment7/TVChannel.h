#pragma once
#include <stdio.h>
#include <string.h>


class CTVChannel
{
public:
	// 데이터 멤버
	char	m_name[40];		// 채널 이름
	int		m_number;		// 채널 번호
	char	m_www[100];		// 해당 채널의 홈페이지 주소

	CTVChannel(void);
	~CTVChannel(void);

	CTVChannel( char *name, int num, char *www="http://없음" ) {
		Set( name, num, www );
	}
	void Set( char *name, int num, char *www ) {
		strcpy( m_name, name );
		m_number = num;	
		strcpy( m_www, www );
	}

	void Print() {
		printf(" %8s\t [%3d]  homepage=%s\n", m_name, m_number, m_www );
	}
	char*	GetName()		{ return m_name; }
	int		GetNumber()		{ return m_number; }
	char*	GetWWW()		{ return m_www; }
	bool	IsInRange(int min, int max) { return (m_number>=min && m_number<=max); }
};
