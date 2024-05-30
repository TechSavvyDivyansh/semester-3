#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top;

void push()
{
    int x,data;struct Node *newnode;
    printf("data:");
    scanf("%d",&data);

    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;

    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }    
}

int pop()
{
    struct Node *temp;
    int x=-1;
    if(top==NULL)
    {
        printf("Stack empty");
    }
    else
    {
        x=top->data;
        temp=top;
        top=top->next;
        free(temp);
    }
    return x;
}

void display()
{
    struct Node *temp;
    temp=top;
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

void main()
{
    push();
    push();
    push();
    int y=pop();
    display();
}