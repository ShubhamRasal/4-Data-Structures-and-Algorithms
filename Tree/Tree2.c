#include<stdio.h>
#include<stdlib.h>
#include"btree1.h"
main()
{
	struct treenode *root,*S=NULL;
	init(root);
	int ch,no,l=0;
	printf("\n Enter the number of nodes to be created: ");
	scanf("%d",&no);
	if(no>0)
	root=create(root,no);
	else
	{
		printf("\n Invalid Number of nodes...");
		exit(0);
	}
	while(1)
	{
		printf("\n Menu is: \n 1. Insert \n 2. Search \n 3. Display in Inorder \n 4. Display in Preorder \n 5. Display in Postorder\n 6. Count the number of nodes \n 7. Exit");
		printf("\n Enter your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n Enter the Number to be inserted: ");
			scanf("%d",&no);
			if(no>0)
			{
				S=searchT(root,no);
				if(S==NULL)
				root=insert(root,no);
				else
				printf("\n Number is Already present in the list");
			}
			else
			printf("\n Invalid Data...");
			break;

			case 2:
			if(root==NULL)
			printf("\n Binary Search Tree is Empty");
			else
			{
				printf("\n Enter the number to be searched: ");
				scanf("%d",&no);
				S=searchT(root,no);
				if(S==NULL)
				printf("\n %d not found",no);
				else
				printf("\n %d found",no);
			}
			break;

			case 3:
			if(root==NULL)
			printf("\n Binary Search Tree is Empty");
			else
			{
				printf("\n Inorder is... ");
				inorder(root);
			}
			break;

			case 4:
			if(root==NULL)
			printf("\n Binary Search Tree is Empty");
			else
			{
				printf("\n Preorder is...");
				preorder(root);
			}
			break;

			case 5:
			if(root==NULL)
			printf("\n Binary Search Tree is Empty");
			else
			{
				printf("\n Postorder is...");
				postorder(root);
			}
			break;
			
			case 6:
			l=countT(root);
			if(l==0)
			printf("\n Binary Search Tree is Empty");
			else
			printf("\n Number of nodes in Binary Search Tree is: %d",l);
			break;
			
			case 7:
			exit(0);
			break;
	
			default:
			printf("\n Invalid Choice...");
		}
	}
}
