#include<stdio.h>
#include<stdlib.h>
#include"cststack.h"
int reverse(char s[]);
void main()
{
	char str[MAX];
	int p;
	printf("Enter the String: ");
	scanf("%s",str);
	p=reverse(str);
	if(p==1)
	printf("\nString is Palindrome");
	else
	printf("\nString is not Palindrome");
}

int reverse(char s[])
{
	struct stack st;
	int i,j=0,p=0;
	char revstr[MAX];
	for(i=0;s[i]!='\0';i++)
	push(&st,s[i]);
	while(!isEmpty(&st))
	{
		revstr[j]=pop(&st);
		j++;
	}
	if((strcmp(s,revstr))==0)
		p=1;
	return p;
}
