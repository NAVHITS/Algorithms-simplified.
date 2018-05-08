//dijikstra's algo for shortest path

#include<stdio.h>
#define INFINITY 9999 
void dig(int G[10][10], int n, int start);
void main(){
	int G[10][10], i, j, n, u;
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d", &G[i][j]);
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
	dig(G,n,u);
} 
void dig(int G[10][10], int n, int start)
{
	int cost[10][10], distance[10], pred[10];
	int visited[10], count, min, next, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	for(i=0;i< n;i++)
	{
		distance[i]=cost[start][i];
		pred[i]=start;
		visited[i]=0;
	}
	distance[start]=0;
	visited[start]=1;
	count=1;
	while(count < n-1){
		min=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < min&&!visited[i])
			{
				min=distance[i];
				next=i;
			}
		visited[next]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(min+cost[next][i] < distance[i])
				{
					distance[i]=min+cost[next][i];
					pred[i]=next;
				}
			count++;
	}
	for(i=0;i < n;i++)
		if(i!=start)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=start);
		}
}
