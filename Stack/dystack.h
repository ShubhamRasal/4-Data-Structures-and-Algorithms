typedef struct
{
	struct node *next;
	int info;
}NODE;

NODE *top;

void init()
{
	top=NULL;
}

void push(int n)
{
	NODE *P;
	P=(NODE *)malloc(sizeof(NODE));
	P->info=n;
	P->next=top;
	top=P;
}

int pop()
{
	int x;
	NODE *T=top;
	x=top->info;
	top=top->next;
	free(T);
	return x;
}

int isEmpty()
{
	return(top==NULL);
}
int peek()
{
	return(top->info);
}

