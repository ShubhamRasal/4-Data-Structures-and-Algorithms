#include<stdio.h>
#include<string.h>
typedef struct
{
	char name[20];
	int age,salary;
}RECORD;
RECORD E[100];
int readfile(RECORD *A);
void quicksort(RECORD *A,int lb,int b);
void writefile(RECORD *A,int n);

main()
{
	int n;
	n=readfile(E);
	quicksort(E,0,n-1);
	writefile(E,n);
}

int readfile(RECORD *A)
{
	int i=0;
	FILE *fp;
	if((fp=fopen("qsort1.txt","r"))!=NULL)
	while(!feof(fp))
	{
		fscanf(fp,"%s %d %d",A[i].name,&A[i].age,&A[i].salary);
		if(A[i].age<0)
		i--;
		i++;
	}
	return i-1;
}

void quicksort(RECORD *A,int lb,int ub)
{
	int i,j,tage,tsal,key;
	char tname[20];
	if(lb<ub)
	{
		key=A[lb].age;
		i=lb+1;
		j=ub;
		while(i<=j)
		{
			while((A[i].age<=key)&&(i<=ub))
			i++;
			while((A[j].age>key)&&(j>lb))
			j--;
			if(i<j)
			{
				tage=A[i].age;
				A[i].age=A[j].age;
				A[j].age=tage;
			
				tsal=A[i].salary;
				A[i].salary=A[j].salary;
				A[j].salary=tsal;
				
				strcpy(tname,A[i].name);
				strcpy(A[i].name,A[j].name);
				strcpy(A[j].name,tname);
			}
			tage=A[lb].age;
			A[lb].age=A[j].age;
			A[j].age=tage;
				
			tsal=A[lb].salary;
			A[lb].salary=A[j].salary;
			A[j].salary=tsal;
	
			strcpy(tname,A[lb].name);
			strcpy(A[lb].name,A[j].name);
			strcpy(A[j].name,tname);	
		}	
		quicksort(A,lb,j-1);
		quicksort(A,j+1,ub);
	}	
}

void writefile(RECORD *A, int n)
{
	int i;
	FILE *fp;
	if((fp=fopen("qsort3.txt","w"))!=NULL)
	for(i=0;i<n;i++)
	{
		fprintf(fp,"\n %s \t %d \t %d \t",A[i].name,A[i].age,A[i].salary);
	}
}
