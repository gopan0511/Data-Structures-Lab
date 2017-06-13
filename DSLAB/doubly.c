#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}

NODE insf(NODE root,int ele)
{
    NODE temp;
    temp=getnode();
    temp->data=ele;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL){
    return temp;}
    temp->rlink=root;
    root->llink=temp;
    return temp;
}

NODE insr(NODE root,int ele)
{
    NODE temp,curr;
    temp=getnode();
    temp->data=ele;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(root==NULL){return temp;}
    curr=root;
    while(curr->rlink!=NULL)
    {
        curr=curr->rlink;
    }
    curr->rlink=temp;
    temp->llink=curr;
    return root;
}

NODE delf(NODE root)
{
    NODE temp;
    if(root==NULL)
    {
        printf("empety list\n");
        return NULL;
    }
    if(root->rlink==NULL)
    {
        printf("%d is deled\n",root->data);
        return NULL;
    }
     temp=root;
    root=root->rlink;
     printf("%d is deled\n",temp->data);
     free(temp);
     return root;
}

NODE delr(NODE root)
{
    NODE temp,curr;
    if(root==NULL || root->rlink==NULL){return delf(root);}
    temp=root;
    curr=NULL;
    while(temp->rlink!=NULL)
    {
        curr=temp;
        temp=temp->rlink;
    }
    printf("%d is deled",temp->data);
    free(temp);
    curr->rlink=NULL;
    return root;
}

void palin(NODE root)
{
    NODE curr,e,b;
    curr=root;
    int l=1,m=0;
    while(curr->rlink!=NULL)
    {
        l++;
            curr=curr->rlink;
    }
    e=curr;
    b=root;
    while(m<=l/2)
    {
        if(b->data!=e->data)
        {
            printf("not palin\n");
            break;
        }
        b=b->rlink;
        e=e->llink;
        m++;
        //return;
    }
    printf("palin\n");

}

NODE insp(NODE root,int ele,int pos)
{
    int i=1;
    NODE temp,curr,prv,next,last;
    temp=getnode();
    temp->data=ele;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(pos==1){return insf(root,ele);}
    curr=root;
    while(i<pos-1)
    {
        curr=curr->rlink;
        i++;
    }
    if(curr->rlink==NULL){return insr(root,ele);}
    next=curr->rlink;
    temp->rlink=next;
    next->llink=temp;
    temp->llink=curr;
    curr->rlink=temp;
    return root;
}

NODE delp(NODE root,int pos)
{
    int i=1;
    NODE temp,curr,prv,next,last;
    if(root==NULL ||pos==1)
    {
        return delf(root);
    }
    curr=root;
    while(i<pos-1)
    {
        curr=curr->rlink;
        i++;

    }
    prv=curr->rlink;
    printf("%d is deled\n",prv->data);
    curr->rlink=prv->rlink;
    free(prv);
    return root;
}

NODE inso(NODE root,int ele)
{
   NODE prv,temp,curr;
   temp=getnode();
   temp->data=ele;
   temp->llink=NULL;
   temp->rlink=NULL;
   if(root==NULL)
   {
       return temp;
   }
   if(ele<root->data)
   {
       temp->rlink=root;
       root->llink=temp;
       root=temp;
       return root;
   }
   curr=root;
   prv=root;
   while(curr!=NULL)
   {

       if(ele>curr->data){
        prv=curr;
        curr=curr->rlink;}
        else{
    break;}
   }
   prv->rlink=temp;
   temp->llink=prv;
   temp->rlink=curr;
   if(curr!=NULL)
   {
       curr=temp->rlink;
   }
   return root;
}

void disp(NODE root)
{
    NODE temp;
    if(root==NULL)
    {
        printf("nothing to disp\n");
    }
    else
    {
        temp=root;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->rlink;
        }
    }
}

int 
main(void)
{
    int ele,ch,pos,flag;
    NODE root=NULL;
    do
    {
        printf("1 2 3 4 5 6 7 8\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter ele to be inserted\n");
            scanf("%d",&ele);
            root=insf(root,ele);
            break;
        case 2:
            printf("enter ele to be inserted\n");
            scanf("%d",&ele);
            root=insr(root,ele);
            break;
        case 3:
            root=delf(root);
            break;
        case 4:
            root=delr(root);
            break;
        case 5:
            printf("enter ele to be inserted\n");
            scanf("%d",&ele);
            printf("enter pos to be inserted\n");
            scanf("%d",&pos);
            root=insp(root,ele,pos);
            break;
        case 6:
             printf("enter pos to be inserted\n");
            scanf("%d",&pos);
            root=delp(root,pos);
            break;
        case 7:
            disp(root);
            break;
        case 8:
            palin(root);
            break;
        case 10:
            printf("enter ele to be inserted\n");
            scanf("%d",&ele);
            root=inso(root,ele);
            break;
        }
    }while(ch!=9);
}
