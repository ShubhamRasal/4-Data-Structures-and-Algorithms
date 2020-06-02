#include<stdio.h>
#include<string.h>
typedef struct
{
	char city[40];
	int code;
}RECORD;
RECORD E[100];
int readfile(RECORD *A);
int bsearch(RECORD *A,int lb,int ub,char S[]);
void sort(RECORD *A,int n);
main()
{
	int n,p;
	char C[40];
	n=readfile(E);
	sort(E,n);
	printf("\n Enter the name of the city to be search: ");
	scanf("%s",C);
	p=bsearch(E,0,n-1,C);
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


int bsearch(RECORD *A, int lb,int ub,char S[])
{
	int mid;
	if(lb<=ub)
	{
		mid=(lb+ub)/2;
		if((strcasecmp(A[mid].city,S))==0)
		return mid+1;
		else if((strcasecmp(A[mid].city,S))>0)
		return bsearch(A,lb,mid-1,S);
		else
		return bsearch(A,mid+1,ub,S);
	}
	return 0;
}

void sort(RECORD *A,int n)
{
	int i,j,tcode;
	char tcity[20];
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<i;j++)
		{
			if((strcasecmp(A[j].city,A[j+1].city))>0)
			{
				tcode=A[j].code;
				A[j].code=A[j+1].code;
				A[j+1].code=tcode;

				strcpy(tcity,A[j].city);
				strcpy(A[j].city,A[j+1].city);
				strcpy(A[j+1].city,tcity);
			}
		}
	}
}
