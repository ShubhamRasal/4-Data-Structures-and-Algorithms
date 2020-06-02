
#include<stdio.h>
#include<stdlib.h>
#include"stqueue.h"

main()
{
	Queue q;
	init(&q);
	int ch,i,n;
	printf("\n Operations on Queue: \n 1. Add\n 2. Remove\n 3. Peek \n 4. Exit");
	while(1)
	{
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			if(isfullq(&q))
			printf("\n Queue is Full");		//Queue overflows
			else
			{
				printf("\n Enter the data: "); //to add an element
				scanf("%d",&n);
				addq(&q,n);
			}
			break;
		
			case 2:
			if(isempty(&q))
			printf("\n Queue is Empty");		//Empty Queue
			else
			printf("\n Removed Element is: %d",removeq(&q));		//if queue is not empty
			break;

			case 3:
			if(isempty(&q))
			printf("\n Queue is Empty");		//if queue is empty
			else	
			printf("\n Peek element is: %d",peek(&q));
			//if queue is not empty it returns peek element 
			break;
			
			case 4:
			exit(0);
			break;	

			default:
			printf("\n Invalid Input");
		}
	}
}
