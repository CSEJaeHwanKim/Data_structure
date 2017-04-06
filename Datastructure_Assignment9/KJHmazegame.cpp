#include <iostream>
#include <Windows.h>
#include "KJHmaze.h"

CKJHMaze::CKJHMaze(void)//객체선언
{
	Init( 0, 0 );
}
CKJHMaze::~CKJHMaze(void)// 메모리 동적 해제 코드
{
	delete[]m_elem;
	for (int i=0 ; i<m_h ; i++ )
			delete m_elem[i];
}


void CKJHMaze::setBeginEnd()// 시작과 끝 위치를 찾아 저장 (m_start, m_exit)
{
	for( int i=0 ; i<m_h ; i++ )
		for( int j=0 ; j<m_w ; j++ ) 
		{
			if( m_elem[i][j] == 5 )
				m_start = CKJH2DPoint( j, i );
			else if ( m_elem[i][j] == 9 )
				m_exit = CKJH2DPoint( j, i );
		}
		m_stack.push( m_start );
}


void CKJHMaze::searchExit()//출구탐색코드
{
	int x,y;
	CKJHPointStack pointstack;// 스택에 저장을 위해 스택 객체선언
	setBeginEnd();
	CKJH2DPoint temp;// 객체 선언
	temp.x=m_start.x;// x,y의 시작값
	temp.y=m_start.y;
	while(!isExitPos(temp.x,temp.y)&&isValidPos(temp.x,temp.y))//출구가 아니며 미로 내부에 있을경우
	{
		
		x=temp.x;
		y=temp.y;
		if(m_elem[y][x]==1||m_elem[y][x]==5)//미로의 길을 따라같때 그것이 1이거나 5(출구)이면 
		{
			
			m_elem[y][x]=T_DONE;// 이동하는길 표시
			pointstack.push(x-1,y);//갈수 있는 방향 제시
			pointstack.push(x+1,y);//
			pointstack.push(x,y-1);//
			pointstack.push(x,y+1);//
			if(pointstack.isEmpty()){return;}//스택이 비어있을경우
			else //스택이 비어있지않을경우 스택에 있는값을 pop시킨다
			{
				temp=*pointstack.pop();
			}
		}
		else if(!isPossiblePos(x,y))//갈수 없는 길일경우 스택의 값을 pop시킨다
		{
			temp=*pointstack.pop();
		}
		
		Sleep(100);
	}
}



void CKJHMaze::Load( char *fname )// 파일에서 미로 정보를 읽어옴
{
	FILE *fp = stdin;
	if( fname != NULL ) 
	{
		fp = fopen (fname, "r");
		if( fp == NULL ) 
		{
			printf( " Error: %s 파일이 없습니다.\n");
			return;
		}
	}

	int w, h;
	printf( " 이미지 크기 입력 (w h): ");
	fscanf( fp, "%d%d", &w, &h );
	printf( " 이미지의 크기는 %d x %d 입니다.\n", w, h);

	Init( w, h );		// 메모리 할당

	for( int i=0 ; i<h ; i++ ) 
	{
		for( int j=0 ; j<w ; j++ ) 
		{
			fscanf( fp, "%d", &(m_elem[i][j]) );
		}
	}
	if( fp != stdin ) fclose(fp);
}


void CKJHMaze::Print( char *fname )// 현재 미로 정보를 파일에 저장
								  // fname이 NULL 이면 화면에 결과를 출력함
{
	FILE *fp = stdout;
	if( fname != NULL ) 
	{
		fp = fopen (fname, "w");
		if( fp == NULL ) 
		{
			printf( " Error: %s 파일을 만들 수 없습니다.\n");
			return;
		}
	}

	system("cls");
	printf( "=============================================\n");
	printf( "  전체 미로의 크기 = ");
	fprintf( fp, "%d %d\n", m_w, m_h);
	printf( "=============================================\n");

	for( int i=0 ; i<m_h ; i++ ) 
	{
		for( int j=0 ; j<m_w ; j++ ) 
		{
			switch (m_elem[i][j]) 
			{
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
/*void CMaze::addOptimalPath (C2DPoint &pt)
{
	
}
void CMaze::PrintOptimal( )
{
	
}*/
