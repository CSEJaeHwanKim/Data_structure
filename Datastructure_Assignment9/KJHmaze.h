#include "KJHpointstack.h"
#define	T_WALL	0
#define	T_START	5
#define	T_EXIT	9
#define	T_EMPTY	1
#define	T_DONE	2
#define	T_OPTIMAL 8

class CKJHMaze
{
public:
	// Member Data
	int		m_w;			// �̷��� width
	int		m_h;			// �̷��� height
	int**	m_elem;			// �̷��� �� �׸� ���� ����	
	CKJHPointStack	m_stack;	// �̷� Ž���� ���� ����
	CKJH2DPoint	m_start;	// �̷��� �Ա�
	CKJH2DPoint	m_exit;		// �̷��� �ⱸ

	CKJHMaze(void);
	~CKJHMaze(void);
	void Init(int w, int h) // ������ �迭 �Ҵ�
	{	
		m_h = h;
		m_w = w;
		m_elem = new int* [ m_h ];
		for (int i=0 ; i<m_h ; i++ )
			m_elem[i] = new int[m_w];
	}
	bool isValidPos( int x, int y ) // ���� ��ġ�� �̷� ���ΰ�?
	{	
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos( int x, int y ) // ���� ��ġ�� �ⱸ�ΰ�?
	{	
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos( int x, int y ) // ���� �ִ� ���ΰ�?
	{
		return (m_elem[y][x] == T_EMPTY);
	}

	void Load( char *fname = NULL );	// ����/Ű���� ���� Maze������ �о��
	void Print(char *fname = NULL );	// ���� Maze�� ����/ȭ�鿡 ����
	void setBeginEnd();				// ���ⱸ ���� �� ���� �ʱ�ȭ
	void searchExit();				// �̷�ã�� ����


	/*// ���ʽ�... ������� ������ ���� ������ �� �Լ���...
	CPointStack m_optimal;	// ���� ��� ������ ���� ����
	void addOptimalPath (C2DPoint &pt);
	void PrintOptimal( );*/
};
