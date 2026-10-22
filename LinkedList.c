#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *createnode(int data)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;

}

struct node *insertatbegin(struct node * head, int data)
{
    struct node * temp=createnode(data);
    temp->next=head;
    head=temp;
    return head;
}

struct node *insertatend(struct node * head, int data)
{
    struct node * temp1=head;
    struct node * temp=createnode(data);
    if(head==NULL)
        return temp;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
    return head;
}

struct node *insertafternode(struct node * head, int data,int n)
{
    struct node * temp=createnode(data);
    struct node * temp1=head;
    int i=0;
    while(i<n-1)
    {
        temp1=temp1->next;
        i++;
    }
    temp->next=temp1->next;
    temp1->next=temp;
    return head;
}

void display(struct node * head)
{
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node * head=NULL;
    int ch,n,pos;
    do
    {   
        printf("**************LINKED LIST PROGRAM MENU**************\n");
        printf("1.Insert at Begininng.\n2.Insert at End.\n3.Insert before nth node\n4.Insert at nth node\n5.Insert after nth node.\n6.Display.\n7.Exit.\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Element to insert:");
                scanf("%d",&n);
                head=insertatbegin(head,n);
                break;
            case 2:
                printf("Enter Element to insert:");
                scanf("%d",&n);
                head=insertatend(head,n);
                break;
            case 5:
                printf("Enter Element to insert:");
                scanf("%d",&n);
                printf("Enter pos to insert after:");
                scanf("%d",&pos);
                head=insertafternode(head,n,pos);
                break;
            case 6:
                printf("Elements are:\n");
                display(head);
                break;
            case 7:
                printf("Exiting....\n");
            default:
                break;
        }
    }
    while(ch!=7);
    return 0;
}