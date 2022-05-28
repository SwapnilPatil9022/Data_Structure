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
	PNODE temp = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE)); 	//newn = (struct node *)malloc(12)
	
	newn->data = no;
	newn->next = NULL;
	
	if(*head == NULL)	//LL is empty
	{
		*head = newn;
	}
	else		//LL containce atleast one node
	{
		//travel till last node
		//store address of new node in the next pointer of last node.
		temp = *head;
		
		while(temp->next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
}

void Display(PNODE head)
{
	printf("Elements from linked list are : \n");
	
	while(head != NULL)
	{
		printf("| %d |->",head->data);
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

void DeleteFirst(PPNODE head)
{
	//If LL is empty then return
	//If LL containce altest one node then
	//store the adderess of secound node int the first point through head
	//And delete the first node
	PNODE temp = NULL;
	
	if(*head == NULL)	//LL is empty
	{
		return;
	}
	else		//LL contain atleast one node
	{
		temp = *head;
		*head = temp -> next;
		free(temp);
	}
}


void DeleteLast(PPNODE head)
{}

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
	
	InsertLast(&first,111);
	InsertLast(&first,121);
	
	Display(first);
		
	iRet = Count(first);
	printf("Number of nodes are :%d\n",iRet);
	
	DeleteFirst(&first);					//using DeleteFirst...
	DeleteFirst(&first);
	
	Display(first);
		
	iRet = Count(first);
	printf("Number of nodes are :%d\n",iRet);
		
	return 0;
}

