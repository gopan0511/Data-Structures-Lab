#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	
	x=(NODE)malloc(sizeof(struct node));
	
	if(x==NULL)
		printf("Unable to allocate memory\n");

	else
		return x;
}

NODE insert(int item, NODE root)
{
	NODE temp,prev,cur;
	int i;
	char dir[10];
	temp = getnode();
	temp -> info = item;
	temp -> l = NULL;
	temp -> r = NULL;
	if(root==NULL) return temp;
	
	printf("Enter the direction\n");
	scanf("%s",dir);
	
	prev = NULL;
	cur = root;
	/* To find the position to insert*/ 
	for(i = 0; i < strlen(dir); i++)
	{
		if(cur == NULL) break;		
		prev = cur;		
		if(dir[i] == 'l')
			cur = cur -> l;
		else
			cur = cur -> r;
	}			
	if(cur!=NULL || i!=strlen(dir))
	{
		printf("Insertion not possible\n");
		free(temp);
		return root;
	}	
	/* Insert the node at leaf level*/
	if(dir[i-1] == 'l')
		prev -> l = temp;
	else
		prev -> r = temp;	
	return root;
}

void preorder(NODE root)
{
	if(root == NULL)
		return;		
	printf("%d",root -> info);
	preorder(root -> l);
	preorder(root -> r);	
}

void inorder(NODE root)
{
	if(root == NULL)
		return;
		
	preorder(root ->l);
	printf("%d",root->info);
	preorder(root -> r);
}

void postorder(NODE root)
{
	if(root == NULL)
		return;
	preorder(root ->l);
	preorder(root -> r);
	printf("%d",root->info);
}

int
main(void)
{
	NODE root;

	root = NULL;

	int ch, item;
	
	for(;;)
	{
		printf("\n1.INSERT\n2.PREORDER\n3.INORDER\n4.POSTORDER\n");
		
		printf("Enter the choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the item to be inserted\n");
				scanf("%d",&item); 
				
				fflush(stdin);
				
				root = insert(item,root);
				break;
				
			case 2:
				printf("Preorder traversal is\n");
				preorder(root);
				printf("\n");
				break;
			
			case 3:
				printf("Inorder traversal is\n");
				inorder(root);
				printf("\n");
				break;
			
			case 4:
				printf("Postorder traversal is\n");
				postorder(root);
				printf("\n");
				break;
			
			default:
				exit(0);
		}
	}	
}



























