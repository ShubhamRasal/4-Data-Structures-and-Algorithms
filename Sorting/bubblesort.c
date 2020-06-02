
#include<stdio.h>
#include<stdlib.h>
void generate(int *A,int n);
void bubblesort(int *A,int n);
void display(int *A,int n);
main()
{
	int n,i,*B;
	while(1)
	{
		printf("\n Enter size of array-");
		scanf("%d",&n);
		B=(int *)malloc(n*sizeof(int));
		if(n>0)
		{
			generate(B,n);
			break;
		}
		else 
		{
			printf("\n Invalid input");
			continue;
		}
	}
	printf("\n Unsorted Array is: ");
	display(B,n);
	bubblesort(B,n);                        //function call
	printf("\n Sorted Array is..");
	display(B,n);
}
void generate(int *A,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=rand()%100;
	}
}

void bubblesort(int *A,int n)
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

void display(int *A,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\t %d",A[i]);
	}
}
