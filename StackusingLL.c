#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack * next;
};

struct stack* top=NULL;

void push(int data){
    struct stack * newnode=(struct stack *)malloc(sizeof(struct stack));
    if(newnode==NULL)
    {
        printf("Allocation failed!Stack Overflow!");
        return;
    }
    newnode->data=data;
    newnode->next=top;
    top=newnode;
    printf("Element Pushed Successfully!\n");
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack UnderFlow!!!\n");
    }
    else{
        printf("Element Popped %d successfully!\n",top->data);
        struct stack* n =top;
        top=top->next;
        free(n);
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("Stack Empty!!!\n");
    }
    else{
        printf("Top ELement is:%d\n",top->data);
    }
}

void display()
{
    if(top==NULL)
        printf("Stack Empty!!\n");
    else{
    printf("Stack Elements are:\n");
    struct stack *temp=top;
    while(temp!=NULL && temp->next!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
}

int main()
{
   
    int ch,data;
    do{
        printf("\n***********STACK USING LINKED LIST***********\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Value to Push:");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting....");
        }
    }
    while(ch!=5);
    return 0;
}