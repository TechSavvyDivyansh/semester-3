#include<stdio.h>

int ar[40],i,j,n=0,test;
void insertionSort()
{
    for(int i=1;i<n;i++)
    {
        test=ar[i];
        j=i-1;
        while(j>=0 && test<ar[j])
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=test;
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

    insertionSort();
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}