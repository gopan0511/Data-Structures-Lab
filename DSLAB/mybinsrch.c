#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *l;
	struct node *r;
};

typedef struct node *NODE;

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

NODE insert_bin(NODE root, int item)
{
	NODE temp, prev, cur;
	temp = getnode();
	temp->info = item;
	temp->l = NULL;
	temp->r = NULL;

	if(root == NULL)
	{
			return temp;
	}

	prev = NULL;
	cur = root;

	while(cur!=NULL)
	{
		prev = cur;
		if(cur->info < item)
			cur = cur->r;
		else
			cur = cur->l;
	}

	if(item < prev->info)
		prev->l = temp;
	else
		prev->r = temp;
	return root;

}

void preorder(NODE root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->info);
		preorder(root->l);
		preorder(root->r);
	}
}


void inorder(NODE root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		printf("%d\t",root->info);
		inorder(root->r);
	}
}



void postorder(NODE root)
{
	if(root!=NULL)
	{
		postorder(root->l);
		postorder(root->r);
		printf("%d\t",root->info);
	}
}

int
main(void)
{
	NODE root;
	root = NULL;
	int item,choice;
	for(;;)
	{
		printf("\n\n1.INSERT\n2.PREORDER\n3.INORDER\n4.POSTORDER\n\n");
		printf("Enter the choice of operation\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				fflush(stdin);
				root = insert_bin(root,item);
				break;
			case 2:
				printf("Preorder traversal:\n");
				preorder(root);
				printf("\n");
				break;
			case 3:
				printf("Inorder traversal:\n");
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("Postorder traversal:\n");
				postorder(root);
				printf("\n");
				break;
			default:
				exit(0);
		}
	}
}














