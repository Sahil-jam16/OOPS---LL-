#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head,*tail,*odd_head,*even_head,*even_ptr,*odd_ptr;
int count_e=1,count_o=1;

void push(struct node* ptr,int d)
{

    struct node* newn=malloc(sizeof(struct node));
    newn->data=d;
    newn->next=ptr;
    ptr=newn;
}

void pop()
{
    struct node *temp=head;
    temp->next=NULL;
    head=head->next;
    free(temp);

}

void print_list(struct node* ptr)
{
    struct node* temp=ptr;
    if( ptr==NULL )
    {
        printf("Empty List\n");
        return ;
    }
    while( temp!=NULL )
    {
        printf(" %d->",temp->data);
        temp=temp->next;
    }
     printf(" NULL\n\n");


}

void create(int n)
{
    int x,i;
    struct node *newn,*temp;

    head=malloc(sizeof(struct node));
    if( head == NULL )
        printf("No memory\n");
    else
    {
        printf("\n Enter Data : ");
        scanf("%d",&x);
        head->data=x;
        head->next=NULL;
        temp=head;
    }

    for(  i=2; i<=n; i++ )
    {
        newn=malloc(sizeof(struct node));
        printf(" Enter Data : ");
        scanf("%d",&x);
        newn->data=x;
        newn->next=NULL;
        temp->next=newn;
        temp=temp->next;
    }

    printf("\n\n");

}

void even_push(int d)
{
    if( count_e==1 )
    {
        even_head=malloc(sizeof(struct node));
        even_head->data=d;
        even_head->next=NULL;
        even_ptr=even_head;
    }
    else
    {
        struct node* newn=malloc(sizeof(struct node));
        newn->data=d;
        newn->next=NULL;
        even_ptr->next=newn;
        even_ptr=newn;
    }

}

void odd_push(int d)
{
    if( count_o==1 )
    {
        odd_head=malloc(sizeof(struct node));
        odd_head->data=d;
        odd_head->next=NULL;
        odd_ptr=odd_head;
    }
    else
    {
        struct node* newn=malloc(sizeof(struct node));
        newn->data=d;
        newn->next=NULL;
        odd_ptr->next=newn;
        odd_ptr=newn;
    }

}


int main()
{
    create(10);
    print_list(head);

    struct node* ptr=head;
    while( ptr!=NULL )
    {
        if( (ptr->data)%2==0 )
        {
            even_push(ptr->data);
            count_e++;
        }
        else if( ptr->data%2!=0 )
        {
            odd_push(ptr->data);
            count_o++;
        }

        ptr=ptr->next;
    }

    printf("EVEN LIST : \n");
    print_list(even_head);
    printf("ODD LIST : \n");
    print_list(odd_head);
    return 0;


}