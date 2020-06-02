#include<stdio.h>
#include<stdlib.h>
main()
{
	static int A[10][10];
	int i,j,k,ID,OD,N,E;
	while(1)
	{
		printf("\n Enter the number of vertices: ");
		scanf("%d",&N);
		if(N>0)
		break;
		else
		printf("\n Invalid Input...");
	}
	while(1)
	{
		printf("\n Enter the number of Edges: ");
		scanf("%d",&E);
		if(E>=0)
		break;
		else
		printf("\n Invalid Input...");
	}
	if(E==0)
	printf("\n Graph is Null Graph...");
	if(E>0)
	{
	printf("\n Enter the edges in the form of ordered pair of Vertices: ");
	for(k=1;k<=E;k++)
	{
		printf("\n Enter the Edge %d: ",k);
		scanf("%d %d",&i,&j);
		if(i>N || j>N || i==j)
		{
			if(i==j)
			printf("\n Self loop is not allowed...");
			printf("\n Invalid Input...");
			printf("\n Re-enter the Edge..");
			k--;
			continue;
		}
		if(A[i-1][j-1]==1)
		{
			printf("\n Edge Already Exists....");
			k--;
			continue;
		}
		A[i-1][j-1]=1;
	}
	for(i=0;i<N;i++)
	{
		ID=0,OD=0;
		printf("\n Vertex %d: ",i+1);
		for(j=0;j<N;j++)
		{
			if(A[i][j]==1)
			OD++;
			if(A[j][i]==1)
			ID++;
		}
		printf("\t Indegree: %d \t Outdegree: %d",ID,OD);
	}
	}
	printf("\n Adjacency Matrix is: ");
	for(i=0;i<N;i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("\t %d",A[i][j]);
		}
	}
}
