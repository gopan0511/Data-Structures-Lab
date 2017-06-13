#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int info;
	struct node*link;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE temp;
	temp =(NODE)malloc(sizeof(struct node));
	return temp;
}

NODE insert_front(NODE last,int item)
{
	NODE temp;
	temp = getnode();
	temp->info=item;
	temp->link = temp;
	if(last==NULL)
	{
		return temp;
	}
	temp->link = last->link;
	last->link=temp;
	return last;
}

NODE insert_rear(NODE last,int item)
{
	NODE temp;
	temp = getnode();
	temp->info = item;
	temp->link = temp;
	if(last == NULL)
	{
		return temp;
	}
	temp->link = last->link;
	last->link = temp;
	return temp;
}

NODE insert_pos(NODE last,int item,int pos)
{
	int i;
	NODE temp;
	NODE next = last->link;
	temp = getnode();
	temp->info = item;
	temp->link=NULL;
	if(last==NULL)
	{
		temp->link = temp;
		return temp;
	}
	if(pos==1)
	{
		temp->link = last->link;
		last->link = temp;
		return last;
	}
	for(i=1;i<pos-1;i++)
	{
		next = next->link;
	}
		temp->link = next->link;
		next->link = temp;
		return last;
}

NODE delete_pos(NODE last, int pos)
{
	NODE prev,cur;
	int count;
	if(last == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}
	if(last->link == last)
	{
		printf("Item deleted is %d",last->info);
		free(last);
		return last;
	}
	if(pos == 1)
	{
		cur = last;
		last = last->link;
		free(cur);
		return last;
	}
	prev = NULL;
	cur = last->link;
	count = 1;
	while(cur!=last && count!=pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}
	if(cur == NULL)
	{
		printf("Invalid position\n");
		return last;
	}
	prev->link = cur->link;
	free(cur);
	return last;


}

NODE delete_front(NODE last)
{
	NODE next;
	if(last==NULL)
	{
		printf("list empty\n");
		return last;
	}
	if(last->link==last)
	{
		printf("the item deleted is %d",last->info);
		free(last);
		return NULL;
	}
	next = last->link;
	last->link = next->link;
	printf("the item deleted is %d",next->info);
	free(next);
	return last;	
}

NODE delete_rear(NODE last)
{
	NODE prev,next;
	if(last==NULL)
	{
		printf("list empty");
		return last;
	}
	if(last->link==last)
	{
		printf("the item deleted is %d",last->info);
		free(last);
		return NULL;
	}
	prev = NULL;
	next = last->link;
	while(next!=last)
	{
		prev = next;
		next = next->link;
	}
	prev->link = next->link;
	printf("the item deleted is %d",next->info);
	free(next);
	return prev;
}

void display(NODE last)
{
	NODE temp;
	
	if(last==NULL)
	{
		printf("list empty\n");
	}
	else
	{
		temp = last->link;
		while(temp!=last)
		{
			printf("%d\t",temp->info);
			temp = temp->link;
		}
		printf("%d\t",temp->info);
	}
}
int 
main(void)
{
	NODE last;
	
	last = NULL;
	
	int item,choice,pos;
	
	for(;;)
	{
		printf("\n\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Insert at a position\n7.Delete at a position\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1:
				printf("Enter the element\n");
				scanf("%d",&item);
				last=insert_front(last,item);
				break;
			
			case 2:
				printf("Enter the element\n");
				scanf("%d",&item);
				last=insert_rear(last,item);
				break;
			
			case 3:
				last=delete_front(last);
				break;
			
			case 4:
				last=delete_rear(last);
				break;
			
			case 5:
				display(last);
				break;
			
			case 6:
				printf("enter the elment\n");
				scanf("%d",&item);
				printf("Enter the position\n");
				scanf("%d",&pos);
				last=insert_pos(last,item,pos);
				break;

			case 7:
				printf("Enter the position\n");
				scanf("%d",&pos);
				last = delete_pos(last,pos);
				break;
				
			case 8:
				display(last);
				break;
			
			default:
				exit(0);
		}
	}
	
}
