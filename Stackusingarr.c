#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
int stack[MAX];
int top=-1;

bool isFull()
{
    return top==MAX-1;
}

bool isEmpty()
{
    return top==-1;
}

void push(int data)
{
    if(isFull())
    {
        printf("Stack Overflow!!\n");
    }
    else{
        top++;
        stack[top]=data;
        printf("Elements Pushed successfully!!\n");
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack UnderFlow!!!\n");
    }
    else{
        printf("%d popped from stack\n",stack[top]);
        top--;
    }
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow!!!\n");
    }
    else{
        printf("Top element is:%d\n",stack[top]);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Empty Stack!!\n");
    }
    else
    {
        printf("STACK ELEMENTS ARE:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int ch,data;
    do{
        printf("\n***********STACK USING ARRAY***********\n");
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