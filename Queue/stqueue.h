#define MAX 5

typedef struct 
{
	int data[MAX];
	int rear,front;
}Queue;

void init(Queue *q)
{
	q->rear=-1;
	q->front=-1;
}

void addq(Queue *q,int n)
{
	if(q->rear==-1)		//if queue is empty
	{
		q->front=0;
		q->rear=0;
		q->data[q->rear]=n;
	}
	else			//if queue is not empty
	{
		q->rear++;
		q->data[q->rear]=n;
	}
}

int removeq(Queue *q)
{
	int n;
	if(q->front==q->rear)//if only one element is there inthe queue	
	{
		n=q->data[q->front];
		init(q);
	}
	else
	{
		n=q->data[q->front];
		q->front++;
	}
	return n;
}

int isempty(Queue *q)
{
	return(q->rear==-1);
}

int isfullq(Queue *q)
{
	return(q->rear==MAX-1);
}

int peek(Queue *q)
{
	return(q->data[q->front]);
}
