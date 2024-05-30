#include<stdio.h>

int rear=-1,front=-1,q[50],size=50;

void enqueue(int val)
{
    if(rear==-1)
    {
        rear++;
        front++;
        q[rear]=val;
    }
    else if(rear==size-1)
    {
        printf("Queue full");
    }
    else
    {
        rear++;
        q[rear]=val;
    }
}

void dequeue()
{
    int val;
    if(front==-1)
    {
        printf("Queue empty");
    }
    else if(front==rear)
    {
        val=q[front];
        rear=-1;
        front=-1;
    }
    else
    {
        val=q[front];
        front++;
    }
    
}

void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",q[i]);
    }
}

void main()
{
    enqueue(50);
    enqueue(40);
    enqueue(30);
    enqueue(20);
    dequeue();
    printf("\n");
    display();
    dequeue();
    printf("\n");
    display();
    dequeue();
    printf("\n");
    display();
    dequeue();
    printf("\n");
    display();
    dequeue();
    printf("\n");
    display();
}