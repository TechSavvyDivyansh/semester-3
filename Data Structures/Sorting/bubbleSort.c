#include<stdio.h>

int ar[40],i,j,n=0;
void bubbleSort()
{
    int t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
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

    bubbleSort();
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}