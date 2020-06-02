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

void add(Queue *q,int n)
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

int removeq(Queue *q)
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

int peek(Queue *q)
{
	return(q->data[q->front]);
}
