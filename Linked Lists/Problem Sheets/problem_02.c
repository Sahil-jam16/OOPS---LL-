#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void create(int n)
{
    struct node *temp,*newn;
    head=malloc(sizeof(struct node));
    if( head==NULL )
        printf("No Memory Allocated!!!");
    else
    {
    printf(" Enter Data : ");
    scanf("%d",&head->data);
    head->next=NULL;
    temp=head;
    }
    for( int i=2 ; i<=n ; i++)
    {
        newn=malloc(sizeof(struct node));
        printf(" Enter Data : ");
        scanf("%d",&newn->data);
        temp->next=newn;
        newn->next=NULL;
        temp=temp->next;
    }
    printf("\n List Created\n");
}

void display(struct node *temp)
{
    struct node* ptr=temp;
    if( ptr==NULL )
        printf(" Empty List\n\n");

    while( ptr!=NULL )
    {
        printf(" %d->",ptr->data);
        ptr=ptr->next;
    }    
    printf(" NULL\n");
}


void swap_nodes(struct node *list,int a,int b)
{
    struct node *nodeX=list,*prevX=NULL,*nodeY=list,*prevY=NULL,*temp;

    if( a==b )
        return ;
    if( list==NULL )
        return ; 

    while( nodeX!=NULL && nodeX->data!=a )
    {
        prevX=nodeX;
        nodeX=nodeX->next;
    }

    while( nodeY!=NULL && nodeY->data!=b )
    {
        prevY=nodeY;
        nodeY=nodeY->next;
    }

    if( nodeX!=NULL && nodeY!=NULL )
    {
        if( prevX!=NULL )
            prevX->next=nodeY;
        else 
            list=nodeY;

        if( prevY!=NULL )
            prevY->next=nodeX;    
        else 
            list=nodeX;

        temp=nodeX->next;
        nodeX->next=nodeY->next;
        nodeY->next=temp;
    }
    else 
    {
        printf(" No Swapping Possible\n");
        return ;
    }
}

int main()
{
    int x,y;
    create(8);
    display(head);
    printf("\nEnter the data for swapping nodes : ");
    scanf("%d %d",&x,&y);
    swap_nodes(head,x,y);
    display(head);

    return 0;
}