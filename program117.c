#include<stdio.h>
#include<stdlib.h>

//Structer declaration
struct node
{
	int data;					//4
	struct node *next;			//8
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
//jun nav             navin nav
//struct node        NODE
//struct node*       PNODE
//struct node**      PPNODE

int main()
{
	//static memory allocation 
	NODE obj;
	
	//Dynamic memory allocation
	PNODE ptr = (PNODE)malloc(sizeof(NODE));
	
	obj.data = 11;		//Direct accessing operator .
	obj.next = NULL;
	
	ptr -> data = 11;	//Indireact accessing operator ->
	ptr -> next = NULL;
	
	return 0;
}