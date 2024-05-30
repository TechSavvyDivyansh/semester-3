#include<stdio.h>


int min(int x, int y){ 
    return (x < y) ? x : y; 
}


int fibonaccisearch(int arr[],int n,int val){
    int fibm2 = 0; 
    int fibm1 = 1; 
    int fibM = fibm2 + fibm1;
    int offset=-1;
    while (fibM < n) { 
        fibm2 = fibm1; 
        fibm1 = fibM; 
        fibM = fibm2 + fibm1; 
    }
    while(fibm2!=0){
        while (fibM > 1) { 
        int i = min(offset + fibm2, n - 1); 
        if (arr[i] < val) { 
            fibM = fibm1; 
            fibm1 = fibm2; 
            fibm2 = fibM - fibm1; 
            offset = i; 
        }  
        else if (arr[i] > val) { 
            fibM = fibm2; 
            fibm1 = fibm1 - fibm2; 
            fibm2 = fibM - fibm1; 
        } 
        else
            return i; 
    } 
    if (fibm1 && arr[offset + 1] == val) 
        return offset + 1; 
    return -1;
    }
}


int main(){
    int arr[50];
    int n,val,key;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element you want to find:");
    scanf("%d",&val);

    key=fibonaccisearch(arr,n,val);

    if(key==-1){
        printf("Element not found.");
    }
    else{
        printf("Element found at index %d",key);        
    }
    return 0;
}