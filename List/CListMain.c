#include<stdio.h>
#include<stdlib.h>
#include"circularlist.h"
main()
{
	struct node *L;
	int n,ch,x;
	printf("\n Enter the number of Nodes in the Linked List: ");
	scanf("%d",&n);
	if(n<=0)
	printf("\n Invalid Input...");
	else
	{
	L=create(n);
	while(1)
	{
		printf("\n Menu is: \n 1. Append\n 2. Display \n 3. Exit");
		printf("\n Enter your Choice: ");	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n Enter the Number of nodes to be appended: ");
			scanf("%d",&n);
			if(n<=0)
			printf("\n Invalid Input...");
			else
			L=append(L,n);
			break;
		
			case 2:
			display(L);
			break;
		
			case 3:
			exit(0);
			break;

			default:
			printf("\n Invalid Input...");
		}
	}
	}
}
