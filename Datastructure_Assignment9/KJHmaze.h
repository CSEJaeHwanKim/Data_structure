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
	int		m_w;			// 미로의 width
	int		m_h;			// 미로의 height
	int**	m_elem;			// 미로의 각 항목 값을 저장	
	CKJHPointStack	m_stack;	// 미로 탐색을 위한 스택
	CKJH2DPoint	m_start;	// 미로의 입구
	CKJH2DPoint	m_exit;		// 미로의 출구

	CKJHMaze(void);
	~CKJHMaze(void);
	void Init(int w, int h) // 이차원 배열 할당
	{	
		m_h = h;
		m_w = w;
		m_elem = new int* [ m_h ];
		for (int i=0 ; i<m_h ; i++ )
			m_elem[i] = new int[m_w];
	}
	bool isValidPos( int x, int y ) // 현재 위치가 미로 내인가?
	{	
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos( int x, int y ) // 현재 위치가 출구인가?
	{	
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos( int x, int y ) // 갈수 있는 길인가?
	{
		return (m_elem[y][x] == T_EMPTY);
	}

	void Load( char *fname = NULL );	// 파일/키보드 에서 Maze정보를 읽어옴
	void Print(char *fname = NULL );	// 현재 Maze를 파일/화면에 저장
	void setBeginEnd();				// 입출구 설정 및 스택 초기화
	void searchExit();				// 미로찾기 시작


	/*// 보너스... 최적경로 추출을 위한 데이터 및 함수들...
	CPointStack m_optimal;	// 최적 경로 저장을 위한 스택
	void addOptimalPath (C2DPoint &pt);
	void PrintOptimal( );*/
};
