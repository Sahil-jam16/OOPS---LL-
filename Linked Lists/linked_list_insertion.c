#include<stdio.h>
#include<stdlib.h>

struct node                         //Structure for the linked list.
{
    int data;
    struct node* link;
};

void count_nodes(struct node *p)        //Function to count no of nodes in the list.
{
    int count=0;
    if ( p==NULL )
        printf("Linked list is Empty!!\n\n");
    
    struct node *ptr=NULL;
    ptr=p;

    while( ptr!=NULL )
    {
        count++;
        ptr=ptr->link;
    }
    printf("No of Nodes : %d\n",count);
}

void print_data(struct node* p)             //Function to print the data from the linked list.
{
    if( p==NULL )
        printf("Linked list is empty!!\n\n");
    struct node *ptr=NULL;
    ptr=p;

    while( p!=NULL )
    {
        printf("Data : %d\n",ptr->data);
        ptr=ptr->link;
    }

}

void insert_end(struct node *p,int val)         //Function to add at the end of the linked list.
{
    struct node *temp=NULL,*ptr=NULL;       //temp node is created and value is pushed to it with link as NULL.
    temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->link=NULL;

    ptr=p;                                  
    while( ptr->link!=NULL )            //Traverse the linked list.j
    {
        ptr=ptr->link;
    }
    ptr->link=temp;                     //Append the linked list with the new created node.


}

int main()
{

    struct node *head=NULL;                 //Creating a Head for the starting of linked list.
    head=(struct node*)malloc(sizeof(struct node));     //Allocating memory for the head node and assigning the created node to head.

    head->data=50;                  //Giving data and giving the link as NULL.
    head->link=NULL;
    //printf("Data : %d\n\n\n",head->data);

    struct node *next=malloc(sizeof(struct node));  //Creating a second node and assigning it with data and linking it with the head.
    next->data=60;
    next->link=NULL;
    head->link=next;

    next=malloc(sizeof(struct node));           //Creating an new node with existing "next" pointer .( 3rd node is created )
    next->data=70;                              
    next->link=NULL;

    head->link->link=next;                      //Second node is linked to third node with head pointer. ( No need of extra pointer )


    count_nodes(head);
    //print_data(head);
    insert_end(head,80);
    count_nodes(head);
    print_data(head);

    return 0;
}