#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int A[MAXSIZE];
int top=-1;

void push(int x)
{
	if(top==MAXSIZE-1)
	{
	printf("STACK OVERFLOW\n");	return;
	}
	A[++top]=x;
}

int pop()
{
	int item_del;
	if(top==-1)
	{
	printf("STACK UNDERFLOW\n");
	return 0;
	}
	item_del=A[top];
	top--;
	return item_del;

}

void print()
{	
	int i;
	for(i=0;i<=top;i++)
	{
	printf("%d",A[i]);
	printf("\n");
	}
}

int 
main(void)
{
	int item,ch,item_del;
	fflush(stdin);
	for(;;)
	{
	printf("\n1.PUSH\n2.POP");
	printf("\n3.DISPLAY\n4.EXIT");
	printf("\nEnter the choice of operation\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		printf("Enter the item to be inserted");
		scanf("%d",&item);
		push(item);
		break;
	case 2:
		item_del=pop();
		if(item_del == 0)
		{
		}
		printf("Item deleted=%d",item_del);
		break;		
	case 3:
		print();
		break;
	default:
		exit(0);
	}
	}
}
