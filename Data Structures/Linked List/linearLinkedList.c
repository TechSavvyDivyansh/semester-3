#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*start;


void create()
{
    int n;struct Node *newnode,*temp;
    printf("Enter number of nodes to be inserted:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data:");
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
        }
    }
}

void insert_before()
{
    int val,data;struct Node* newnode,*temp,*pre;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value before which node is to be inserted:");
    scanf("%d",&val);
    printf("Enter data of newnode:");
    scanf("%d",&data);

    newnode->data=data;

    temp=start;
    while(temp->data!=val && temp->next!=NULL)
    {
        pre=temp;
        temp=temp->next;
    }
    if(temp==start)
    {
        newnode->next=start;
        start=newnode;
    }
    else if(temp->data!=val && temp->next==NULL)
    {
        printf("Value not found\n");
    }
    else
    {
        pre->next=newnode;
        newnode->next=temp;
    }

}

void insert_After()
{
    int val,data;struct Node* newnode,*temp;

    newnode=(struct Node*)malloc(sizeof(struct Node));

    printf("Enter the value after which node is to be inserted:");
    scanf("%d",&val);
    printf("Enter data of newnode:");
    scanf("%d",&data);

    newnode->data=data;

    temp=start;
    while(temp->data!=val && temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->data!=val && temp->next==NULL)
    {
        printf("\nValue not found\n");
    }
    else
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }    
}

void delete()
{
    int val;struct Node *temp,*pre;

    printf("Enter the value in node to be deleted:");
    scanf("%d",&val);

    temp=start;
    while(temp->next!=NULL && temp->data!=val)
    {
        pre=temp;
        temp=temp->next;
    }
    if(temp==start)
    {
        start=start->next;
        free(temp);
    }
    else if(temp->data!=val && temp->next==NULL)
    {
        printf("\nValue not found\n");
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
    if(temp==NULL)
    {
        printf("Empty linked list");
    }
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d\n\n",temp->data);
    }
}


void main()
{
    create();
    printf("Insert before:\n");
    insert_before();
    printf("Insert after:\n");
    insert_After();
    display();
    delete();
    printf("\n");
    display();
}