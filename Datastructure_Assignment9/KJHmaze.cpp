#include "KJHmaze.h"

void main()
{
	CKJHMaze	maze;

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