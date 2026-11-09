#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * createnode(int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct node* insertatbegin(struct node * head,int data)
{
    struct node * newnode =createnode(data);
    if(head==NULL)
    {
        head=newnode;
        head->next=newnode;
    }
    else{
        newnode->next=head->next;
        head->next=newnode;
    }
    return head;
}

void display(struct node *head)
{
    struct node * ptr=head;
    printf("Elements are:\n");
    printf("%d->",ptr->data);
    ptr=ptr->next;
    while(ptr!=head)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",head->data);
}

int main(){
    struct node *head=NULL;
    int ch,n,pos;
    do{
        printf("**************LINKED LIST PROGRAM MENU**************\n");
        printf("1.Insert at begin.\n9.Display.\n10.Exit.\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter data to insert:");
                scanf("%d",&n);
                head=insertatbegin(head,n);
                break;
            case 9:
                display(head);
                break;
        }
    }
    while(ch!=10);
    return 0;
}