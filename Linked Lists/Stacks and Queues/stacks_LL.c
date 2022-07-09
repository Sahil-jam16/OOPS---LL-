#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top;


void push(int d)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=d;
    if( top==NULL )
    {    top=temp;
        top->next=NULL;
        return ;
    }

    temp->next=top;
    top=temp;
}

void pop()
{
    if( top==NULL )
    {
        printf(" Stack underflow \n");
        return ;
    }
    
    struct node *temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
    printf(" Popped\n");
}

static inline void peek() 
{
    printf(" Top = %d\n",top->data);
}

void show()
{
    struct node *temp=top;

    if( temp==NULL )
    {
        printf("\nEmpty Stack\n\n");
        return ;
    }
    while( temp!=NULL )
    {
        printf(" %d-> ",temp->data);
        temp=temp->next;
        if( temp==NULL )
            printf("NULL\n\n");
    }
    
}

int main()
{
    int choice=0;     
    printf("\n\tSTACKS using linked list\n");  
    while(choice != 4)  
    {  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                int d;
                printf(" Enter Data : ");
                scanf("%d",&d);
                push(d);  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                show();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    };  
}  

    return 0;
}