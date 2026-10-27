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

struct node *insertatnode(struct node * head, int data,int n)
{
    struct node * temp=createnode(data);
    struct node * temp1=head;
    if(n==1)
    {
        head=insertatbegin(head,data);
    }
    else
    {
        int i=0;
        while(i<n-2)
        {
            temp1=temp1->next;
            i++;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    return head;
}

struct node * deleteatbegin(struct node *head)
{
    if(head==NULL)
        printf("List is Empty\n");
        return head;
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node * deleteatend(struct node *head)
{
    if(head==NULL)
        printf("List is Empty\n");
        return head;
    while(head->next->next!=NULL)
    {
        head=head->next;
    }
    head->next=NULL;
    return head;
}

struct node * deletenthnode(struct node *head,int pos)
{
    if(head==NULL)
    {    
        printf("List is Empty\n");
        return head;
    }
    struct node * temp=head;
    if(pos==1)
        return deleteatbegin(head);
    int i=0;
    while(i<pos-2)
    {
        temp=temp->next;
        i++;
    }
    struct node* temp1=temp->next;
    temp->next=temp->next->next;
    free(temp1);
    return head;
}

struct node* deletevalue(struct node * head,int value)
{
    if(head==NULL)
    {    
        printf("List is Empty\n");
        return head;
    }
    if (head->data == value)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node *p = head;
    while (p->next != NULL && p->next->data != value)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        printf("Value not found\n");
        return head;
    }
    struct node *temp = p->next;
    p->next = temp->next;
    free(temp);

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
        printf("1.Insert at Begininng.\n2.Insert at End.\n3.Insert at nth node.\n4.Delete at begin.\n5.Delete at end.\n6.Delete at nth node.\n7.Delete node with value.\n9.Display.\n10.Exit.\n");
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
            case 3:
                printf("Enter Element to insert:");
                scanf("%d",&n);
                printf("Enter pos to insert at:");
                scanf("%d",&pos);
                head=insertatnode(head,n,pos);
                break;
            case 4:
                head=deleteatbegin(head);
                printf("Element deleted\n");
                break;
            case 5:
                head=deleteatend(head);
                printf("Element deleted\n");
                break;
            case 6:
                printf("Enter element position to delete:");
                scanf("%d",&pos);
                head=deletenthnode(head,pos);
                printf("Element deleted\n");
                break;
            case 7:
                printf("Enter Value to delete:");
                scanf("%d",&n);
                head=deletevalue(head,n);
                break;
            case 9:
                printf("Elements are:\n");
                display(head);
                break;
            case 10:
                printf("Exiting....\n");
            default:
                break;
        }
    }
    while(ch!=10);
    return 0;
}