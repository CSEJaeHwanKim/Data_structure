#include "CalcStack.h"
class CCalculator
{
public:
	CCalcobj m_infix[1000];//중위표기
	int m_inCount;
	CCalcobj m_postfix[1000];//후위표기
	int m_postCount;
	CCalcStack m_stack;//stack 객체생성
	CCalculator(){}
	~CCalculator(){}
	void Read(FILE*fp=stdin)//infix값 저장
	{
		printf("수식: ");
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
	void PrintInfix()//infix값 출력
	{
		printf("Infix:\n");
		for(int i=0;i<m_inCount;i++)
		{
			m_infix[i].Print();
			printf("\n");
		}
	}
	void PrintPostfix()//postfix값 출력
	{
	
		printf("Postfix:\n");
		for(int i=0;i<m_postCount;i++)
		{
			m_postfix[i].Print();
			printf("\n");
		}
	}
	//void Write();
	void Infix2postfix()//infix->postfix로 변환
	{
		CCalcStack stack;
		CCalcobj temp;
		m_postCount=0;
		int predence;
		
		for(int i=0;i<=m_inCount;i++)//infix의 값이 끝날때까지 비교
		{
			predence=m_infix[i].Precedence();//우선순위
			if(m_infix[i].IsNumber())//숫자가 입력 받았을시 postfix로 값이동
			{
				m_postfix[m_postCount++]=m_infix[i];
			}
			else if(m_infix[i].IsOperator())//연산자를 입력받았을시
			{      //1.스택이 비어있을 않았을시2.우선 순위가 같거나 서로다를시3.괄호시작 기호흫 만났을시=>stack에서 빼서 postfix에저장 그외의것은 stack에다시 저장
				if(!stack.isEmpty()&&stack.m_obj[stack.m_top-1].Precedence()>=predence&&stack.m_obj[stack.m_top-1].m_op!='('&&stack.m_obj[stack.m_top-1].m_op!='['&&stack.m_obj[stack.m_top-1].m_op!='{')
					{
						temp=stack.pop();
						m_postfix[m_postCount++]=temp;
						stack.push(m_infix[i]);
					}
					else 
						stack.push(m_infix[i]);
			}
			else if (m_infix[i].IsBracket() )//괄호를 만났을시 서로의 짝을 만나기전까지 postfix로 넣는다 ex)'{}''[]''()'
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
			
			while(!stack.isEmpty())//stack이 비어있지않았을시 stack에 저장되어 있는 값을 전부 postfix로 이동
			{
				m_postfix[m_postCount++].Set(stack.pop().m_op);
			}
	}

	double Calculate()//계산기
		              //stack에 들어가있는 맨위의 피연산자부터 차례로 두개를 빼내어 연산자(Bracket+operate)를 이용하여 최종 연산
	{
		CCalcStack stack;
		CCalcobj cal1;
		CCalcobj cal2;
		char op=0;
		double result;
		
		for (int i=0;i<m_postCount;i++)//postfix에 저장되어있는값을 불러오기위해 사용
		{

			if(m_postfix[i].IsNumber())//피연산자가 입력 받았을때
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