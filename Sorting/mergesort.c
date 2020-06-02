
#include<stdio.h>
#include<stdlib.h>

void generate(int *A,int n);
void mergesort(int *A,int lb,int ub);
void merge(int *A,int lb1,int ub1,int ub2);
void display(int *A,int n);

main()
{
	int *B,n;
	while(1)
	{
		printf("\n Enter the number of elements in  array : ");
		scanf("%d",&n);
		B=(int *)malloc(n*sizeof(int));
		if(n>0)
		{	
			generate(B,n);
			break;
		}
		else
		{
			printf("\n Invalid Input ");	
			continue;
		}
	}
	printf("\n Unsorted Array is: ");
	display(B,n);
	mergesort(B,0,n-1);
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

void mergesort(int *A,int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		mergesort(A,lb,mid);
		mergesort(A,mid+1,ub);
		merge(A,lb,mid,ub);
	}
}

void merge(int *A,int lb1,int ub1,int ub2)
{
	int B[100],i,j,k;
	i=lb1;
	j=ub1+1;
	k=0;
	while((i<=ub1)&&(j<=ub2))
	{
		if(A[i]<A[j])
		{
			B[k]=A[i];
			k++;
			i++;
		}
		else
		{
			B[k]=A[j];
			k++;
			j++;
		}
	}
	while(i<=ub1)
	{
		B[k]=A[i];
		k++;
		i++;
	}
	while(j<=ub2)
	{
		B[k]=A[j];
		k++;
		j++;
	}
	for(i=lb1,k=0;i<=ub2;i++,k++)
	{
		A[i]=B[k];
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
