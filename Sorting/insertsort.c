
#include<stdio.h>
#include<stdlib.h>
void insertionsort(int *A,int n);
void generate(int *A,int n);
void display(int *A,int n);
main()
{
	int i,n,*B;
	while(1)
	{
		printf("\n Enter the size of array-");
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
	printf("\n Unsorted Array is:");
	display(B,n);
	insertionsort(B,n);
	printf("\n Sorted Array is: ");
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

void insertionsort(int *A,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=A[i];
		for(j=i-1;j>=0;j--)
		{
			if(A[j]>temp)
			{
				A[j+1]=A[j];
				A[j]=temp;
			}
			else
			break;
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
/*
#include<stdio.h>
void main()
{
	int i,j,n,A[100],temp;//declaration
	printf("\nenter how many no\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)//accepting numbers
		{
			printf("\nenter %d no\n",i+1);
			scanf("%d",&A[i]);
		}
	printf("\nThe numbers entered are:-\n");
	for(i=0;i<n;i++)//printing numbers accepted from user
		{			
			printf("%d\t",A[i]);
		}
	for(i=1;i<n;i++)//insertion logic
		{
			temp=A[i];			
			for(j=i-1;j>=0;j--)
				{	
					if(A[j]>temp)
						{
							A[j+1]=A[j];
						}
					else break;
				}
			A[j+1]=temp;
		}
	printf("\nThe sorted numbers are:-\n");
	for(i=0;i<n;i++)//printing sorted array
		{			
			printf("%d\t",A[i]);
		}
}
*/
