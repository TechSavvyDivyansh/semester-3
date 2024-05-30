#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define size 10

struct Node
{
    int data;
    struct Node *next;
}*HashTable[size];


void initializeHashTable()
{
    for(int i=0;i<size;i++)
    {
        HashTable[i]=NULL;
    }
}

int Hashfn(int key)
{
    int square=key*key;
    int temp=square,count=0,divisor,middle_digit;
    do
    {
        temp=temp/10;
        ++count;
    } while (temp!=0);
    int mid_index=count/2;

    if(count%2==0)
    {
        divisor=pow(10,mid_index-1);
    }
    else
    {
        divisor=pow(10,mid_index);
    }

    middle_digit=(square/divisor)%100;
    int index=middle_digit%size;
    return index;
}

void insert(int key)
{
    int index=Hashfn(key);

    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=key;

    if(HashTable[index]==NULL)
    {
        HashTable[index]=newnode;
    }
    else
    {
        struct Node *temp;
        temp=HashTable[index];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}


int search(int key)
{
    int index=Hashfn(key);

    struct Node *temp;
    temp=HashTable[index];

    while(temp->next!=NULL && temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp->data==key)
    {
        return 1;
    }
    else if(temp->next==NULL && temp->data==key)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Index %d:", i);
        struct Node *temp = HashTable[i];
        while (temp != NULL)
        {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main()
{
    initializeHashTable();

    int choice, key;

    do
    {
        printf("\nHashing Techniques Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display Hash Table\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(key))
            {
                printf("Key %d found in the hash table.\n", key);
            }
            else
            {
                printf("Key %d not found in the hash table.\n", key);
            }
            break;

        case 3:
            display();
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}


