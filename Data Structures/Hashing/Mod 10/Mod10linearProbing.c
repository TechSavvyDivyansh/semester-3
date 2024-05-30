#include<stdio.h>
#define size 10

int HashTable[size];

void initializeHashTable()
{
    for (int i = 0; i < size; i++)
    {
        HashTable[i] = NULL;
    }
}
                                                                                                        
void insert(int key)
{
    int hashfn=key%10;

    if(HashTable[hashfn]==NULL)
    {
        HashTable[hashfn]=key;
    }
    else
    {
        int i=1,index;
        do
        {
            index=(hashfn+i)%10;
            i++;
        }while(i<size && HashTable[index]!=0);
        if(i==size)
        {
            printf("\nHashTable full\n");
        }
        else
        {
            HashTable[index]=key;
        }
    }
}
                                                                                                        
void display()
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("INDEX %d :%d\n",i,HashTable[i]);
    }
}

int search(int key)
{
    for(int i=0;i<size;i++)
    {
        if(HashTable[i]==key)
            return 1;
    }
    return 0;
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


