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
	printf("�������==>%f\n\n",result);
	getchar();
}




