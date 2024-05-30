#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;

}*start;


void create()
{
    struct Node *newnode,*temp;
    int n,data;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d",&data);
        newnode->data=data;
        if(start==NULL)
        {
            start=newnode;
            newnode->next=start;
        }
        else
        {
            temp=start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=start;
        }
    }
}

void insert_before()
{
    int data,val;
    struct Node *temp,*newnode,*pre,*t1;
    newnode=(struct Node*)malloc(sizeof(struct Node));

    printf("Enter value before which node is to be inserted:");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&data);
    
    newnode->data=data;
    temp=start;
    while(temp->data!=val)
    {
        pre=temp;
        temp=temp->next;
    }
    if(temp==start)
    {
        t1=start;
        while(t1->next!=start)
        {
            t1=t1->next;
        }
        t1->next=newnode;
        newnode->next=start;
        start=newnode;
    }
    else
    {
        pre->next=newnode;
        newnode->next=temp;
    }    

}

void insert_after()
{
    int data,val;
    struct Node *temp,*newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));

    printf("Enter value after which node is to be inserted:");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&data);
    
    newnode->data=data;
    temp=start;

    while(temp->data!=val)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void delete()
{
    int val;
    struct Node *temp,*pre,*t1;
    printf("Enter value to be deleted:");
    scanf("%d",&val);
    
    temp=start;

    while(temp->data!=val)
    {
        pre=temp;
        temp=temp->next;
    }
    if(temp==start)
    {
        t1=start;
        while(t1->next!=start)
        {
            t1=t1->next;
        }
        t1->next=temp->next;
        start=start->next;
        free(temp);
    }
    else 
    {
        pre->next=temp->next;
        free(temp);
    }
}

void display()
{
    struct Node *temp;
    temp=start;
    while(temp->next!=start)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->",temp->data);
    printf("%d\n",temp->next->data);
}

void main()
{
    create();
    insert_before();
    insert_after();
    display();
    delete();
    display();
}