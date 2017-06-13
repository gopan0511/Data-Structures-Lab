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
		printf("Unable to allocate memory\n");
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

NODE insert_rear(NODE first,int item)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;
	temp->link=NULL;
	if(first==NULL)
	{
		return temp;
	}
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	return first;
}

NODE delete_rear(NODE first)
{
	NODE prev,cur;
	if(first==NULL)
	{
		printf("List is empty\n");
		return first;
	}
	if(first->link==NULL)
	{
		printf("Deleted value is %d",first->info);
		freenode(first);
		first=NULL;
		return first;
	}
	cur=first;
	prev=NULL;

	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}

	printf("Item deleted is %d",cur->info);
	freenode(cur);
	prev->link=NULL;
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
	int choice,item;
	first=NULL;
	for(;;)
	{
		printf("\n1.INSERT\n2.DELETE");
		printf("\n3.DISPLAY\n4.EXIT");
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the item to be inserted at rear position\n");
			scanf("%d",&item);
			first=insert_rear(first,item);
			break;

			case 2:
			first=delete_rear(first);
			break;

			case 3:
			display(first);
			break;

			default:
			exit(0);
		}
	}
}























