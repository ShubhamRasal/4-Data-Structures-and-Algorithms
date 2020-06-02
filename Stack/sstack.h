#define MAX 5
struct stack
{
	int top;
	int data[MAX];
}*st;

void init(struct stack *st)
{
	st->top=-1;
}

void push(struct stack *st,int n)
{
	st->top++;
	st->data[st->top]=n;
}

int pop(struct stack *st)
{
	return(st->data[st->top--]);
}

int peek(struct stack *st)
{
	return (st->data[st->top]);
}
int isEmpty(struct stack *st)
{
	return(st->top==-1);
}

int isFull(struct stack *st)
{
	return(st->top==MAX-1);
}
