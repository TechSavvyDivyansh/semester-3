#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff,power;
    struct Node *next;
}*start1,*start2,*start3;

void create(struct Node **startn)
{
    int n;struct Node *newnode,*temp;
    printf("Enter number of nodes to be inserted:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int coeff,power;
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the coeff:");
        scanf("%d",&coeff);
        printf("Enter the power:");
        scanf("%d",&power);
        newnode->coeff=coeff;
        newnode->power=power;
        
        if(*startn==NULL)
        {
            *startn=newnode;
        }
        else
        {
            temp=*startn;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void link(int c,int p)
{
    struct Node *newnode,*temp;

    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->coeff=c;
    newnode->power=p;
    if(start3==NULL)
    {
        start3=newnode;
    }
    else
    {
        temp=start3;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void add()
{
    struct Node *temp1,*temp2;
    int c,p;

    temp1=start1;
    temp2=start2;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->power>temp2->power)
        {
            c=temp1->coeff;
            p=temp1->power;
            temp1=temp1->next;
            link(c,p);
        }
        else if(temp1->power<temp2->power)
        {
            c=temp2->coeff;
            p=temp2->power;
            temp2=temp2->next;
            link(c,p);
        }
        else
        {
            c=temp1->coeff+temp2->coeff;
            p=temp1->power;
            temp1=temp1->next;
            temp2=temp2->next;
            link(c,p);
        }

        if(temp1==NULL)
        {
            while(temp2!=NULL)
            {
                c=temp2->coeff;
                p=temp2->power;
                temp2=temp2->next;
                link(c,p);
            }
        }
        if(temp2==NULL)
        {
            while(temp1!=NULL)
            {
                c=temp1->coeff;
                p=temp1->power;
                temp1=temp1->next;
                link(c,p);
            }
        }
    }
}

void display(struct Node *start)
{
    struct Node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        printf("%dx^%d + ",temp->coeff,temp->power);
        temp=temp->next;
    }
    printf("%dx^%d",temp->coeff,temp->power);
}

void main()
{
    printf("--Linked List1--");
    create(&start1);
    printf("--Linked List2--");
    create(&start2);

    add();
    display(start3);

}