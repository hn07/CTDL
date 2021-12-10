#include "stackmang.h"
#include <string.h>
#include <iostream>
#include "ReadTree.cpp"
using namespace std;

int Precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}
float Evaluate(char *Postfix)
{
	Stack S;
	makeNullStack(&S);
	char *p;
	float op1, op2, result;
	S.Top_idx = -1; 
	p = &Postfix[0];

	while (*p != '\0')
	{
		while (*p == ' ' || *p == '\t')
		{
			p++;
		}
		if (isdigit(*p))
		{
			int num = 0;
			while (isdigit(*p))
			{
				num = num * 10 + *p - 48;
				*p++;
			}
			push(num,&S);
		}
		else
		{
		//	 op1 = pop(&S);
			// op2 = pop(&S);
			switch (*p)
			{
			case '+':
				result = op2 + op1;
				break;
			case '-':
				result = op2 - op1;
				break;
			case '/':
				result = op2 / op1;
				break;
			case '*':
				result = op2 * op1;
				break;
			default:
				printf("\nInvalid Operator");
				return 0;
			}
			push(result,&S);
		}
		p++;
	}

//	result pop(&S)
	return result;
}

int main()
{
	char A[MAX], B[MAX];
	printf("Infix : ");
	gets(A);


	//printf("Postfix: %s\n", B);
	printf("Equals is %f\n", Evaluate(&B[0]));
	gets(A);
	return 0;
}
