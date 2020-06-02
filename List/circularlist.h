struct node
{
	int data;
	struct node *next;
};

struct node *H;

struct node * create(int n)
{
	struct node *S,*F=NULL;
	int i;
	if(n>0)
	{
		F=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter the data: ");
		scanf("%d",&F->data);
		S=F;
		H=F;
		for(i=2;i<=n;i++)
		{
			S->next=(struct node *)malloc(sizeof(struct node));
			S=S->next;
			printf("\n Enter the data: ");
			scanf("%d",&S->data);
		}
		S->next=F;
	}
	return S;
}

void display(struct node *F)
{
	struct node *S;
	if(F!=NULL)
	{
	S=H;
	do
	{
		printf("\t %d",S->data);
		S=S->next;
	}while(S!=H);
	}
}

struct node * append(struct node *F,int n)
{
	struct node *S;
	int i;
	if(n>0)
	{
	for(i=1;i<=n;i++)
	{
		S=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter the data: ");
		scanf("%d",&S->data);
		if(F==NULL)
		{
			F=S;
			S->next=S;
		}
		else
		{
			S->next=F->next;
			F->next=S;
			F=S;
		}
	}
	}
	else
	{
		printf("\n Number is not valid..");
	}
	return F;
}
