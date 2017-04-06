#include<stdio.h>
#define T_BRACKET 0
#define T_OPERATOR 1
#define T_NUMBER 2

class CCalcobj
{
public:
	int m_type;//ǥ���
	char m_op;//������
	double m_number;//�ǿ�����

	CCalcobj(void){}
	CCalcobj(double val){ Set(val);}//������ �Լ�
	~CCalcobj(void){}//�Ҹ����Լ�
	void  Set(char ch)//������+��ȣ 
	{
		m_op=ch;
		if(isBracket(ch))
			m_type=T_BRACKET;
		else if(isOperator(ch))
			m_type=T_OPERATOR;
	}
	void  Set(double val)//�ǿ����� �ԷµǴ� ����
	{
		m_type=T_NUMBER;
		m_number= val;
	}
	int Precedence(){return precedence(m_op);}//�켱����
	bool IsBracket(){return m_type==T_BRACKET;}//��ȣ�� �Է¹��� ���
	bool IsOperator(){return m_type==T_OPERATOR;}//�����ڰ� �Է¹��� ���
	bool IsNumber(){return m_type==T_NUMBER;}//���ڸ� �Է¹��� ���
	void Print()//���
	{
		if(IsBracket()||IsOperator())
			printf("\t%c",m_op);
		else
			printf("\t%4.1f",m_number);
	}
	friend bool isBracket(char ch);//��ȣ�� �Է¹��� ���
	friend bool isOperator(char ch);//�����ڰ� �Է¹��� ���
	friend bool isNumber(char ch);//���ڸ� �Է¹��� ���
	friend int precedence(char op);//�켱������ ���� �ϱ�����
};
inline bool isBracket(char ch)//��ȣ�� �Է¹��� ���
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
inline bool isOperator(char ch)//�����ڸ� �Է¹��� ���
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
inline bool isNumber(char ch)//���ڸ� �Է¹��� ���
{
	int temp=atoi(&ch);
	return (temp>=0&&temp<=9);
}
inline int precedence(char op)//�Է¹������� �켱���� 
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