#include<stdio.h>
#include<string.h>
typedef struct
{
	char city[40];
	int code;
}RECORD;
RECORD E[100];
int readfile(RECORD *A);
int lsearch(RECORD *A,int n, char S[]);
main()
{
	int n,p;
	char C[40];
	n=readfile(E);
	printf("\n Enter the name of the city to be search: ");
	scanf("%s",C);
	p=lsearch(E,n,C);
	if(p==0)
	printf("\n City is not in the list");
	else
	printf("\n City:%s \t Code:%d",E[p-1].city,E[p-1].code);
}


int readfile(RECORD *A)
{
	int i=0;
	FILE *fp;
	if((fp=fopen("a.txt","r"))!=NULL)
	while(!feof(fp))
	{
		fscanf(fp,"%s %d",A[i].city,&A[i].code);
		if(A[i].code<=0)
		i--;
		i++;
	}
	return i-1;
}


int lsearch(RECORD *A, int n,char S[])
{
	int i,pos=0;
	for(i=0;i<n;i++)
	{
		if((strcasecmp(A[i].city,S))==0)
		{
			pos=i+1;
			break;
		}
	}
	return pos;
}
