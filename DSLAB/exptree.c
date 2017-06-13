//This is a program on evaluation of expression tree
//When you compile this program, try this:
//gcc exptree.c -lm (since you are including math.h header file)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

//Creating of a tree
NODE create_tree(char postfix[])
{
	NODE temp, st[20];
	int i, k;
	char symbol;
	for(i = 0,k = 0;(symbol = postfix[i])!='\0';i++)
	{
		temp = getnode();
		temp->info = symbol;
		temp->l = NULL;
		temp->r = NULL;
		if(isalnum(symbol))
			st[k++] = temp;
		else
		{
			temp->r = st[--k];
			temp->l = st[--k];
			st[k++] = temp;
        }
	}
	return st[--k];
}

//Evaluation of the tree
float eval(NODE root)
{
	float num;
	switch(root->info)
	{
		case '+':
			return (eval(root->l) + eval(root->r));

		case '-':
			return (eval(root->l) - eval(root->r));

		case '*':
			return (eval(root->l) * eval(root->r));

		case '/':
			return (eval(root->l)/eval(root->r));

		case '^':
		case '$':
			return pow(eval(root->l),eval(root->r));

		default:
			if(isalpha(root->info))
			{
				printf("Enter the number\n");
				scanf("%f",&num);
				return num;
			}
			else
				return root->info-'0';//Conversion from ASCII.

	}
}


int
main(void)
{
	NODE root;
	root = NULL;
	char postfix[20]; float res;
	printf("Enter a calid postfix expression\n");
	scanf("%s",postfix);
	root = create_tree(postfix);
	res = eval(root);
	printf("Result =%f",res);
}








