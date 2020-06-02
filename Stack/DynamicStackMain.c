#include<stdio.h>
#include<stdlib.h>
#include"dystack.h"
main()
{
	int ch,n,i;
	init();
	printf("\n Operations performed on Stack:\n 1. Push \n2. Pop \n3. Peek\n 4. Exit  ");
	while(1)
	{
		printf("\n Enter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
			printf("\n Enter the element to be push: ");
			scanf("%d",&n);
			push(n);
			break;
		
			case 2:
			if(isEmpty())
			printf("\n Stack is Empty");
			else
			{
				i=pop();
				printf("\n Number is:%d",i);
			}
			break;

			case 3:
			if(isEmpty())
			printf("\n Stack is Empty");
			else
			{
				printf("%d",peek());
			}
			break;
			
			case 4:
			exit(0);
			break;
			
			default:
			printf("\n Invalid Input...");
		}	
	}
}


