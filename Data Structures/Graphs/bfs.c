#include<stdio.h>
#include<stdlib.h>
#define NODES 8
int visited[NODES] = {0};
//char nodes[NODES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int adj[NODES][NODES] = 
{
//   A  B  C  D  E  F  G  H 
	{0, 1, 0, 1, 0, 0, 0, 0},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 0, 1, 0, 1, 0, 0},
	{0, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 1, 0, 0, 0, 0, 1, 0}
};

#define SIZE 50
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) 
{
	if (rear != SIZE - 1)
		queue[++rear] = val;
	if (front == -1)
		front++;
}
int dequeue() 
{
	int x = -1;
	if (front != -1) {
    	if (front == rear) {
    		x = queue[front];
    		front = rear = -1;
    	}
    	else 
    	    x = queue[front++];
	}
	return x;
}

int peek() 
{
	if (front != -1)
		return queue[front];
	return -1;
}

void bfs(int start) 
{
	int i;
	if (visited[start] == 0) {
		enqueue(start);
		printf("%c ", start+65);
	}
	visited[start] = 1;
	for (i = 0; i < NODES; i++) {
		if (adj[start][i] == 1 && visited[i] == 0) {
			enqueue(i);
		}
	}
	dequeue();
	if (peek() != -1)
		bfs(peek());
	else
		return;
}  

// void bfs(int start) 
// {
//     int i;
//     if (visited[start] == 0) {
//         enqueue(start);
//         printf("%c ", start + 65);
//     }
//     visited[start] = 1;

//     while (peek() != -1) {
//         int current = dequeue();

//         for (i = 0; i < NODES; i++) {
//             if (adj[current][i] == 1 && visited[i] == 0) {
//                 enqueue(i);
//                 printf("%c ", i + 65);
//                 visited[i] = 1;
//             }
//         }
//     }
// }
int main() 
{
	printf("BFS: ");
	bfs(0);
	return 0;
}