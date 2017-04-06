//======================================================
//======================================================
// main() �Լ�
//======================================================
//======================================================
#include "Maze.h"

void main()
{
	CMaze	maze;

	maze.Load("maze1.txt");
	maze.Print();
	printf( " ���͸� ġ�� �̷� �Ա� �ۿ��� �ⱸ �ݷ� ���� ���ã�⸦ �����մϴ�.\n");
	getchar();

	maze.searchExit();
	maze.Print();
	printf( " ������ �ϴ� ��������Դϴ�. ������ ���ʽ� �׸��Դϴ�.\n\n");
	printf( " ���͸� ġ�� Ž���� ��� ���߿��� ���� ��� �ٸ� ����մϴ�.\n");
	getchar();

	//maze.PrintOptimal( );
	//maze.Print();
	//getchar();
}

//======================================================
//======================================================
// Point Ŭ������ Stack Ŭ����
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
// �̷� Ŭ���� (...h)
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
	int		m_w;			// �̷��� width
	int		m_h;			// �̷��� height
	int**	m_elem;			// �̷��� �� �׸� ���� ����	
	CPointStack	m_stack;	// �̷� Ž���� ���� ����
	C2DPoint	m_start;	// �̷��� �Ա�
	C2DPoint	m_exit;		// �̷��� �ⱸ

	CMaze(void);
	~CMaze(void);
	void	Init(int w, int h) {	// ������ �迭 �Ҵ�
		m_h = h;
		m_w = w;
		m_elem = new int* [ m_h ];
		for (int i=0 ; i<m_h ; i++ )
			m_elem[i] = new int[m_w];
	}
	bool isValidPos( int x, int y ) {	// ���� ��ġ�� �̷� ���ΰ�?
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos( int x, int y ) {	// ���� ��ġ�� �ⱸ�ΰ�?
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos( int x, int y ) {// ���� �ִ� ���ΰ�?
		return (m_elem[y][x] == T_EMPTY);
	}

	void Load( char *fname = NULL );	// ����/Ű���� ���� Maze������ �о��
	void Print(char *fname = NULL );	// ���� Maze�� ����/ȭ�鿡 ����
	void setBeginEnd();				// ���ⱸ ���� �� ���� �ʱ�ȭ
	void searchExit();				// �̷�ã�� ����


	// ���ʽ�... ������� ������ ���� ������ �� �Լ���...
	CPointStack m_optimal;	// ���� ��� ������ ���� ����
	void addOptimalPath (C2DPoint &pt);
	void PrintOptimal( );
};

//======================================================
//======================================================
// �̷� Ŭ���� (...cpp)
//======================================================
//======================================================
#include "Maze.h"
CMaze::CMaze(void)
{
	Init( 0, 0 );
}
CMaze::~CMaze(void)
{
	// �޸� ���� ���� �ڵ带 �߰��Ͻÿ�.
	...
	...
	...
}

// ���۰� �� ��ġ�� ã�� ���� (m_start, m_exit)
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
// ���������� �ⱸ�� Ž���ϴ� �ڵ�....
void CMaze::searchExit()
{
	setBeginEnd();
	...
	...
	...
}


// ���Ͽ��� �̷� ������ �о��
void CMaze::Load( char *fname ){
	FILE *fp = stdin;
	if( fname != NULL ) {
		fp = fopen (fname, "r");
		if( fp == NULL ) {
			printf( " Error: %s ������ �����ϴ�.\n");
			return;
		}
	}

	int w, h;
	printf( " �̹��� ũ�� �Է� (w h): ");
	fscanf( fp, "%d%d", &w, &h );
	printf( " �̹����� ũ��� %d x %d �Դϴ�.\n", w, h);

	Init( w, h );		// �޸� �Ҵ�

	for( int i=0 ; i<h ; i++ ) {
		for( int j=0 ; j<w ; j++ ) {
			fscanf( fp, "%d", &(m_elem[i][j]) );
		}
	}
	if( fp != stdin ) fclose(fp);
}

// ���� �̷� ������ ���Ͽ� ����
// fname�� NULL �̸� ȭ�鿡 ����� �����
void CMaze::Print( char *fname ) {
	FILE *fp = stdout;
	if( fname != NULL ) {
		fp = fopen (fname, "w");
		if( fp == NULL ) {
			printf( " Error: %s ������ ���� �� �����ϴ�.\n");
			return;
		}
	}

	system("cls");
	printf( "=============================================\n");
	printf( "  ��ü �̷��� ũ�� = ");
	fprintf( fp, "%d %d\n", m_w, m_h);
	printf( "=============================================\n");

	for( int i=0 ; i<m_h ; i++ ) {
		for( int j=0 ; j<m_w ; j++ ) {
			switch (m_elem[i][j]) {
				case T_WALL		: fprintf( fp, "��" ); break;
				case T_START	: fprintf( fp, "��" ); break;
				case T_EXIT		: fprintf( fp, "��" ); break;
				case T_EMPTY	: fprintf( fp, "  " ); break;
				case T_DONE		: fprintf( fp, "��" ); break;
				case T_OPTIMAL	: fprintf( fp, "��" ); break;
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
	int		m_w;			// �̷��� width
	int		m_h;			// �̷��� height
	int**	m_elem;			// �̷��� �� �׸� ���� ����	
	CPointStack	m_stack;	// �̷� Ž���� ���� ����
	C2DPoint	m_start;	// �̷��� �Ա�
	C2DPoint	m_exit;		// �̷��� �ⱸ

	CMaze(void);
	~CMaze(void);
	void	Init(int w, int h) {	// ������ �迭 �Ҵ�
		m_h = h;
		m_w = w;
		m_elem = new int* [ m_h ];
		for (int i=0 ; i<m_h ; i++ )
			m_elem[i] = new int[m_w];
	}
	bool isValidPos( int x, int y ) {	// ���� ��ġ�� �̷� ���ΰ�?
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos( int x, int y ) {	// ���� ��ġ�� �ⱸ�ΰ�?
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos( int x, int y ) {// ���� �ִ� ���ΰ�?
		return (m_elem[y][x] == T_EMPTY);
	}

	void Load( char *fname = NULL );	// ����/Ű���� ���� Maze������ �о��
	void Print(char *fname = NULL );	// ���� Maze�� ����/ȭ�鿡 ����
	void setBeginEnd();				// ���ⱸ ���� �� ���� �ʱ�ȭ
	void searchExit();				// �̷�ã�� ����


	// ���ʽ�... ������� ������ ���� ������ �� �Լ���...
	CPointStack m_optimal;	// ���� ��� ������ ���� ����
	void addOptimalPath (C2DPoint &pt);
	void PrintOptimal( );
};

//======================================================
//======================================================
// �̷� Ŭ���� (...cpp)
//======================================================
//======================================================
#include "Maze.h"
CMaze::CMaze(void)
{
	Init( 0, 0 );
}
CMaze::~CMaze(void)
{
	// �޸� ���� ���� �ڵ带 �߰��Ͻÿ�.
	...
	...
	...
}

// ���۰� �� ��ġ�� ã�� ���� (m_start, m_exit)
void CMaze::setBeginEnd()
{
	for( int i=0 ; i<m_h ; i++ )
	for( int j=0 ; j<m_w ; j++ ) {
		if( m_elem[i][j] == 5 )
			m_start = C2DPoint( j, i );
		else if ( m_elem[i][j] == 9 )
			m_exit = C2DPoin