#include<stdio.h>
#include<stdlib.h>

void generate(int *A,int n);
void quicksort(int *A,int lb,int ub);
void display(int *A,int n);

main()
{
	int n,*B;
	while(1)
	{
		printf("\n Enter the number of elements in the array: ");
		scanf("%d",&n);
		B=(int *)malloc(n*sizeof(int));
		if(n>0)
		{
			generate(B,n);
			break;
		}
		else
		{
			printf("\n Invalid Input");
			continue;
		}
	}
	printf("\n Unsorted Array is:");
	display(B,n);
	quicksort(B,0,n-1);
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

void quicksort(int *A,int lb,int ub)
{
	int i,j,temp,key;
	if(lb<ub)
	{
		key=A[lb];
		i=lb+1;
		j=ub;
		while(i<=j)
		{
			while((A[i]>=key)&&(i<=ub))
			i++;
			while((A[j]<key)&&(j>lb))
			j--;
			if(i<j)
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
			temp=A[lb];
			A[lb]=A[j];
			A[j]=temp;
		}

		quicksort(A,lb,j-1);
		quicksort(A,j+1,ub);
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
