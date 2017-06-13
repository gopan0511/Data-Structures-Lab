#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* l;
	struct node* r;
};

typedef struct node* NODE;

NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	if(x == NULL)
	{
		printf("MEMORY CANNOT BE ALLOCATED\n");
		return NULL;
	}
	return x;
}

NODE insert_pos(NODE root, int pos, int item)
{
	NODE temp,prev,cur;
	int n = 1;
	
	temp = getnode();
	temp->info = item;
	temp->l = NULL;
	temp->r = NULL;
	
	if(root == NULL)
		return temp;
	
	if(pos == 1)
	{
		temp->r = root;
		root->l = temp;
		return temp;
	}
	
	cur = root;
	while(cur!=NULL && n<pos)
	{
		prev = cur;
		cur = cur->r;
		n++;
	}
	temp->l = prev;
	temp->r = cur;
	prev->r = temp;
	cur->l = temp;

	return root;
}

NODE delete_pos(NODE root, int pos)
{
	NODE temp,cur;
	int n = 1;
	if(root == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}
	if(pos == 1)
	{
		temp = root;
		root = root->r;
		if(root!=NULL)
			root->l = NULL;
		printf("Deleted item =%d",temp->info);
		free(temp);
		return root;
	}
	cur = root;
	while(cur!=NULL && n<pos)
	{
		temp = cur;
		cur = cur->r;
		n++;
	}	
	if(cur == NULL)
	{
		printf("Position out of range\n");
		return root;
	}
	temp->r = cur->r;
	if(cur->r!=NULL)
		(cur->r)->l = temp;
	printf("Deleted item =%d",cur->info);
	free(cur);
	return root;
}

void display(NODE root)
{
	NODE temp;
	if(root == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp = root;
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp = temp->r;
		}
	}
}

int
main(void)
{
	NODE root;
	root = NULL;
	int choice, pos, item;
	for(;;)
	{
		printf("\n\n1.INSERT\n2.DELETE\n3.DISPLAY\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				printf("Enter the position\n");
				scanf("%d",&pos);
				root = insert_pos(root,pos,item);
				break;

			case 2:
				printf("Enter the position to delete from\n");
				scanf("%d",&pos);
				root = delete_pos(root,pos);
				break;

			case 3:
				display(root);
				break;

			default:
				exit(0);
		}
	}
}

























