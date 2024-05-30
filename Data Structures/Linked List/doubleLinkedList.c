#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev,*next;

}*start;


void create()
{
    struct Node *newnode,*temp;
    int n,data;
    printf("Enter the number of node:");
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
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;

        }
    }
}

void insert_begin()
{
    struct Node *newnode,*temp;
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;

    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        newnode->next=start;
        start->prev=newnode;
        start=newnode;
    }    
    
}

void insert_before()
{
    struct Node *newnode,*temp;
    int val,data;
    printf("Enter the value before which data is to be inserted:");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&data);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    temp=start;
    while(temp->next!=NULL && temp->data!=val)
    {
        temp=temp->next;
    }
    if(temp==start)
    {
        start->prev=newnode;
        newnode->next=start;
        start=newnode;
    }
    else if(temp->data!=val && temp->next==NULL)
    {
        printf("\nValue not found\n");
    }
    else
    {
        newnode->prev=temp->prev;
        newnode->next=temp;
        newnode->prev->next=newnode;
        newnode->next->prev=newnode;
    }
}

void insert_After()
{
    struct Node *newnode,*temp;
    int val,data;
    printf("Enter the value after which data is to be inserted:");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&data);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    temp=start;
    while(temp->next!=NULL && temp->data!=val)
    {
        temp=temp->next;
    }
    if(temp->data!=val && temp->next==NULL)
    {
        printf("\nValue not found\n");
    }
    else if(temp->next==NULL)
    {
        newnode->prev=temp;
        temp->next=newnode;
    }
    else
    {
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}


void full_display()
{
    struct Node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

void forwardDisplay()
{
    struct Node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

void backwardDisplay()
{
    struct Node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=start)
    {
        printf("%d->",temp->data);
        temp=temp->prev;
    }
    printf("%d\n",temp->data);

}

void delete()
{
    struct Node *temp;
    int val;
    printf("Enter the value to be deleted:");
    scanf("%d",&val);

    temp=start;
    while(temp->next!=NULL && temp->data!=val)
    {
        temp=temp->next;
    }
    if(temp==start)
    {
        start=temp->next;
        start->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
    else if(temp->next==NULL && temp->data!=val)
    {
        printf("\nValue not found\n");
    }
    else if(temp->next==NULL && temp->data==val)
    {
        temp->prev->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}


void main()
{
    create();
    printf("\n--Insert Before--\n");
    insert_before();
    printf("\n--Insert After--\n");
    insert_After();
    printf("\n--Insert Begin--\n");
    insert_begin();
    printf("Display:");
    full_display();
    delete();
    printf("\n--DISPLAY--\n");
    full_display();
    forwardDisplay();
    backwardDisplay();
}



