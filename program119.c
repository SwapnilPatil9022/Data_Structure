//Singly Linear Link list
/*
	InsertFirst
	InsertLast
	InsertAtPosition
	
	DeleteFirst
	DeleteLast
	DeleteAtPosition
	
	Display
	Count
*/

/*
	1.Allocate the memory for node
	2.Initialise the node
	3.check whether the LL is empty or not.
	4.If LL is empty

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

//jun nav             navin nav
//struct node        NODE
//struct node*       PNODE
//struct node**      PPNODE

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = iNo;
	newn -> next = NULL;
	
	if(*Head == NULL)		//IF LL is empty
	{
		*Head = newn;
	}
	else		//If LL Contence atleast one node
	{
		newn -> next = *Head;
		*Head = newn;
	}
}

void Display(PNODE Head)
 {
	 while(Head != NULL)
	 {
		 printf("%d\t",Head -> data);
		 Head = Head -> next;
	 }
 }
			
int main()
{
	PNODE First = NULL;		//struct node *First = NULL;
	
	InsertFirst(&First,101);		//InsertFirst(60,101);
	InsertFirst(&First,51);			//InsertFirst(60,51);
	InsertFirst(&First,21);			//InsertFirst(60,21);
	InsertFirst(&First,11);			//InsertFirst(60,11);
	
	Display(First);
	
	return 0;
}

//Rules
/*
	1. Use only dynamic memoery allocation
	2.Don't write any techniqual syntax in main
	3.Don't use any global variables
	4.Be careful while manipulating the First pointer
	5.Past the First pointer directly if the function is not going to modify the LL.	(Display Count)
	6.Pass the address of the First pointer if the function is going to mpodify the LL.
	(InsertFirst,InsertLast,InsertAtPosition,DeleteFirst,DeleteLast,DeleteAtPosition))

*/