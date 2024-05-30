#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front,*rear;

void enqueue()
{
    int x;
    struct Node *newnode,*temp;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value to be inserted:");
    scanf("%d",&x);
    newnode->data=x;

    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {   
        rear->next=newnode;
        rear=rear->next;
    }
}

void dequeue()
{
    int x;
    struct Node *temp;
    if(front==NULL)
    {
        printf("Queue empty");
    }
    else if(front==rear)
    {
        x=front->data;
        temp=front;
        printf("%d is deleted",x);
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        x=front->data;
        printf("%d is deleted",x);
        temp=front;
        front=front->next;
        free(temp);
    }
}

void display()
{
    struct Node *temp;
    temp = front;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void main()
{
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    display();
}