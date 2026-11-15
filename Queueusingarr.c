#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front=-1,rear=-1;

void enqueue(int data)
{
    if(rear==SIZE-1)
    {
        printf("Queue Full!!\n");
        return;
    }
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=data;
    printf("%d enqueued successfully!!\n",data);
}

void dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Queue Empty!!\n");
        return;
    }
    printf("%d dequeued!\n",queue[front]);
    front++;
    if(front > rear)
    {
        front = rear = -1;
    }
}

void peek()
{
    if(front==-1|| front>rear)
    {
        printf("Queue Empty!!\n");
        return;
    }
    printf("Front Element:%d\n",queue[front]);
}

void display()
{
    if(front==-1|| front>rear)
    {
        printf("Queue Empty!!\n");
        return;
    }
    printf("Queue Elements!!\n");
    for(int i=front;i<rear+1;i++)
    {
        printf("%d\t",queue[i]);
    }
    printf("\n");
}

int main()
{
    int ch,data;
    do{
        printf("\n***********QUEUE USING ARRAY***********\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Value to Enqueue:");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting....");
                break;
            default:
                printf("Invalid choice!!\n");
        }
    }
    while(ch!=5);
    return 0;
}