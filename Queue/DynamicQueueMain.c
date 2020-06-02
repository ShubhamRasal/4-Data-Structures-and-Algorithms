#include<stdio.h>
#include<stdlib.h>
#include"dyqueue.h"

main()
{
	init();
	int ch,i,n;
	printf("\n Operations on Queue: \n 1. Add\n 2. Remove\n 3. Peek \n 4. Exit");
	while(1)
	{
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n Enter the data: ");		 //to add an element
			scanf("%d",&n);
			add(n);
			break;
		
			case 2:
			if(isempty())
			printf("\n Queue is Empty");		//Empty Queue
			else
			printf("\n Removed Element is: %d",removeq());		//if queue is not empty
			break;

			case 3:
			if(isempty())
			printf("\n Queue is Empty");		//if queue is empty
			else	
			printf("\n Peek element is: %d",peek());	//if queue is not empty it returns peek element 
			break;
			
			case 4:
			exit(0);
			break;	

			default:
			printf("\n Invalid Input");
		}
	}
}
