#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define ST_SIZE 30

double op(char symbol, int op1, int op2)
{
	switch(symbol)
	{
	case '+': return op1+op2;
	case '-': return op1-op2;
	case '*': return op1*op2;
	case '/': return op1/op2;
	case '^': return pow(op1,op2);
	}
}

void push(double item, int *top, double s[])
{
	if(*top==ST_SIZE-1)
	{
		return;
	}
	s[++(*top)]=item;
}
	
double pop(int *top, double s[])
{
	double item_del;
	item_del=s[*top];
	(*top)--;
	return item_del;
}

int isdig(char symbol)
{
	return (symbol >= '0' && symbol <='9');
}

void main()
{
	double s[ST_SIZE],op1,op2,res;
	char postfix[ST_SIZE],symbol;
	int top,i;
	printf("Enter a valid postfix exxpression\n");
	scanf("%s",postfix);
	top=-1;
	for(i=0;i<strlen(postfix);i++)
	{
		symbol = postfix[i];
		if(isdig(symbol))
			push(symbol - '0',&top,s);
		else
		{
			op2=pop(&top,s);
			op1=pop(&top,s);
			res=op(symbol,op1,op2);
			push(res,&top,s);
		}
	}
	res=pop(&top,s);
	printf("Value is %lf\n",res);
}





























