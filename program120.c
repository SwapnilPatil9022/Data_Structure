#include<stdio.h>
#include<stdlib.h >

struct node
{
	int data;
	struct node*next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head, int no)
{
	//Allocate memory for node (Dynamacally)
	//Initialise that node
	
	//Cheak whether LL is empty or not
	//If LL is empty then new node is the first node so updates its address in first point to head
	
	//If LL is a not empty then store the address of first node in the next pointer of our next node
	//update the first pointer through head.
	PNODE newn = NULL;
	 
	newn = (PNODE)malloc(sizeof(NODE)); 	//newn = (struct node *)malloc(12)
	
	newn->data = no;
	newn->next = NULL;
	
	if(*head == NULL)	//LL is empty
	{
		*head = newn;
	}
	else		//LL containce atleast one node
	{
		newn->next = *head;
		*head = newn;
	}
}

void InsertLast(PPNODE head, int no)
{
	//Allocate memory for node (Dynamacally)
	//Initialise that node
	
 	//Cheak whether LL is empty or not
	//If LL is empty then new node is the first node so updates its address in first point to head
	
	//If LL is a not empty then store the address of 
	//update the first pointer through head.
	
	//If LL is mot empty then
	//travel till last node of LL
	//store address of new node in the next pointer of the last node.
	
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE)); 	//newn = (struct node *)malloc(12)
	
	newn->data = no;
	newn->next = NULL;
	
	if(*head == NULL)	//LL is empty
	{
		*head = newn;
	}
	else		//LL containce atleast one node
	{
		//Code
	}
}

void Display(PNODE head)
{
	printf("Elements from linked list are : \n");
	
	while(head != NULL)
	{
		printf("| %d\t |->",head->data);
		head = head -> next;
	}
	printf("NULL\n");
}

int Count(PNODE head)
{
	int iCnt = 0;
	
	while(head != NULL)
	{
		iCnt++;
		head = head -> next;
	}
	return iCnt;
}

int main()
{
	int iRet = 0;
    PNODE first = NULL;
	
	InsertFirst(&first,101);		//call by address
	InsertFirst(&first,51);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	
	Display(first);		//call by value
	 
	iRet = Count(first);
	printf("Number of nodes are :%d\n",iRet);
	
	InsertFirst(&first,1);
	
	Display(first);		//call by value
	
	iRet = Count(first);
	printf("Number of nodes are :%d\n",iRet);
	
	return 0;
}

