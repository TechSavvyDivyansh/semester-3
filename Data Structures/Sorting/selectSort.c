#include<stdio.h>

int ar[50],i,j,n=0;

void selection_sort()
{
    int min,t;
    for(i=0;i<(n-1);i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(ar[j]<ar[min])
            {
                min=j;
            }
            
        }
        t=ar[i];
            ar[i]=ar[min];
            ar[min]=t;
    }
    printf("Sorted order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}

void main()
{
    int data;
    i=0;
     do
    {
        printf("Enter element in the array:");
        scanf("%d",&data);
        if(data==0)
            break;
        ar[i]=data;
        i++;
        n++;
    }while(data!=0);

    selection_sort();
}