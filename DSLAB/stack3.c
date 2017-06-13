#include<stdio.h>
#include<stdlib.h>
#define ST_SIZE 10

struct stack 
{
	int items[ST_SIZE];
	int top;
};
typedef struct stack STACK;

int is_empty(STACK *S)
{
	if(S->top==-1)
		return -1;
	return 0;
}

int is_full(STACK *S)
{
	if(S->top==ST_SIZE-1)
		return -1;
	return 0;
}

void push(int item,STACK *S)
{
	if(is_full(S))
	{	
		printf("STACK OVERFLOW\n");
		return;
	}
	S->top++;
	S->items[S->top]=item;
}

int pop(STACK *S)
{
	int item_del;
	if(is_empty(S))
	{	
		printf("STACK UNDERFLOW\n");
		return 0;
	}
	item_del=S->items[S->top];
	S->top--;
	return item_del;
}

void display(STACK *S)
{
	int i;
	if(is_empty(S))
	{
		printf("STACK UNDERFLOW\n");
		return;
	}
	printf("Contents of the stack\n");
	for(i=0;i<=S->top;i++)
	{
		printf("%d\n",S->items[i]);
	}
}

int 
main(void)
{
	int item,choice;
	STACK s;
	s.top=-1;
	for(;;)
	{
		printf("MENU\n");
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be pushed\n");
				scanf("%d",&item);
				push(item,&s);
				break;
			case 2:
				printf("Item deleted=%d",pop(&s));
				break;
			case 3:
				display(&s);
				break;
			default: exit(0);
		}
	}
}



















































































