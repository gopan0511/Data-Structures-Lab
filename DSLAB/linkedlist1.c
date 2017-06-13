#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("Unable to allocate memory space\n");
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

NODE insert_front(NODE first,int item)
{
	NODE temp;
	temp=getnode();
	temp->info=item;
	temp->link=first;
	return temp;
}

NODE delete_front(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("List is empty\n");
		return first;
	}
	temp=first;
	first=first->link;
	printf("Node deleted is %d\n",temp->info);
	freenode(temp);
	return first;
}

void display(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("No list is present\n");
		return;
	}
	temp=first;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->link;
	}
}

int
main(void)
{
	NODE first;
	int item,choice;
	for(;;)
	{
		printf("MENU\n");
		printf("1.INSERT\n2.DELETE\n");
		printf("3.DISPLAY\n4.EXIT\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the item to be inserted in the list\n");
			scanf("%d",&item);
			first=insert_front(first,item);
			break;

			case 2:
			first=delete_front(first);
			break;

			case 3:
			display(first);
			break;

			default:
			exit(0);
		}
	}
}




























