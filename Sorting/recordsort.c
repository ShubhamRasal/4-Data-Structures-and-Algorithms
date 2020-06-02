#include<stdio.h>
#include<string.h>
typedef struct
{
	char name[20];
	int age,salary;
}RECORD;
RECORD E[100];
int readfile(RECORD *A);
void sort(RECORD *A,int n);
void writefile(RECORD *A,int n);

main()
{
	int n;
	n=readfile(E);
	sort(E,n);
	writefile(E,n);
}

int readfile(RECORD *A)
{
	int i=0;
	FILE *fp;
	if((fp=fopen("data.txt","r"))!=NULL)
	while(!feof(fp))
	{
		fscanf(fp,"%s %d %d",A[i].name,&A[i].age,&A[i].salary);
		if(A[i].age<0)
		i--;
		i++;
	}
	return i-1;
}

void sort(RECORD *A,int n)
{
	int i,j,tage,tsal;
	char tname[20];
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<i;j++)
		{
			if((strcmp(A[j].name,A[j+1].name))>0)
			{
				tage=A[j].age;
				A[j].age=A[j+1].age;
				A[j+1].age=tage;
				
				tsal=A[j].salary;
				A[j].salary=A[j+1].salary;
				A[j+1].salary=tsal;
	
				strcpy(tname,A[j].name);
				strcpy(A[j].name,A[j+1].name);
				strcpy(A[j+1].name,tname);
			}
		}
	}	
}

void writefile(RECORD *A, int n)
{
	int i;
	FILE *fp;
	if((fp=fopen("sorted1.txt","w"))!=NULL)
	for(i=0;i<n;i++)
	{
		fprintf(fp,"\n %s \t %d \t %d \t",A[i].name,A[i].age,A[i].salary);
	}
}
