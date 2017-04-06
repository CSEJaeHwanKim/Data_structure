//3.Ʈ�� ����
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
	draw_tree(row+1,left,mid-1); // ���� ���� mid ����
	draw_tree(row+1,mid+1,right); // ������ ���� mid ����
}
void init(void) //�Է�
{
	int i,j;
	for(i=0;i<MAX_HEIGHT;i++)
	{
		for(j=0;j<MAX_WIDTH;j++)
		{
			screen[i][j]='-'; //����� '-'���� ���
		}
  
	}
}
void display(void) //���
{
	int i,j;
	for(i=0;i<MAX_HEIGHT;i++)
	{
		for(j=0;j<MAX_WIDTH;j++)
		{
			cout<<screen[i][j]; //X�� ������ ������ ���
		}
		cout<<endl;
	}
 
}
void main(void)
{
	init();
	draw_tree(0,0,MAX_WIDTH-1);
	display();
}//main���� ���������� ���


