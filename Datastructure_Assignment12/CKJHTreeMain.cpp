#include<iostream>
#include <conio.h>
#include "KJHTree.h"
using namespace std;
void Usage()
{
	system("cls");
	printf("=====================================\n");
	printf("Binary Tree Test program Usage:\n\n");
	printf("a num : append num node.\n");
	printf("d:       delete num node.\n");
	printf("s:       search num node.\n");
	printf("i:       inorder print.\n");
	printf("p:       preorder print.\n");
	printf("t:       postorder print.\n");
	printf("c:       count print.\n");
	printf("l:       height print.\n");
	printf("h:       print this message.\n");
	printf("q:       exit.\n");
	printf("=====================================\n");
}
void main()
{
	CKJHTree tree;
	char ch;
	
	int num,nmatch;
	char str[100];
	Usage();
	do
	{
		printf(">>> ");
		gets(str);
		nmatch=sscanf(str,"%c %d",&ch,&num);
		switch(str[0])
		{
			case 'h':Usage(); break;
			case 'p':tree.PrintPreOrder(); break;
			case 't':tree.PrintPostOrder(); break;
			case 'i':tree.PrintInOrder(); break;
			case 'c':printf("%d\n",tree.GetCount()); break;
			case 'l':printf("%d\n",tree.GetHeight()); break;
			case 'a':tree.Insert(num); break;
			case 'd':tree.Delete(num); break;
			case 's':tree.Search(num); break;
		}
	}while(str[0]!='q');


	/*tree.Insert(18);
	tree.Insert(26);
	tree.Insert(31);
	tree.Insert(7);
	tree.Insert(12);
	tree.Insert(27);
	tree.Insert(3);
	tree.PrintInOrder();
	tree.PrintPostOrder();
	tree.PrintPreOrder();
	int count=tree.GetCount();
	printf("%d\n",count);
	int height=tree.GetHeight();
	printf("%d\n",height);*/
	//CNode *n=tree.Find(13);

}
