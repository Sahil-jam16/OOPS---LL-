#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;

};

void show(struct node* temp)
{
    struct node* ptr=temp;
    while( ptr->next!=NULL )
    {
        printf("\n%d - Value.",ptr->data);
        ptr=ptr->next;
    }
}

struct node* insert_begin(struct node* head,int d)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=d;
    ptr->next=NULL;

    ptr->next=head;
    head=ptr;
    return head;

}


int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=10;
    head->next=NULL;

    struct node *second=malloc(sizeof(struct node));
    second->data=20;
    second->next=NULL;
    
    head->next=second;
  
    head=insert_begin(head,30);
    head=insert_begin(head,66);
    head=insert_begin(head,2222);
    head=insert_begin(head,96);

   
    second=head;

    while(second->next!=NULL)
    {
        printf("Data : %d\n",second->data);
        second=second->next;
    }

    return 0;
}