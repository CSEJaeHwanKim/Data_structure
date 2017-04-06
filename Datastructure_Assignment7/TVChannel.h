#pragma once
#include <stdio.h>
#include <string.h>


class CTVChannel
{
public:
	// ������ ���
	char	m_name[40];		// ä�� �̸�
	int		m_number;		// ä�� ��ȣ
	char	m_www[100];		// �ش� ä���� Ȩ������ �ּ�

	CTVChannel(void);
	~CTVChannel(void);

	CTVChannel( char *name, int num, char *www="http://����" ) {
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
