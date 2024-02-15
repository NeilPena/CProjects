#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int counter = 0; 
	while(head != NULL){
		head = head -> next;
		counter++;
	} 
	return counter;
	
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int i = 0; 
	int count = length(head);
	char *str = (char*) malloc(sizeof(char) * (count + 1));
	node *tmp = head;
	while(tmp != NULL){
		str[i] = tmp -> letter;
		tmp = tmp -> next;
		i++;
	} 
	str[count] = '\0';
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *newNode = (node*) malloc(sizeof(node));
	newNode -> letter = c; 
	newNode -> next = NULL;
	if(*pHead == NULL){
		*pHead = newNode;
	}
	else{
		node *tmp;  
		tmp = *pHead; 
		while(tmp -> next != NULL){
			tmp = tmp -> next; 
		} 
		tmp -> next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node *tmp = *pHead;
	while(tmp != NULL){
		*pHead = tmp -> next; 
		free(tmp);
		tmp = *pHead;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}