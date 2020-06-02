#include<stdio.h>
#include<stdlib.h>
#include"doublylist.h"
main()
{
	struct node *L,*P;
	int n,ch,x,p;
	printf("\n Enter the number of Nodes in the Linked List: ");
	scanf("%d",&n);
	if(n<=0)
	printf("\n Invalid Input...");
	else
	{
	L=create(n);
	while(1)
	{
		printf("\n Menu is: \n 1. Insert\n 2. Search\n 3. Delete\n 4. Display \n 5. Exit");
		printf("\n Enter your Choice: ");	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			if(L==NULL)
			p=1;
			else
			{
				printf("\n Enter the Position at which you want to insert: ");
				scanf("%d",&p);
			}
			if(p<=0)
			printf("\n Invalid Input...");
			else
			{
				if(p>(LLlength(L)+1))
				p=LLlength(L)+1;
				printf("\n Enter the data: ");
				scanf("%d",&x);
				L=insertl(L,x,p);
			}
			break;

			case 2:
			if(L==NULL)
			printf("\n Linked List is Empty");
			else
			{
				printf("\n Enter the element to be searched: ");
				scanf("%d",&x);
				searchl(L,x);
			}
			break;
	
			case 3:
			if(L==NULL)
			printf("\n Linked List is Empty");
			else
			{
				printf("\n Enter the element to be deleted: ");
				scanf("%d",&x);
				L=deletel(L,x);
			}
			break;
	
			case 4:
			display(L);
			break;
		
			case 5:
			exit(0);
			break;

			default:
			printf("\n Invalid Input...");
		}
	}
	}
}
