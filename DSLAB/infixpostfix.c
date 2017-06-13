#include<stdio.h>
#include<string.h>
#define ST_SIZE 20

void push(char item,int *top,char s[])
{
	if(*top==ST_SIZE-1)
	{
		printf("STACK OVERFLOW\n");
		return;
	}
	s[++(*top)]=item;
}

char pop(int *top,char s[])
{
	char item_del;
	if(*top==-1)
	{	
		return 0;
	}
	item_del=s[(*top)--];
	
	return item_del;
}

int F(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 4;
		case '^':
		case '$': return 5;
		case '(': return 0;
		case '#': return -1;
		default : return 8;
	}
}

int G(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 3;
		case '^':
		case '$': return 6;
		case '(': return 9;
		case ')': return 0;
		default: return 7;
	}
}

void infix_postfix(char infix[],char postfix[])
{
	int i,j;
	char symbol;
	int top = -1;
	char s[30];
	
	push('#',&top,s);
	j=0;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(F(s[top])>G(symbol))
		{
			postfix[j]=pop(&top,s);
			j++;
		}
		if(F(s[top])!=G(symbol))
			push(symbol,&top,s);
		else
			pop(&top,s);
	}
	while(s[top]!='#')
	{
		postfix[j]=pop(&top,s);
		j++;
	}
	postfix[j]='\0';
	
}

int main(){
	char infix[30],postfix[30];
	printf("Enter a valid infix expression\n");
	scanf("%s",infix);
	infix_postfix(infix,postfix);
	printf("Valid postfix expression is:\n%s\n",postfix);
	printf("\n");
}











































