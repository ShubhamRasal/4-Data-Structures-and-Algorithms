#include<stdio.h>
#include<stdlib.h>
#include"sstack.h"

main()
{
	struct stack st;
	int ch,n,i;
	init(&st);
	printf("Operations performed on Stack:\n0.Init\t1.Push\t2.Pop \t3.Peek\t4.isEmpty\t5.isFull\t6.Exit");
	while(1)
	{
		printf("\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 0:init(&st);
				break;
			case 1:
				if(isFull(&st))
				{
					printf("\nStack is Full");
				}
				else
				{
					printf("\nEnter the element to be push: ");
					scanf("%d",&n);
					push(&st,n);
				}
				break;
		
			case 2:
				if(isEmpty(&st))
				printf("\nStack is Empty");
				else
				{
					i=pop(&st);
					printf("\n Removed Element is:%d",i);
				}
				break;
			case 3:
				if(isEmpty(&st))
					printf("\nStack is Empty");
				else
					printf("Peek Element: %d",peek(&st));
				break;
			case 4:
				if(isEmpty(&st))
					printf("\nStack is Empty");
				else
					printf("\nStack is not Empty");
				break;
			case 5:
				if(isFull(&st))
					printf("\nStack is Full");
				else 
					printf("\nStack is not full");
				break;
			case 6:
				exit(0);
				break;
			
			default:
				printf("\nInvalid Input..!");
		}	
	}
}


