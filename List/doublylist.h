struct node
{
	int data;
	struct node *next,*prev;
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
		F->prev=NULL;
		S=F;
		for(i=2;i<=n;i++)
		{	
			S->next=(struct node *)malloc(sizeof(struct node));
			S->next->prev=S;
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
	if(F==NULL)
	printf("\n Linked List is Empty");
	else
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


struct node * insertl(struct node *F,int x,int pos)
{
	struct node *S,*T;
	int i;
	S=(struct node *)malloc(sizeof(struct node));
	S->data=x;
	if(pos==1)
	{
		S->next=F;
		S->prev=NULL;
		if(F!=NULL)
		F->prev=S;
		F=S;
	}
	else
	{
		for(i=1,T=F;i<=pos-2;i++)
		T=T->next;
		S->next=T->next;
		S->prev=T;
		if(S->next!=NULL)
		S->next->prev=S;
		T->next=S;	
	}	
	return F;
}

struct node * deletel(struct node *F,int n)
{
	struct node *S;
	int c=0,f=0;
	if(LLlength(F)==1 && F->data==n)
	{
		S=F;
		free(S);
		return NULL;
	}
	for(S=F;S!=NULL;S=S->next)
	{
		f++;	
		if(S->data==n)
		{
			c=1;
			if(f==1)
			{
				S=F;
				F=F->next;
				if(F!=NULL)
				F->prev=NULL;
				free(S);
				f=0;
			}
			else
			{
				if(S->prev!=NULL)
				S->prev->next=S->next;
				if(S->next!=NULL)
				S->next->prev=S->prev;
				free(S);
			}
		}
	}
	if(c==0 && S==NULL)
	printf("\n Number is not there in the list..");
	return F;
}

void searchl(struct node *F,int x)
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
				printf("\n %d found at %d",x,c);
			}
		}
		if(f==0)
		printf("%d not found");
	}
}
