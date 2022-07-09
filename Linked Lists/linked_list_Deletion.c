#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void push(struct node* head,int d)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=d;
    new_node->next=head;
    head=new_node;
    printf("*\n");
}

void show(struct node* ptr)
{
    while( ptr->next!=NULL )
    {
        printf("%d - Data \n",ptr->data);
        ptr=ptr->next;
        printf("u");
    }

}


int main()
{
    head=NULL;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,410);
    printf("%d \t\t\t",head->data);

    struct node *ptr=head;
    show(head);

    return 0;
}    