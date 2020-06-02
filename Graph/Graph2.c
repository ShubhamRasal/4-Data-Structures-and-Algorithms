#include<stdio.h>
#include<stdlib.h>
main()
{
	static int A[10][10];
	int i,j,k,ID,OD,N,E,d=0;
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
		if(i>N || j>N)
		{
			printf("\n Invalid Input...");
			printf("\n Re-enter the Edge..");
			k--;
			continue;
		}
		A[i-1][j-1]=1;
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(A[i][j]!=A[j][i])
			{
				d=1;
				break;
			}
		}
	}
	if(d==1)
	printf("\n Graph is Directed...");
	else
	printf("\n Graph is Undirected...");
	}
}
