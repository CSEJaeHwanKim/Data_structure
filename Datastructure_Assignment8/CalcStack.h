#include "Calcobj.h"
#define STACKSIZE 10000
class CCalcStack
{
public:
	CCalcobj m_obj[STACKSIZE];
	int m_top;
	CCalcStack(void){m_top=0;}
	~CCalcStack(void){}
	bool isEmpty(){return m_top==0;}//stack�� ����������
	bool isFull(){return m_top==STACKSIZE;}//stack�� �������������
	void push(CCalcobj pt)//stack�� �߰�
	{
		if(!isFull())
			m_obj[m_top++]=pt;
	}
	CCalcobj pop()//stack������ ��Ұ� ����
	{
		if(isEmpty())return NULL;
		else return m_obj[--m_top];
	}
	CCalcobj peek()//stack�� ���
	{
		if(isEmpty()) return NULL;
		else return m_obj[m_top-1];
	}
};