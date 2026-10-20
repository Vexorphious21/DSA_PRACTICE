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
    int ch,n;
    do
    {   
        printf("**************LINKED LIST PROGRAM MENU**************\n");
        printf("1.Insert at Begininng.\n2.Display.\n3.Exit.\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Element to insert:");
                scanf("%d",&n);
                head=insertatbegin(head,n);
                break;
            case 2:
                printf("Elements are:\n");
                display(head);
                break;
            case 3:
                printf("Exiting....\n");
            default:
                break;
        }
    }
    while(ch!=3);
    return 0;
}