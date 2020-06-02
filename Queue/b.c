/*Dhanashree Pethkar
SY 17*/


#include<stdio.h>
#include<stdlib.h>
#include"dstqueue.h"

main()
{
	Queue q;
	init(&q);
	int ch,i,n,c;
	while(1)
	{
		printf("\n Two Ways for Doubly Ended Queue: \n 1.Input Restricted \n 2.Output Restricted\n 3.Exit");
		printf("\n Enter your Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("\n Operations on Queue: \n 1. Insertion from Rear\n 2. Deletion from Front\n 3.Deletion from Rear\n 4. Switch to other choice");	
			while(1)
			{
				printf("\n Enter your choice: ");
				scanf("%d",&ch);
				if(ch==1)
				{
					if(isfull(&q))
					printf("\n Queue is Full");		//Queue overflows
					else
					{
						printf("\n Enter the data: ");		 //insert an element
						scanf("%d",&n);
						addrear(&q,n);
						printf("\n Contents of Queue: ");
						display(&q);
					}
				}
			
				else if(ch==2)
				{
					if(isempty(&q))
					printf("\n Queue is Empty");		//Empty queue
					else	
					{
						printf("\n Removed element is: %d",deletefront(&q));	//delete the first element 		
						printf("\n Contents of Queue: ");
						display(&q);
					}
				}
			
				else if(ch==3)
				{	
					if(isempty(&q))
					printf("\n Queue is Empty");
					else
					{
						printf("\n Removed Element is:%d",deleterear(&q));	//delete last element
						printf("\n Contents of Queue: ");
						display(&q);
					}
				}	
			
				else if(ch==4)
				break;
				else
				printf("\n Invalid Input");
			}
			break;
	
			case 2:
			printf("\n Operations on Queue: \n 1. Insertion from Rear\n 2. Insertion from Front\n 3.Deletion from Front\n  4.Switch to other choice");	
			while(1)
			{
				printf("\n Enter your choice: ");
				scanf("%d",&ch);
				if(ch==1)
				{
					if(isfull(&q))
					printf("\n Queue is Full");		//Queue overflows
					else
					{
						printf("\n Enter the data: ");		 //insert an element
						scanf("%d",&n);
						addrear(&q,n);
						printf("\n Contents of Queue: ");
						display(&q);
					}
				}
					
				else if(ch==2)
				{
					if(isfull(&q))
					printf("\n Queue is Full");		//Queue Overflows
					else
					{
						printf("\n Enter the data: ");		//insert an element
						scanf("%d",&n);
						addfront(&q,n);
						printf("\n Contents of Queue: ");
						display(&q);
					}		
				}
		
				else if(ch==3)
				{
					if(isempty(&q))
					printf("\n Queue is Empty");		//Empty queue
					else
					{	
						printf("\n Removed element is: %d",deletefront(&q));	//delete the first element 		
						printf("\n Contents of Queue: ");
						display(&q);
					}
				}
	
				else if(ch=4)
				break;
				else					
				printf("\n Invalid Input...");
			}
			break;
			
			case 3:
			exit(0);
			break;

			default:
			printf("\n Invalid Input...");
		}
	}	
}
