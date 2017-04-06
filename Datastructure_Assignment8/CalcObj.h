#include<stdio.h>
#define T_BRACKET 0
#define T_OPERATOR 1
#define T_NUMBER 2

class CCalcobj
{
public:
	int m_type;//표기법
	char m_op;//연산자
	double m_number;//피연산자

	CCalcobj(void){}
	CCalcobj(double val){ Set(val);}//생성자 함수
	~CCalcobj(void){}//소멸자함수
	void  Set(char ch)//연산자+괄호 
	{
		m_op=ch;
		if(isBracket(ch))
			m_type=T_BRACKET;
		else if(isOperator(ch))
			m_type=T_OPERATOR;
	}
	void  Set(double val)//피연산자 입력되는 숫자
	{
		m_type=T_NUMBER;
		m_number= val;
	}
	int Precedence(){return precedence(m_op);}//우선순위
	bool IsBracket(){return m_type==T_BRACKET;}//괄호가 입력받을 경우
	bool IsOperator(){return m_type==T_OPERATOR;}//연산자가 입력받을 경우
	bool IsNumber(){return m_type==T_NUMBER;}//숫자를 입력받을 경우
	void Print()//출력
	{
		if(IsBracket()||IsOperator())
			printf("\t%c",m_op);
		else
			printf("\t%4.1f",m_number);
	}
	friend bool isBracket(char ch);//괄호가 입력받을 경우
	friend bool isOperator(char ch);//연산자가 입력받을 경우
	friend bool isNumber(char ch);//숫자를 입력받을 경우
	friend int precedence(char op);//우선순위를 정의 하기위해
};
inline bool isBracket(char ch)//괄호가 입력받을 경우
{
	switch(ch)
	{
	case'(':
	case')':
	case'[':
	case']':
	case'{':
	case'}':
		return true;
	}
	return false;
}
inline bool isOperator(char ch)//연산자를 입력받을 경우
{
	switch(ch)
	{
	case'+':
	case'-':
	case'/':
	case'*':
		return true;
	}
	return false;
}
inline bool isNumber(char ch)//숫자를 입력받을 경우
{
	int temp=atoi(&ch);
	return (temp>=0&&temp<=9);
}
inline int precedence(char op)//입력받은것의 우선순위 
{
	switch(op)
	{
	case'(':
	case')':return 0;
	case'+':
	case'-':return 1;
	case'*':
	case'/':return 2;
	}
	return -1;
}