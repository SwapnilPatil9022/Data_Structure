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
{
	//if LL is empty
	//if LL containce one node then delete that node and return 
	//if LL containce more than one node then travel till secound last node and delete last node 
	
	PNODE temp = NULL;
	
	if(*head == NULL)		//LL is empty
	{
		return;
	}
	else if((*head) -> next == NULL)		// LL containce one node
	{
		free(*head);
		*head = NULL;
	}
	else 	// LL containce more than one node
	{
		temp = *head;
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		free(temp -> next);
		temp -> next = NULL;
	}
}

void InsertAtPos(PPNODE head,int no, int pos)
{	
	//Conside no of nodes are 4
	
	//If position is invalid then return directly  ( < 1 OR >5)
	//if position is 1 hen call insertFirst
	//if position is N+1 hen call insertlast	(position is 5)
	
	int size = 0;
	int iCnt = 0;
	PNODE newn = NULL;
	PNODE temp = NULL;
	
	size = Count(*head);
	
	if((pos < 1) || (pos > (size+1)))					//Filter
	{
		printf("Position is invalid\n");
		return;
	}
	
	if(pos == 1)
	{
		InsertFirst(head,no);
	}
	else if(pos == (size+1))
	{
		InsertLast(head,no);
	}
	else		//Logic
	{
		newn = NULL;
	 
		newn = (PNODE)malloc(sizeof(NODE)); 	//newn = (struct node *)malloc(12)
	
		newn->data = no;
		newn->next = NULL;
		
		temp = *head;
		
		for(iCnt = 1; iCnt < pos-1; iCnt++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;
	}
}

int main()
{
	int iRet = 0;
    PNODE first = NULL;
	
	InsertFirst(&first,101);		//call by address
	InsertFirst(&first,51);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	
	InsertAtPos(&first,75,3);
	
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
		
	DeleteLast(&first);
	Display(first);
		
	iRet = Count(first);
	printf("Number of nodes are :%d\n",iRet);
		
	return 0;
}

