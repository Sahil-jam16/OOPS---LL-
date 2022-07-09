#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *link;
   struct node *prev;
};
void insert_end(struct node *head,int x)
{
    struct node *ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    struct node *neww;
    neww=malloc(sizeof(struct node));
    neww->data=x;
    neww->link=NULL;
    ptr->link=neww;
    neww->prev=ptr;
}
void swap(struct node *head)
{
    struct node *ptr=head;
    struct node *ptr2=head;
    while(ptr2->link!=NULL)
    {
        ptr2=ptr2->link;
    }
    int t;
    t=ptr->data;
    ptr->data=ptr2->data;
    ptr2->data=t;
    printt(head);
}
void printt(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
int main()
{
    int x;
    printf("Enter the first elememt");
    scanf("%d",&x);
    struct node *head=NULL;
    head=malloc(sizeof(struct node));
    head->data=x;
    head->link=NULL;
    head->prev=NULL;
    int choice,n;
    printf("Enter how many elements you needed to insert");
    scanf("%d",&n);
    while(n!=0)
    {
        if(n!=0)
        {
             int x;
             printf("\nEnter the no to be inserted at end:");
             scanf("%d",&x);
             insert_end(head,x);
             n--;
        }
        else
            n=0;
    }
    printt(head);
    swap(head);
    return 0;
}
