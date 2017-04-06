#include<iostream>
#include"KJHMyQueue.h"
#include "KJHArray.h"
using namespace std;

void main()
{
	CKJHMyQueue q; //ť ��ü����
	CKJHMyNode * n;//��� ��ü ����(�ּҰ�)
	CKJHArray a;//Arrayť��ü ����
	
	a.ArrEnQ1("�ڼ���",1);
	a.ArrEnQ1("�����",4);
	a.ArrEnQ1("�̼���",9);
	a.ArrEnQ1("������",8);
	a.ArrEnQ1("�����",7);
	
	a.Print();
	n=a.ArrDeQ();
	if(n!=NULL)//ť�� ������� �������
	{
		cout<<endl;
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.",n->name,n->w_time);
	}
	n=a.ArrDeQ();
	if(n!=NULL)//ť�� ������� �������
	{
		cout<<endl;
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.",n->name,n->w_time);
	}
	n=a.ArrDeQ();
	if(n!=NULL)//ť�� ������� �������
	{
		cout<<endl;
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.",n->name,n->w_time);
	}
	n=a.ArrDeQ();
	if(n!=NULL)//ť�� ������� �������
	{
		cout<<endl;
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.",n->name,n->w_time);
		cout<<endl;
	}
	a.Print();
	n=a.ArrDeQ();
	if(n!=NULL)//ť�� ������� �������
	{
		cout<<endl;
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.",n->name,n->w_time);
	}


	q.EnQ("ȫ�浿",1);
	q.EnQ("��浿",5);
	q.EnQ("��浿",4);
	q.EnQ("�̱浿",3);
	q.EnQ("�ڱ浿",9);
	q.EnQ("���浿",10);
	cout<<endl<<endl;
	fprintf(stdout,"             ********������� ��********\n");
	q.Print();

	n=q.DeQ();//ť���� ��������
	if(n!=NULL)//ť�� ������� �������
	{
		cout<<endl;
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.\n",n->name,n->w_time);
		delete n;
	}
	n=q.DeQ();//ť���� ��������
	if(n!=NULL)//ť�� ������� �������
	{
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.\n",n->name,n->w_time);
		delete n;
	}	
	n=q.DeQ();//ť���� ��������
	if(n!=NULL)//ť�� ������� �������
	{
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.\n",n->name,n->w_time);
		delete n;
	}
	n=q.DeQ();//ť���� ��������
	if(n!=NULL)//ť�� ������� �������
	{
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.\n",n->name,n->w_time);
		delete n;
	}
	n=q.DeQ();//ť���� ��������
	if(n!=NULL)//ť�� ������� �������
	{
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.\n",n->name,n->w_time);
		delete n;
	}

	q.Print();

	n=q.DeQ();//ť���� ��������
	if(n!=NULL)//ť�� ������� �������
	{
		fprintf(stdout,"%10s ������ %3f�е��� �����Ͽ����ϴ�.\n",n->name,n->w_time);
		delete n;
		
	}

}