#include "Calcobj.h"
#define STACKSIZE 10000
class CCalcStack
{
public:
	CCalcobj m_obj[STACKSIZE];
	int m_top;
	CCalcStack(void){m_top=0;}
	~CCalcStack(void){}
	bool isEmpty(){return m_top==0;}//stack이 비어있을경우
	bool isFull(){return m_top==STACKSIZE;}//stack이 가득차있을경우
	void push(CCalcobj pt)//stack에 추가
	{
		if(!isFull())
			m_obj[m_top++]=pt;
	}
	CCalcobj pop()//stack맨위의 요소값 빼기
	{
		if(isEmpty())return NULL;
		else return m_obj[--m_top];
	}
	CCalcobj peek()//stack값 출력
	{
		if(isEmpty()) return NULL;
		else return m_obj[m_top-1];
	}
};