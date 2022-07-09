#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *link;
};
void insert_end(struct node *head,int x)
{
    struct node *ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    struct node *neww;
    neww=malloc(sizeof(struct node));
    neww->data=x;
    neww->link=NULL;
    ptr->link=neww;
}
void inter(struct node *head,struct node *head2)
{
    int n;
    int count=0;
    struct node *ptr=head;
    struct node *ptr2=head2;
    struct node *head3;
    head3=malloc(sizeof(struct node));
    head3->link=NULL;
    while(ptr!=NULL && ptr2!=NULL)
    {
        while(ptr!=NULL && ptr2!=NULL)
           {
                 if(ptr->data<ptr2->data)
                    {
                        ptr=ptr->link;
                    }
                else if(ptr->data>ptr2->data)
                    {
                        ptr2=ptr2->link;
                    }
                else
                    {
                        count++;
                        if(count==1)
                        {
                             head3->data=ptr->data;
                        }
                        else
                        {
                               insert_end(head3,ptr->data);
                               ptr=ptr->link;
                        }
                    }
            }
      }
     duplicate(head3);
   // printt(head3);
}
 void duplicate(struct node *head)
 {
    struct node *ptr1=head;
    struct node *ptr2=ptr1->link;
    while(ptr1->link!=NULL)
    {
        if(ptr1->data==ptr2->data)
        {
            ptr1->link=ptr2->link;
            free(ptr2);
            ptr2=ptr1->link;
        }
        ptr1=ptr1->link;
    }
    printt(head);
 }
void printt(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
void add(struct node *head)
{
    int x;
    printf("Enter the first elememt");
    scanf("%d",&x);
    head->data=x;
    int n;
    printf("Enter how many elements you needed to insert");
    scanf("%d",&n);
    while(n!=0)
    {
        if(n!=0)
        {
             int x;
             printf("\nEnter the no to be inserted at end:");
             scanf("%d",&x);
             insert_end(head,x);
             n--;
        }
        else
            n=0;
    }
}
int main()
{
    struct node *head=NULL;
    head=malloc(sizeof(struct node));
    head->link=NULL;
    add(head);
    struct node *head2=NULL;
    head2=malloc(sizeof(struct node));
    head2->link=NULL;
    add(head2);
    printt(head);
    printt(head2);
    inter(head,head2);
    return 0;
}
