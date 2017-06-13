#include<stdio.h>
#include<stdlib.h>
#define ST_SIZE 10
void push(int item,int s[],int top)
{
	if(top==ST_SIZE-1)
	{
	printf("STACK OVERFLOW\n");
	return;
	}
	s[++(top)]=item;
}

int pop(int s[],int top)
{
	int item_del;
	if(top==-1)
	{
	printf("STACK UNDEERFLOW\n");
	return;
	}
	item_del=s[top];
	(top)--;
	return item_del;
}

void display(int s[],int top)
{

	int i;
	if(top==-1)
	{
	printf("No Elements to print\n");
	return;
	}
	for(i=0;i<=top;i++)
	{
	printf("\n%d\n",s[i]);
	}	
}

int main(void)
{
	int top;
	int item,item_del,ch,s[5];
	for(;;)
	{
	printf("\n1.PUSH\n2.POP");
	printf("\n3.DISPLAY\n4.EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		printf("Enter the item to be pushed\n");
		scanf("%d",&item);
		push(item,s,top);
		break;
	case 2:
		item_del=pop(s,top);
		if(item_del==0)
		{
			
		}
		else
		{
		printf("deleted item=%d",item_del);
		break;
		}
	case 3:
		display(s,top);
		break;
	default:
		exit(0);
	}
	}
}
