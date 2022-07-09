/* 
3.	Given two circular lists sorted in increasing order, create and return a new singly linked list representing the intersection of the two lists.
Example: 
Input: 
First linked list: 	1->2->3->4->6 -> 1
Second linked list:	2->4->6->8 -> 2, 
Output:		2->4->6.

*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head1,*head2,*inter_head;

int count=1;

void create_head1(int n)
{
    struct node *temp=head1,*newn;
    head1=malloc(sizeof(struct node));
    printf(" Enter data : ");
    scanf("%d",&(head1->data));
    head1->next=head1;
    temp=head1;

    for( int i=2 ; i<=n ; i++ )
    {
        newn=malloc(sizeof(struct node));
        printf(" Enter data : ");
        scanf("%d",&(newn->data));
        temp->next=newn;
        newn->next=head1;
        temp=temp->next;
    }
    printf("\n List Created\n");
}

void create_head2(int n)
{
    struct node *temp=head1,*newn;
    head2=malloc(sizeof(struct node));
    printf("\n\n Enter data : ");
    scanf("%d",&(head2->data));
    head2->next=head2;
    temp=head2;

    for( int i=2 ; i<=n ; i++ )
    {   
        
        newn=malloc(sizeof(struct node));
        printf(" Enter data : ");
        scanf("%d",&(newn->data));
        temp->next=newn;
        newn->next=head2;
        temp=temp->next;
    }
    printf("\n List Created\n");
}

void display(struct node* ptr)
{
    struct node *temp=ptr;
    if( head1==NULL )
    {
        printf(" Empty list\n");
        return ;
    }

    do{
        printf(" %d->",temp->data);
        temp=temp->next;
    }while( temp!=ptr );
    printf("%d\n",ptr->data);
}

void add_node(int d)
{
    if( count==1 )
    {
        inter_head=malloc(sizeof(struct node));
        inter_head->data=d;
        inter_head->next=NULL;
    }
    else
    {
    struct node *ptr=inter_head;
    struct node* newn=malloc(sizeof(struct node));
    newn->data=d;

    while( ptr!=NULL )
    {
        ptr=ptr->next;
    }
    ptr->next=newn;
    newn->next=NULL;
    count++;
    }
}
void intersection(struct node* head1,struct node* head2)
{
    struct node *ptr1=head1;
    do 
    {   
        struct node *ptr2=head2;
        do{
            if( ptr1->data==ptr2->data )
            {   
                count++;
                add_node(ptr1->data);
            }
            ptr2=ptr2->next;    
        }while( ptr2!=head2);

        ptr1=ptr1->next;

    }while( ptr1!=head1 );

}

int main()
{
    create_head1(5);
    display(head1);
    create_head2(4);
    display(head2);

    intersection(head1,head2);

    display(inter_head);


    return 0;
}