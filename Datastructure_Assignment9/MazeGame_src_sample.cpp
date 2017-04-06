//======================================================
//======================================================
// main() 함수
//======================================================
//======================================================
#include "Maze.h"

void main()
{
	CMaze	maze;

	maze.Load("maze1.txt");
	maze.Print();
	printf( " 엔터를 치면 미로 입구 ○에서 출구 ◎로 가는 경로찾기를 시작합니다.\n");
	getchar();

	maze.searchExit();
	maze.Print();
	printf( " 과제는 일단 여기까지입니다. 다음은 보너스 항목입니다.\n\n");
	printf( " 엔터를 치면 탐색한 경로 □중에서 최적 경로 ☆를 출력합니다.\n");
	getchar();

	//maze.PrintOptimal( );
	//maze.Print();
	//getchar();
}

//======================================================
//======================================================
// Point 클래스와 Stack 클래스
//======================================================
//======================================================
#include <stdio.h>
#include <stdlib.h>

struct C2DPoint {
	int		x;
	int		y;
	C2DPoint ( int xx=0, int yy=0 ) {
		x = xx; 
		y = yy;
	}
	bool operator==( C2DPoint &p ) {
		return (p.x==x && p.y==y);
	}
	bool isNeighbor( C2DPoint &p ) {
		int dx = (x > p.x) ? (x - p.x) : (p.x - x); 
		int dy = (y > p.y) ? (y - p.y) : (p.y - y); 
		return ((dx+dy) == 1);
	}
};
class CPointStack
{
public:
	C2DPoint	m_path[10000];
	int			m_top;

	CPointStack(void)	{ m_top = 0; }
	~CPointStack(void)	{ }
	bool isEmpty() { return m_top==0 ; }

	void push( int x, int y ) {
		push( C2DPoint( x, y ) );
	}
	void push( C2DPoint &pt ) {
		m_path[m_top++] = pt;
	}
	C2DPoint* pop () {
		if( m_top==0 ) return NULL;
		else  return &m_path[--m_top];
	}
	C2DPoint* peek () {
		if( m_top==0 ) return NULL;
		else  return &m_path[m_top-1];
	}
};

//======================================================
//======================================================
// 미로 클래스 (...h)
//======================================================
//======================================================
#include "PointStack.h"
#define	T_WALL	0
#define	T_START	5
#define	T_EXIT	9
#define	T_EMPTY	1
#define	T_DONE	2
#define	T_OPTIMAL 8

class CMaze
{
public:
	// Member Data
	int		m_w;			// 미로의 width
	int		m_h;			// 미로의 height
	int**	m_elem;			// 미로의 각 항목 값을 저장	
	CPointStack	m_stack;	// 미로 탐색을 위한 스택
	C2DPoint	m_start;	// 미로의 입구
	C2DPoint	m_exit;		// 미로의 출구

