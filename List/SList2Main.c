#include<stdio.h>
#include<stdlib.h>
#include"singly.h"
main()
{
	struct node *L,*P;
	int n,ch,x,p;
	printf("\n Enter the number of Nodes in the Linked List: ");
	scanf("%d",&n);
	if(n<=0)
	printf("\n Invalid Number...");
	else
	{
	L=create(n);
	L=sort(L);
	while(1)
	{
		printf("\n Menu is: \n 1. Insert\n 2. Search\n 3. Display \n 4. Exit");
		printf("\n Enter your Choice: ");	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n Enter the Number: ");
			scanf("%d",&x);
			L=insert(L,x);
			break;

			case 2:
			printf("\n Enter the element to be searched: ");
			scanf("%d",&x);
			search(L,x);
			break;
		
			case 3:
			display(L);
			break;
		
			case 4:
			exit(0);
			break;

			default:
			printf("\n Invalid Input...");
		}
	}
	}
}
