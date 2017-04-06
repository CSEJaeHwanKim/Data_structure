#include "CalcStack.h"
class CCalculator
{
public:
	CCalcobj m_infix[1000];//����ǥ��
	int m_inCount;
	CCalcobj m_postfix[1000];//����ǥ��
	int m_postCount;
	CCalcStack m_stack;//stack ��ü����
	CCalculator(){}
	~CCalculator(){}
	void Read(FILE*fp=stdin)//infix�� ����
	{
		printf("����: ");
		char ch;
		double val;
		m_inCount=0;
		while((ch=getc(fp))!='\n')
		{
			if(isBracket(ch)||isOperator(ch))
			{
				m_infix[m_inCount++].Set(ch);
			}
			else if(isNumber(ch))
			{
		
				ungetc(ch,fp);
				fscanf(fp,"%lf",&val);
				m_infix[m_inCount++].Set(val);
			}
		}
		
	}
	void PrintInfix()//infix�� ���
	{
		printf("Infix:\n");
		for(int i=0;i<m_inCount;i++)
		{
			m_infix[i].Print();
			printf("\n");
		}
	}
	void PrintPostfix()//postfix�� ���
	{
	
		printf("Postfix:\n");
		for(int i=0;i<m_postCount;i++)
		{
			m_postfix[i].Print();
			printf("\n");
		}
	}
	//void Write();
	void Infix2postfix()//infix->postfix�� ��ȯ
	{
		CCalcStack stack;
		CCalcobj temp;
		m_postCount=0;
		int predence;
		
		for(int i=0;i<=m_inCount;i++)//infix�� ���� ���������� ��
		{
			predence=m_infix[i].Precedence();//�켱����
			if(m_infix[i].IsNumber())//���ڰ� �Է� �޾����� postfix�� ���̵�
			{
				m_postfix[m_postCount++]=m_infix[i];
			}
			else if(m_infix[i].IsOperator())//�����ڸ� �Է¹޾�����
			{      //1.������ ������� �ʾ�����2.�켱 ������ ���ų� ���δٸ���3.��ȣ���� ��ȣň ��������=>stack���� ���� postfix������ �׿��ǰ��� stack���ٽ� ����
				if(!stack.isEmpty()&&stack.m_obj[stack.m_top-1].Precedence()>=predence&&stack.m_obj[stack.m_top-1].m_op!='('&&stack.m_obj[stack.m_top-1].m_op!='['&&stack.m_obj[stack.m_top-1].m_op!='{')
					{
						temp=stack.pop();
						m_postfix[m_postCount++]=temp;
						stack.push(m_infix[i]);
					}
					else 
						stack.push(m_infix[i]);
			}
			else if (m_infix[i].IsBracket() )//��ȣ�� �������� ������ ¦�� ������������ postfix�� �ִ´� ex)'{}''[]''()'
			{
				if(m_infix[i].m_op=='('||m_infix[i].m_op=='{'||m_infix[i].m_op=='[')
					stack.push(m_infix[i]);
				if(m_infix[i].m_op=='}')
					 while((temp=stack.pop()).m_op!='{')
						m_postfix[m_postCount++]=temp;
				else if(m_infix[i].m_op==')')
					while((temp=stack.pop()).m_op!='(')
						m_postfix[m_postCount++]=temp;
				else if(m_infix[i].m_op==']')
					while((temp=stack.pop()).m_op!='[')
						m_postfix[m_postCount++]=temp;
			}
			
		}
			
			while(!stack.isEmpty())//stack�� ��������ʾ����� stack�� ����Ǿ� �ִ� ���� ���� postfix�� �̵�
			{
				m_postfix[m_postCount++].Set(stack.pop().m_op);
			}
	}

	double Calculate()//����
		              //stack�� ���ִ� ������ �ǿ����ں��� ���ʷ� �ΰ��� ������ ������(Bracket+operate)�� �̿��Ͽ� ���� ����
	{
		CCalcStack stack;
		CCalcobj cal1;
		CCalcobj cal2;
		char op=0;
		double result;
		
		for (int i=0;i<m_postCount;i++)//postfix�� ����Ǿ��ִ°��� �ҷ��������� ���
		{

			if(m_postfix[i].IsNumber())//�ǿ����ڰ� �Է� �޾�����
			{
				stack.push(m_postfix[i]);
			}
			else
			{
				cal1=stack.pop();
				cal2=stack.pop();

				switch((m_postfix[i].m_op))
				{
				case '+':cal1.Set(cal2.m_number+cal1.m_number);
				break;
				case '-':cal1.Set(cal2.m_number-cal1.m_number);
				break;
				case '*':cal1.Set(cal2.m_number*cal1.m_number);
				break;
				case '/':cal1.Set(cal2.m_number/cal1.m_number);
				break;
				}
				stack.push(cal1);
			}
		}
		return stack.pop().m_number;
		
	}
};