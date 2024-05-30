#include<stdio.h>

int ar[40];


int partition(int ar[],int low,int high)
{
    int pivot=ar[high];
    int i = low-1;

    for(int j=low;j<high;j++)
    {
        if(ar[j]<pivot)
        {
            i++;

            // swap
            int temp;
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
        }
    }
    i++;
    // swap to fix pivot
    int temp;
    temp=ar[i];
    ar[i]=pivot;  //pivot is same as ar[high]
    ar[high]=temp;

    return i;

}

void quickSort(int ar[],int low,int high)
{
    if(low<high)
    {
         int pivotindex=partition(ar,low,high);

         quickSort(ar,low,pivotindex-1);
         quickSort(ar,pivotindex+1,high);
    }
}


void main()
{
    int data;
    int i=0,n=0;
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

    quickSort(ar,0,n-1);
    
    printf("Sorted: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }


}