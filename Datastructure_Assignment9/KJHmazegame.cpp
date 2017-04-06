#include <iostream>
#include <Windows.h>
#include "KJHmaze.h"

CKJHMaze::CKJHMaze(void)//��ü����
{
	Init( 0, 0 );
}
CKJHMaze::~CKJHMaze(void)// �޸� ���� ���� �ڵ�
{
	delete[]m_elem;
	for (int i=0 ; i<m_h ; i++ )
			delete m_elem[i];
}


void CKJHMaze::setBeginEnd()// ���۰� �� ��ġ�� ã�� ���� (m_start, m_exit)
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


void CKJHMaze::searchExit()//�ⱸŽ���ڵ�
{
	int x,y;
	CKJHPointStack pointstack;// ���ÿ� ������ ���� ���� ��ü����
	setBeginEnd();
	CKJH2DPoint temp;// ��ü ����
	temp.x=m_start.x;// x,y�� ���۰�
	temp.y=m_start.y;
	while(!isExitPos(temp.x,temp.y)&&isValidPos(temp.x,temp.y))//�ⱸ�� �ƴϸ� �̷� ���ο� �������
	{
		
		x=temp.x;
		y=temp.y;
		if(m_elem[y][x]==1||m_elem[y][x]==5)//�̷��� ���� ���󰰶� �װ��� 1�̰ų� 5(�ⱸ)�̸� 
		{
			
			m_elem[y][x]=T_DONE;// �̵��ϴ±� ǥ��
			pointstack.push(x-1,y);//���� �ִ� ���� ����
			pointstack.push(x+1,y);//
			pointstack.push(x,y-1);//
			pointstack.push(x,y+1);//
			if(pointstack.isEmpty()){return;}//������ ����������
			else //������ �������������� ���ÿ� �ִ°��� pop��Ų��
			{
				temp=*pointstack.pop();
			}
		}
		else if(!isPossiblePos(x,y))//���� ���� ���ϰ�� ������ ���� pop��Ų��
		{
			temp=*pointstack.pop();
		}
		
		Sleep(100);
	}
}



void CKJHMaze::Load( char *fname )// ���Ͽ��� �̷� ������ �о��
{
	FILE *fp = stdin;
	if( fname != NULL ) 
	{
		fp = fopen (fname, "r");
		if( fp == NULL ) 
		{
			printf( " Error: %s ������ �����ϴ�.\n");
			return;
		}
	}

	int w, h;
	printf( " �̹��� ũ�� �Է� (w h): ");
	fscanf( fp, "%d%d", &w, &h );
	printf( " �̹����� ũ��� %d x %d �Դϴ�.\n", w, h);

	Init( w, h );		// �޸� �Ҵ�

	for( int i=0 ; i<h ; i++ ) 
	{
		for( int j=0 ; j<w ; j++ ) 
		{
			fscanf( fp, "%d", &(m_elem[i][j]) );
		}
	}
	if( fp != stdin ) fclose(fp);
}


void CKJHMaze::Print( char *fname )// ���� �̷� ������ ���Ͽ� ����
								  // fname�� NULL �̸� ȭ�鿡 ����� �����
{
	FILE *fp = stdout;
	if( fname != NULL ) 
	{
		fp = fopen (fname, "w");
		if( fp == NULL ) 
		{
			printf( " Error: %s ������ ���� �� �����ϴ�.\n");
			return;
		}
	}

	system("cls");
	printf( "=============================================\n");
	printf( "  ��ü �̷��� ũ�� = ");
	fprintf( fp, "%d %d\n", m_w, m_h);
	printf( "=============================================\n");

	for( int i=0 ; i<m_h ; i++ ) 
	{
		for( int j=0 ; j<m_w ; j++ ) 
		{
			switch (m_elem[i][j]) 
			{
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
/*void CMaze::addOptimalPath (C2DPoint &pt)
{
	
}
void CMaze::PrintOptimal( )
{
	
}*/
