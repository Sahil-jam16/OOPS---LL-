#include<stdio.h>
#include<stdlib.h>

struct node                         //Structure for the linked list.
{
    int data;
    struct node* link;
};

int main()
{
    struct node *head=NULL;                 //Creating a Head for the starting of linked list.
    head=(struct node*)malloc(sizeof(struct node));     //Allocating memory for the head node and assigning the created node to head.

    head->data=50;                  //Giving data and giving the link as NULL.
    head->link=NULL;

    printf("Data : %d\n\n\n",head->data);

    struct node *next=malloc(sizeof(struct node));  //Creating a second node and assigning it with data and linking it with the head.
    next->data=60;
    head->link=next;
    next->link=NULL;

    next=malloc(sizeof(struct node));           //Creating an new node with existing "next" pointer .( 3rd node is created )
    next->data=70;                              
    next->link=NULL;

    head->link->link=next;                      //Second node is linked to third node with head pointer. ( No need of extra pointer )

    return 0;
}