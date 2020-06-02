typedef struct
{
	struct node *next;
	int data;
}NODE;

NODE *front,*rear;

void init()
{
	front=NULL;
	rear=NULL;
}

void add(int n)
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=n;
	newnode->next=NULL;
	if(rear==NULL)
	{
		rear=newnode;
		rear->next=rear;
	}
	else
	{	
		newnode->next=rear->next;
		rear->next=newnode;
		rear=newnode;
	}
}

int removeq()
{       int n;
	front=rear->next;
	if(rear->next==rear)
	{
		n=rear->data;
		rear=NULL;
	}
	else
	{
		rear->next=front->next;
		n=front->data;
		free(front);
	}
	return n;
}

int isempty()
{
	return(rear==NULL);
}

int peek()
{
	front=rear->next;
	return(front->data);
}
