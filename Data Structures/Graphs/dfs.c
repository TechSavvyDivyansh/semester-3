#include<stdio.h>
#include<stdlib.h>
#define nodes 7

int visited[nodes]={0,0,0,0,0,0,0};

int A[7][7]={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void DFS(int start)
{
    printf("%c ",start+65);
    visited[start]=1;

    for(int i=0;i<nodes;i++)
    {
        if(A[start][i]==1 && visited[i]==0)
        {
            DFS(i);
        }
    }
}

void main()
{
    DFS(0);
}
