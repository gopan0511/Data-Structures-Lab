#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *l ,*r;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("Memory cannot be allocated\n");
		return NULL;
	}
	
	return x;
}

NODE iorder(NODE root, int item)
{
	NODE cur, prev, temp;
	temp = getnode();
	temp->info = item;
	temp->l = NULL;
	temp->r = NULL;
	if(root == NULL)
		return temp;
	if(root->info > item)
	{	
		temp->r = root;
		root->l = temp;
		return temp;
	}
	
	prev = NULL;
	cur = root;
	while(cur!=NULL && item > cur->info)
	{	
		prev = cur;
		cur = cur->r;
	}
	
	if(cur!=NULL)
		cur->l = temp;
	
	temp->r = cur;
	prev->r = temp;
	temp->l = prev;
	return root;
}

void display(NODE root)
{
	NODE temp;
	if(root == NULL)
		printf("Nothing to print\n");
	
	temp = root;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp = temp->r;
	}
	printf("\n");
}

int
main(void)
{
	NODE root;
	root = NULL;
	int item,ch;
	
	for(;;)
	{
		printf("\n1.INPUT ELEMENT IN LIST\n2.DISPLAY\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				root = iorder(root,item);
				break;
				
			case 2:
				display(root);
				break;
				
			default:
				exit(0);
		}
	}
}




















