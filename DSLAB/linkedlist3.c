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
		printf("Cannot allocate memory\n");
		return NULL;
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

NODE insert_front(int item,NODE last)
{
	NODE temp;
	temp=getnode();
	temp->info=item;
	if(last==NULL)
	{
		last=temp;
		temp->link=temp;
		return temp;
	}
	else
	{
		temp->link=last->link;
	}
	last->link=temp;
	return last;
}

NODE delete_front(NODE last)
{
	NODE first;
	if(last==NULL)
	{
		printf("List is empty\n");
		return NULL;
	}
	if(last->link=last)
	{
		printf("Item Deleted=%d",last->info);
		freenode(last);
		return NULL;
	}
	first=last->link;/*assign first in the circular linked list*/
	last->link=first->link;/*update the link to the next node*/
	printf("Item Deleted=%d",first->info);
	freenode(first);
	return last;
}

NODE insert_rear(int item,NODE last)
{
        NODE temp;
        temp=getnode();
        temp->info=item;
        if(last==NULL)
        {
                last=temp;
                temp->link=temp;
                return temp;
        }
        else
        {
                temp->link=last->link;
        }
        last->link=temp;
        return temp;
}

NODE delete_rear(NODE last)
{
	NODE prev;
	if(last==NULL)
	{
		printf("List is empty\n");
		return NULL;
	}
	if(last->link=last)
	{
		printf("Item Deleted=%d",last->info);
		freenode(last);
		return NULL;
	}
	prev=last->link;
	while(prev->link!=NULL)
		prev=prev->link;
	prev->link=last->link;
	printf("Item Deleted=%d",last->info);
	freenode(last);
	return prev;
}		

void display(NODE last)
{
	NODE temp;
	if(last==NULL)
	{
		printf("List is empty\n");
	}
	temp=last;
	while(temp->link!=last)
	{
		temp=temp->link;
		printf("%d\n",temp->info);
	}
	printf("%d\n",last->info);
}

int 
main(void)
{
	NODE last;
	last=NULL;
	int choice,item;
	for(;;)
	{
		printf("\n1.INSERT FRONT\n2.DELETE FRONT");
		printf("\n3.INSERT REAR\n4.DELETE REAR");
		printf("\n5.DISPLAY\n6.EXIT\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be inserted at front\n");
				scanf("%d",&item);
				last=insert_front(item,last);
				break;
			case 2:
				last=delete_front(last);
				break;
			case 3:
				printf("Enter the item to be inserted at rear\n");
				scanf("%d",&item);
				last=insert_rear(item,last);
				break;
			case 4:
				last=delete_rear(last);
				break;
			case 5:
				display(last);
				break;
			default:
				exit(0);
		}
	}
}



































