#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void count_nodes(struct node *p)
{
    int count=0;
    if ( p==NULL ) 
        printf("Linked list is empty!!\n");

    struct node *ptr=NULL;
    ptr=p;

    while( p!=NULL )
    {
        count++;
        ptr=ptr->next;
    }
    printf("\n%d Nodes ",count);
}

struct node* insert_end(struct node *p,int val)
{
    struct node *temp=malloc(sizeof(struct node));;
    temp->data=val;
    temp->next=NULL;

    p->next=temp;
    printf("*");
    return p;    
}



int main()
{
    struct node *head;
    head=malloc(sizeof(struct node));
    head->data=10;
    head->next=NULL;

    struct node *ptr=head;

    ptr=insert_end(ptr,20);
    ptr=insert_end(ptr,30);
    ptr=insert_end(ptr,40);
    ptr=insert_end(ptr,50);

   ptr=head;

   while( ptr!=NULL )
   {
       printf("\nData : %d",ptr->data);
       ptr=ptr->next;
   }

    
    
    return 0;
}