#include<stdio.h> 
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* circular_singly(int d)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->next=temp;
    return temp;
}

struct node* insert_begin(struct node *tail,int d)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=d;
    new_node->next=tail->next;
    tail->next=new_node;
    return new_node;
}

struct node* insert_end(struct node* tail,int d)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=d;
    new_node->next=tail->next;
    tail->next=new_node;
    tail=tail->next; 
    return new_node;
}
 
struct node* insert_after(struct node* tail,int d,int pos)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=d;
    new_node->next=NULL;

    struct node* p=tail->next;

    while( pos>2 )
    {
        p=p->next;
        pos--;
    } 

    new_node->next=p->next;
    p->next=new_node;

    if( p==tail )
    {
        tail=tail->next;
    }

    return tail;
    
} 


void print_list(struct node* tail)
{
    struct node* ptr=tail->next;
    do{
        printf("%d - data\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}

int main()
{
    struct node* head;
    head=circular_singly(15);
    head=insert_begin(head,78);
    head=insert_begin(head,20);
    head=insert_begin(head,17);
    head=insert_end(head,100);
    head=insert_end(head,200);
    print_list(head);
    head=insert_after(head,69,3);
    head=insert_after(head,345,5);

 

    return 0;
}