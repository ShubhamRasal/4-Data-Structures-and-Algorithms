#include<stdio.h>
#define MAX 5

typedef struct
{	
	int data[MAX];
	int front,rear;
}Queue;

void init(Queue *q)
{
	q->front=-1;
	q->rear=-1;
}

int isempty(Queue *q)
{
	return(q->rear==-1);
}

int isfull(Queue *q)
{
	return((q->rear+1)%MAX==q->front);
}

void addrear(Queue *q,int n)
{
	if(q->rear==-1)
	{
		q->rear=0;
		q->front=0;
		q->data[q->rear]=n;
	}
	else
	{
		q->rear=(q->rear+1)%MAX;
		q->data[q->rear]=n;
	}
}

void addfront(Queue *q,int n)
{
	if(q->rear==-1)
	{
		q->rear=0;
		q->front=0;
		q->data[q->front]=n;
	}	
	else
	{
		q->front=(q->front-1+MAX)%MAX;
		q->data[q->front]=n;
	}
}

int deletefront(Queue *q)
{
	int x;
	x=q->data[q->front];
	if(q->rear==q->front)
	{
		init(q);
	}
	else
	q->front=(q->front+1)%MAX;
	return x;
}

int deleterear(Queue *q)
{
	int x;
	x=q->data[q->rear];
	if(q->rear==q->front)
	init(q);
	else
	q->rear=(q->rear-1+MAX)%MAX;
	return x;
}

void display(Queue *q)
{	
	int i;
	printf("\n");
	for(i=q->front;i<=q->rear;i++)
	{
		printf("\t %d",q->data[i]);
	}
}

