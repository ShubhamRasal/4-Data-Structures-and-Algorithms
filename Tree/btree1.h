struct treenode
{
	int data;
	struct treenode *LC,*RC;
};

struct treenode *root=NULL;
	
void init(struct treenode *T)
{
	T=NULL;
}

struct treenode * insert(struct treenode *T,int x)
{
	struct treenode *t1,*t2,*S;
	S=(struct treenode *)malloc(sizeof(struct treenode));
	S->data=x;
	S->LC=NULL;
	S->RC=NULL;
	if(root==NULL)
	{
		T=S;
		root=S;
	}
	else
	{
		t1=T;
		while(t1!=NULL)
		{
			t2=t1;
			if(x<(t1->data))
			t1=t1->LC;
			else
			t1=t1->RC;
		}
		if(x<(t2->data))
		t2->LC=S;
		else
		t2->RC=S;
	}
	return root;
}

struct treenode * searchT(struct treenode *T,int x)
{
	if(T==NULL)
	return T;
	if(T->data==x)
	return T;
	else if(x<T->data)
	return searchT(T->LC,x);
	else
	return searchT(T->RC,x);
}


void inorder(struct treenode *T)
{
	if(T!=NULL)
	{
		inorder(T->LC);
		printf("%d \t",T->data);
		inorder(T->RC);
	}
}

void preorder(struct treenode *T)
{
	if(T!=NULL)
	{
		printf("%d \t",T->data);
		preorder(T->LC);
		preorder(T->RC);
	}
}

void postorder(struct treenode *T)
{
	if(T!=NULL)
	{
		postorder(T->LC);
		postorder(T->RC);
		printf("%d \t",T->data);
	}
}

struct treenode * create(struct treenode *T,int n)
{
	struct treenode *S=NULL;
	int i,x;
	for(i=1;i<=n;i++)
	{
		printf("\n Enter the data: ");
		scanf("%d",&x);
		if(x>0)
		{
			if(T==NULL)
			T=insert(T,x);
			else
			{
				S=searchT(root,x);
				if(S==NULL)
				T=insert(T,x);
				else
				printf("\n Number is already there in the Tree...");
			}
		}
		else
		printf("\n Invalid Data...");
	}
	return T;
}

int countT(struct treenode *T)
{
	int c;
	if(T==NULL)
	return 0;
	if(T->LC==NULL && T->RC==NULL)
	return 1;
	c=1+countT(T->LC)+countT(T->RC);
	return c;
}
