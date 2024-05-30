#include<stdio.h>

int ar[40];

void conquer(int ar[], int start, int mid, int end)
{
    int merged[end - start + 1];

    int index1 = start;
    int index2 = mid + 1;
    int x = 0;

    while (index1 <= mid && index2 <= end)
    {
        if (ar[index1] <= ar[index2])
        {
            merged[x] = ar[index1];
            x++;
            index1++;
        }
        else
        {
            merged[x] = ar[index2];
            x++;
            index2++;
        }
    }
    while (index1 <= mid)
    {
        merged[x] = ar[index1];
        x++;
        index1++;
    }
    while (index2 <= end)
    {
        merged[x] = ar[index2];
        x++;
        index2++;
    }

    int j;
    for (int i = start, j = 0; i <= end; i++, j++)
    {
        ar[i] = merged[j];
    }
}




void divide(int ar[],int start,int end)
{
    if(start>=end)
    {
        return;
    }

    int mid;
    mid=(start+end)/2;
    divide(ar,start,mid);
    divide(ar,mid+1,end);
    conquer(ar,start,mid,end);

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

    divide(ar,0,n-1);
    
    printf("Sorted: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}