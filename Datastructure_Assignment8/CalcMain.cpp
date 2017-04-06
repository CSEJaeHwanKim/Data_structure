#include<iostream>
#include "Calculator.h"
void main()
{
	CCalculator cal;
	cal.Read();
	cal.PrintInfix();
	cal.Infix2postfix();
	cal.PrintPostfix();
	double result=cal.Calculate();
	printf("결과값은==>%f\n\n",result);
	getchar();
}




