#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head,*tail;

void create_nodes(int n)
{
    int x,i;
    struct node *newn,*temp;
    
    head=malloc(sizeof(struct node));
    if( head==NULL )
        printf("No Memory Alloction!!!\n\n");
    else 
    {
        printf("\n Enter Data : ");
        scanf("%d",&x);
        head->data=x;
        head->next=NULL;
        head->prev=NULL;
        temp=head;
    }

    for( i=2; i<=n ; i++ )
    {
        newn=malloc(sizeof(struct node));
        printf(" Enter Data : ");
        scanf("%d",&x);
        newn->data=x;
        newn->next=NULL;
        temp->next=newn;
        newn->prev=temp;
        temp=newn;
    }

}

void Add_Beg(int d)
{
    struct node *newn=malloc(sizeof(struct node));
    newn->data=d;
    newn->next=head;
    head->prev=newn;
    newn->prev=NULL;
    head=newn;
}

void Add_End(int d)
{
    struct node *newn,*ptr;
    newn=malloc(sizeof(struct node));
    newn->data=d;
    newn->next=NULL;
    newn->prev=NULL;
    ptr=head;

    if( head==NULL )
    {
        head=newn;
        return ;
    }

    while( ptr->next!=NULL )
    {
        ptr=ptr->next;
    }

    ptr->next=newn;
    newn->prev=ptr;
    newn->next=NULL;
    tail=newn;

}

void Add_Pos(int d,int pos)
{
    struct node *newn,*ptr;
    newn=malloc(sizeof(struct node));
    newn->data=d;
    ptr=head;

    if( pos==1 )
    {
        Add_Beg(d);
        return ;
    }

    while( pos>2 )
    {   
        ptr=ptr->next;
        pos--;
    }

    newn->next=ptr->next;
    ptr->next->prev=newn;
    ptr->next=newn;
    newn->prev=ptr;
}

void display()
{
    struct node *ptr;
    int count=0;
    ptr=head;
    while( ptr!=NULL )
    {
        printf(" Data - %d\n",ptr->data);
        ptr=ptr->next;
        count++;
    }

    printf(" No of Nodes : %d\n",count);
}

void del_Beg()
{
    struct node *temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    free(temp);
}

void del_End()
{
    struct node *temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    temp->prev=NULL;
    free(temp);

}


int main()
{
   create_nodes(5);
   // Add_Beg(9);
   // display();
    Add_End(89);
   //  Add_Pos(100,7);
    // Add_Pos(48,5);
    display();
 ///   Add_Beg(69);
 //   display();

    del_Beg();
    del_End();del_End();
    display();

    return 0;
}