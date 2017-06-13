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
		return NULL;
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

