	CMaze(void);
	~CMaze(void);
	void	Init(int w, int h) {	// 이차원 배열 할당
		m_h = h;
		m_w = w;
		m_elem = new int* [ m_h ];
		for (int i=0 ; i<m_h ; i++ )
			m_elem[i] = new int[m_w];
	}
	bool isValidPos( int x, int y ) {	// 현재 위치가 미로 내인가?
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos( int x, int y ) {	// 현재 위치가 출구인가?
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos( int x, int y ) {// 갈수 있는 길인가?
		return (m_elem[y][x] == T_EMPTY);
	}

	void Load( char *fname = NULL );	// 파일/키보드 에서 Maze정보를 읽어옴
	void Print(char *fname = NULL );	// 현재 Maze를 파일/화면에 저장
	void setBeginEnd();				// 입출구 설정 및 스택 초기화
	void searchExit();				// 미로찾기 시작


	// 보너스... 최적경로 추출을 위한 데이터 및 함수들...
	CPointStack m_optimal;	// 최적 경로 저장을 위한 스택
	void addOptimalPath (C2DPoint &pt);
	void PrintOptimal( );
};

//======================================================
//======================================================
// 미로 클래스 (...cpp)
//======================================================
//======================================================
#include "Maze.h"
CMaze::CMaze(void)
{
	Init( 0, 0 );
}
CMaze::~CMaze(void)
{
	// 메모리 동적 해제 코드를 추가하시오.
	...
	...
	...
}

// 시작과 끝 위치를 찾아 저장 (m_start, m_exit)
void CMaze::setBeginEnd()
{
	for( int i=0 ; i<m_h ; i++ )
	for( int j=0 ; j<m_w ; j++ ) {
		if( m_elem[i][j] == 5 )
			m_start = C2DPoint( j, i );
		else if ( m_elem[i][j] == 9 )
			m_exit = C2DPoint( j, i );
	}
	m_stack.push( m_start );
}
#include <Windows.h>
// 본격적으로 출구를 탐색하는 코드....
void CMaze::searchExit()
{
	setBeginEnd();
	...
	...
	...
}


// 파일에서 미로 정보를 읽어옴
void CMaze::Load( char *fname ){
	FILE *fp = stdin;
	if( fname != NULL ) {
		fp = fopen (fname, "r");
		if( fp == NULL ) {
			printf( " Error: %s 파일이 없습니다.\n");
			return;
		}
	}

	int w, h;
	printf( " 이미지 크기 입력 (w h): ");
	fscanf( fp, "%d%d", &w, &h );
	printf( " 이미지의 크기는 %d x %d 입니다.\n", w, h);

	Init( w, h );		// 메모리 할당

	for( int i=0 ; i<h ; i++ ) {
		for( int j=0 ; j<w ; j++ ) {
			fscanf( fp, "%d", &(m_elem[i][j]) );
		}
	}
	if( fp != stdin ) fclose(fp);
}

// 현재 미로 정보를 파일에 저장
// fname이 NULL 이면 화면에 결과를 출력함
void CMaze::Print( char *fname ) {
	FILE *fp = stdout;
	if( fname != NULL ) {
		fp = fopen (fname, "w");
		if( fp == NULL ) {
			printf( " Error: %s 파일을 만들 수 없습니다.\n");
			return;
		}
	}

	system("cls");
	printf( "=============================================\n");
	printf( "  전체 미로의 크기 = ");
	fprintf( fp, "%d %d\n", m_w, m_h);
	printf( "=============================================\n");

	for( int i=0 ; i<m_h ; i++ ) {
		for( int j=0 ; j<m_w ; j++ ) {
			switch (m_elem[i][j]) {
				case T_WALL		: fprintf( fp, "■" ); break;
				case T_START	: fprintf( fp, "○" ); break;
				case T_EXIT		: fprintf( fp, "◎" ); break;
				case T_EMPTY	: fprintf( fp, "  " ); break;
				case T_DONE		: fprintf( fp, "□" ); break;
				case T_OPTIMAL	: fprintf( fp, "☆" ); break;
			}
		}
		fprintf( fp, "\n");
	}
	printf( "=============================================\n");
	if( fp != stdout ) fclose(fp);
}


//==========================================================
// for optimal path finding
//
void CMaze::addOptimalPath (C2DPoint &pt)
{
	...
	...
	...
}
void CMaze::PrintOptimal( )
{
	...
	...
	...
}

/======================================================
//======================================================
#include "PointStack.h"
#define	T_WALL	0
#define	T_START	5
#define	T_EXIT	9
#define	T_EMPTY	1
#define	T_DONE	2
#define	T_OPTIMAL 8

class CMaze
{
public:
	// Member Data
	int		m_w;			// 미로의 width
	int		m_h;			// 미로의 height
	int**	m_elem;			// 미로의 각 항목 값을 저장	
	CPointStack	m_stack;	// 미로 탐색을 위한 스택
	C2DPoint	m_start;	// 미로의 입구
	C2DPoint	m_exit;		// 미로의 출구

	CMaze(void);
	~CMaze(void);
	void	Init(int w, int h) {	// 이차원 배열 할당
		m_h = h;
		m_w = w;
		m_elem = new int* [ m_h ];
		for (int i=0 ; i<m_h ; i++ )
			m_elem[i] = new int[m_w];
	}
	bool isValidPos( int x, int y ) {	// 현재 위치가 미로 내인가?
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos( int x, int y ) {	// 현재 위치가 출구인가?
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos( int x, int y ) {// 갈수 있는 길인가?
		return (m_elem[y][x] == T_EMPTY);
	}

	void Load( char *fname = NULL );	// 파일/키보드 에서 Maze정보를 읽어옴
	void Print(char *fname = NULL );	// 현재 Maze를 파일/화면에 저장
	void setBeginEnd();				// 입출구 설정 및 스택 초기화
	void searchExit();				// 미로찾기 시작


	// 보너스... 최적경로 추출을 위한 데이터 및 함수들...
	CPointStack m_optimal;	// 최적 경로 저장을 위한 스택
	void addOptimalPath (C2DPoint &pt);
	void PrintOptimal( );
};

//======================================================
//======================================================
// 미로 클래스 (...cpp)
//======================================================
//======================================================
#include "Maze.h"
CMaze::CMaze(void)
{
	Init( 0, 0 );
}
CMaze::~CMaze(void)
{
	// 메모리 동적 해제 코드를 추가하시오.
	...
	...
	...
}

// 시작과 끝 위치를 찾아 저장 (m_start, m_exit)
void CMaze::setBeginEnd()
{
	for( int i=0 ; i<m_h ; i++ )
	for( int j=0 ; j<m_w ; j++ ) {
		if( m_elem[i][j] == 5 )
			m_start = C2DPoint( j, i );
		else if ( m_elem[i][j] == 9 )
			m_exit = C2DPoin