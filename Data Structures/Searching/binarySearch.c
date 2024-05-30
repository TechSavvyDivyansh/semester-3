#include <stdio.h>

int val,A[50];
int binary(int low,int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(val==A[mid])
            return mid;
        else if(val<A[mid])
            return binary(low,mid-1);
        else
            return binary(mid+1,high);
    }
    else
        return -1;
}

void main()
{
    
}