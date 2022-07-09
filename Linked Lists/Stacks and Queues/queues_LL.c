#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void Enqueue(int d)
{
    printf("\n");
    struct node *temp=malloc(sizeof(struct node));
    temp->data=d;

    if( front==NULL )
    {
        front=temp;
        front->next=NULL;
        rear=temp;
        rear->next=NULL;
        return ;
    }    
    rear->next=temp;
    rear=temp;
    rear->next=NULL;
}

void Dequeue()
{
    if( front==NULL )
    {
        printf(" Queue Underflow\n");
        return ;
    }
    struct node *temp=front;
    front=front->next;
    temp->next=NULL;
    free(temp);
}

void show()
{
    struct node *ptr=front;
    if( ptr==NULL )
    {
        printf(" Empty Queue\n");
        return;
    }

    while( ptr!=NULL )
    {
        printf(" %d->",ptr->data);
        ptr=ptr->next;
        if( ptr==NULL )
            printf(" NULL\n\n");
    }
}


int main()
{   
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Dequeue();
    Enqueue(4);
    Enqueue(5);
    Dequeue();
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();


    show();
    
    return 0;
}