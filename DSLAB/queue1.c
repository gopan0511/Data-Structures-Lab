#include<stdio.h>
#include<stdlib.h>
#define Q_SIZE 10

int qfull(int r)
{
	if(r==Q_SIZE-1)
		return 1;
	return 0;
}

int qempty(int f,int r)
{
	return ((f>r)?1:0);
}

void enqueue(int q[],int item,int *r)
{
	if(qfull(*r))
	{
		printf("Queue is empty\n");
		return;
	}
	q[++(*r)]=item;
}

int dequeue(int q[],int *f,int *r)
{
	if(qempty(*f,*r))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Deleted item=%d",q[*f]);
	(*f)++;
	if(*f>*r)
	{
		*f=0; *r=-1;
	}
}

void display(int q[],int f,int r)
{
	int i;
	if(qempty(f,r))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements:\n");
	for(i=f;i<=r;i++)
		printf("%d\n",q[i]);
}

int
main(void)
{
	int choice,f,r,q[Q_SIZE],item;
	f=0; r=-1;
	for(;;)
	{
		printf("\n1.ENQUEUE\n2.DEQUEUE");
		printf("\n3.DISPLAY\n4.EXIT\n");
		printf("Enter the choice of operation\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				enqueue(q,item,&r);
				break;
			case 2:
				dequeue(q,&f,&r);
				break;
			case 3:
				display(q,f,r);
				break;
			case 4:
				exit(0);
		}
	}
}















