//3.트리 생성
#include <iostream>
using namespace std;
#define MAX_HEIGHT 50 
#define MAX_WIDTH 40
char screen[MAX_HEIGHT][MAX_WIDTH];
void draw_tree(int row, int left, int right) 
{ 
	int mid; 
	if( (right-left)<3 || row>MAX_HEIGHT)
	{ 
		return; 
	}
	mid = (right+left)/2;
	screen[row][mid] = 'X'; 
	draw_tree(row+1,left,mid-1); // 왼쪽 영역 mid 기준
	draw_tree(row+1,mid+1,right); // 오른쪽 영역 mid 기준
}
void init(void) //입력
{
	int i,j;
	for(i=0;i<MAX_HEIGHT;i++)
	{
		for(j=0;j<MAX_WIDTH;j++)
		{
			screen[i][j]='-'; //빈공간 '-'으로 출력
		}
  
	}
}
void display(void) //출력
{
	int i,j;
	for(i=0;i<MAX_HEIGHT;i++)
	{
		for(j=0;j<MAX_WIDTH;j++)
		{
			cout<<screen[i][j]; //X를 포함한 최종값 출력
		}
		cout<<endl;
	}
 
}
void main(void)
{
	init();
	draw_tree(0,0,MAX_WIDTH-1);
	display();
}//main에서 최종적으로 출력


