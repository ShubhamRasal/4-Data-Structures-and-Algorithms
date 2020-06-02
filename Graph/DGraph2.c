#include<stdio.h>
#include<stdlib.h>
struct node
{
	int v;
	struct node *next;
};
struct node *AL[10];
struct node * append(struct node *F,int no);
void display(struct node *AL[],int n);
main()
{
	static int A[10][10];
	int i,j,k,N,E;
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
	for(i=0;i<N;i++)
	AL[i]=NULL;
	printf("\n Enter the edges - pair of Vertices: ");
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
			if(A[i][j]==1)
			AL[i]=append(AL[i],j);//directed
		}	
	}
	printf("\n Adjacency List is: ");
	display(AL,N);
}

struct node * append(struct node *F,int no)
{
	struct node *S;
	if(F==NULL)
	{
		F=(struct node *)malloc(sizeof(struct node));
		S=F;
	}
	else
	{
		for(S=F;S->next!=NULL;S=S->next);
		S->next=(struct node *)malloc(sizeof(struct node));
		S=S->next;	
	}
	S->v=no;
	S->next=NULL;
	return F;
}

void display(struct node *AL[],int N)
{
	int i;
	struct node *T;
	for(i=0;i<N;i++)
	{
		printf("\n %d-",i+1);
		for(T=AL[i];T!=NULL;T=T->next)
		printf("\t %d",T->v+1);
	}
}

//0110_0001_0001_0000

