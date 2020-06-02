struct node
{
	int data;
	struct node *next;
};
struct node * create(int n)
{
	struct node *F=NULL,*S;
	int i;
	if(n>0)
	{
		F=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter the data: ");
		scanf("%d",&F->data);
		S=F;
		for(i=2;i<=n;i++)
		{	
			S->next=(struct node *)malloc(sizeof(struct node));
			S=S->next;
			printf("\n Enter the data: ");
			scanf("%d",&S->data);	
		}
		S->next=NULL;
	}
	return F;
}

void display(struct node *F)
{
	if(F!=NULL)
	{
	while(F!=NULL)
	{	
		printf("%d \t",F->data);
		F=F->next;
	}
	}
}

int LLlength(struct node *F)
{
	int c=0;
	if(F!=NULL)
	{
		while(F!=NULL)
		{
			c++;
			F=F->next;
		}
	}
	return c;
}

struct node * sort(struct node *F)
{
	struct node *S,*T,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	int i,j,l;
	l=LLlength(F);
	S=F;
	for(j=l;j>0;j--)
	{
		for(i=1,T=F;i<j,T->next!=NULL;i++,T=T->next)
		{
			if(T->data>T->next->data)
			{
				temp->data=T->data;
				T->data=T->next->data;
				T->next->data=temp->data;
			}
		}	
	}
	return F;
}

struct node * insert(struct node *F,int x)
{
	struct node *S,*T;
	int p=1,i;
	S=(struct node *)malloc(sizeof(struct node));
	S->data=x;
	T=F;
	while(T->data<S->data)
	{
		if(T->next!=NULL)
		{
			p++;
			T=T->next;
		}
		else
		{
			p++;
			break;
		}
	}
	if(p==1)
	{
		S->next=F;
		F=S;
	}
	else
	{
		for(i=1,T=F;i<=p-2;i++)
		T=T->next;
		S->next=T->next;
		T->next=S;
	}
	return F;
}


void search(struct node *F,int x)
{
	struct node *S=NULL;
	int f=0,c=0;
	if(F!=NULL)
	{
	for(S=F;S!=NULL;S=S->next)
	{
		c++;
		if(S->data==x)
		{
			f=1;
			printf(" \n %d found at %d",x,c);
		}
	}
	}
	if(f==0)
	printf("\n %d not found",x);
}
