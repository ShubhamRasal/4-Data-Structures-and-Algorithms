#include<stdio.h>
#include<stdlib.h>
#include"cststack.h"

void reverse(char s[]);

void main()
{
	char str[MAX];
	printf("Enter the String: ");
	scanf("%s",str);
	reverse(str);
}
void reverse(char s[])
{
	struct stack st;
	char revstr[MAX];
	int i,j=0;
	init(&st);
	for(i=0;s[i]!='\0';i++)
	push(&st,s[i]);
	while(!isEmpty(&st))
	{
		revstr[j]=pop(&st);
		j++;
	}
	printf("\nReverse String is: %s\n\n",revstr);
}
