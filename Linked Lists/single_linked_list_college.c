#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head;

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
        head->link=NULL;
        temp=head;
    }

    for(  i=2; i<=n; i++ )
    {
        newn=malloc(sizeof(struct node));
        printf(" Enter Data : ");
        scanf("%d",&x);
        newn->data=x;
        newn->link=NULL;
        temp->link=newn;
        temp=temp->link;
    }

    printf("\n\n");

}

void display(struct node* temp)
{
    struct node* ptr=temp;
    int count=0;
     while( ptr!=NULL )
    {
        printf(" %3d - data\n",ptr->data);
        ptr=ptr->link;
        count++;
    }
    printf("No of Nodes : %d     END\n\n",count);
}

void Add_Beg(int d)
{
    struct node* newn=malloc(sizeof(struct node));
    newn->data=d;
    newn->link=head;
    head=newn;
};

void Add_End(struct node* head,int d)
{
    struct node* newn=malloc(sizeof(struct node));
    newn->data=d;
    newn->link=NULL;
    if( head==NULL )
    {
       head=newn;
          return ;
    }
    struct node* temp=head;
    while( temp->link!=NULL  )
    {
        temp=temp->link;
    }
    temp->link=newn;
};

struct node* Add_Pos(int d,int pos)
{
    struct node* newn=malloc(sizeof(struct node));
    newn->data=d;
    newn->link=NULL;

    if( pos==1 )
    {
        newn->link=head;
        head=newn;
    }

    struct node* ptr=head;

    pos--;
    while( pos>1 )
    {
        ptr=ptr->link;
        pos--;
    }
    newn->link=ptr->link;
    ptr->link=newn;
}

void reverse_list()
{
    struct node *curr,*prev;
    prev=head;
    curr=head->link;
    head=head->link;

    prev->link=NULL;     // Head is made as the last node by linking it to NULL.

    while( head!=NULL )
    {   
        head=head->link;            //linking the node in previous order.
        curr->link=prev;
        prev=curr;
        curr=head;        
    }

    head=prev;          //Last node is made as the head.
}

void delete_head()
{
    struct node *temp=head;
    head=head->link;
    temp->link=NULL;
    free(temp);
}

void delete_last()
{
    struct node *ptr,*tail;
    
    if( head==NULL )
    {
        printf("Empty list\n\n");
        return ;
    }
    
    ptr=head;
    while( ptr->link->link!=NULL )
    {
        ptr=ptr->link;
    }
    
    tail=ptr->link;
    ptr->link=NULL;
    free(tail);
}

void delete_pos(int pos)
{
    struct node *ptr,*del;
    ptr=head;
    del=head;

    if( pos==1 )
    {
        delete_head();
        return;
    }
    while( pos>1 )
    {
        ptr=del;
        del=del->link;
        pos--;
    }

    ptr->link=del->link;
    del->link=NULL;
    free(del);
}




int main()
{
    create(8);
   // Add_Beg(69);
  //  Add_Beg(70);
   // Add_Pos(9,3);
   //  Add_Pos(40,5);
    display(head);
    delete_pos(5);
    display(head);
    delete_pos(1);
    delete_pos(1);
    display(head);

    return 0;
}
