#include "KJHmaze.h"

void main()
{
	CKJHMaze	maze;

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