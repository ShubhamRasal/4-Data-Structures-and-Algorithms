#include<stdio.h>
#include<stdlib.h>
void generate(int *A,int n);
void display(int *A,int n);
int Bsearch(int *A,int lb,int ub,int x);
void sort(int *A,int n);
main()
{
	int n,*B,i,no,p;
	while(1)
	{
		printf("\n Enter the size of array: ");
		scanf("%d",&n);
		if(n>0)
		{	
			B=(int *)malloc(n*sizeof(int));
			generate(B,n);
			break;
		}	
		else
		{
			printf("\n Invalid Input");
			continue;
		}
	}
	display(B,n);
	sort(B,n);
	printf("\n Sorted Array is: ");
	display(B,n);
	printf("\n Enter the number to be search: ");
	scanf("%d",&no);
	p=Bsearch(B,0,n-1,no);
	if(p==0)
	printf("\n %d not found",no);
	else
	printf("\n %d found at position %d",no,p);
}

void generate(int *A,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=rand()%100;
	}
}

void display(int *A,int n)
{
	int i;
	printf("\n ");
	for(i=0;i<n;i++)
	{
		printf("%d \t",A[i]);
	}
}

int Bsearch(int *A,int lb,int ub,int x)
{
	int mid;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(A[mid]==x)
		return mid+1;
		else if(x<A[mid])
		return Bsearch(A,lb,mid-1,x);  //search in 1st half 
		else 
		return Bsearch(A,mid+1,ub,x); //search in 2nd half
	}
}

void sort(int *A,int n)
{
	int i,j,temp;
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;		
			}
		}
	}
}
