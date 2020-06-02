#include<stdio.h>
#include<stdlib.h>
void generate(int *A,int n);
void display(int *A,int n);
void lsearch(int *A,int n,int x);
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
	printf("\n Enter the number to be search: ");
	scanf("%d",&no);
	lsearch(B,n,no);
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
	for(i=0;i<n;i++)
	{
		printf("%d \t",A[i]);
	}
}

void lsearch(int *A,int n,int x)
{
	int i,pos=0;
	for(i=0;i<n;i++)
	{
		if(A[i]==x)
		{
			pos++;
			printf("\n Number found at position:  %d",i+1);
		}
	}
	if(pos==0)
	printf("Number not found");

}
