#include<stdio.h>
#include<stdlib.h>
struct node
{
	int v;
	struct node *next;
};
struct node *AL[100];
struct node * append(struct node *F,int no);
void display(struct node *AL[],int n);
int outdegree(struct node *AL[],int V);
main()
{
	int i,j,k,ch,N,E,V;
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
	if(E==0)
	printf("\n Graph is Null Graph...");	
	if(E>0)
	{
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
			if((search(AL[i-1],j-1))==1)
			{
				printf("\n Edge already exists...");
				k--;	
			}	
			else
			AL[i-1]=append(AL[i-1],j-1);
		}
	}
	printf("\n Adjacency List- ");
	display(AL,N);
	while(1)
	{	
		printf("\n Enter the Vertex: ");
		scanf("%d",&V);
		if(V>0 && V<=N)
		{
			printf("\n Outdegree of %d is %d",V,outdegree(AL,V));
			break;
		}
	}
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

int search(struct node *F,int j)
{
	struct node *T;
	for(T=F;T!=NULL;T=T->next)
	{
		if(T->v==j)
		return 1;
	}
	return 0;	
}

int outdegree(struct node *AL[],int V)
{
	int d=0;
	struct node *T;
	for(T=AL[V-1];T!=NULL;T=T->next)
	d++;
	return d;
}
