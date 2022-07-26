#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


typedef struct node {
	int num; // the data in this node of the list
	struct node* next; // the pointer to the next node
} Node, * NodePtr;

typedef struct llist {
	NodePtr head;
	NodePtr tail;
} LListType, * LList;



NodePtr makeNode(int n) {
	NodePtr np = (NodePtr)malloc(sizeof(Node));
	np->num = n;
	np->next = NULL;
	return np;
}

LList initLList() {
	//LList list;
	LList list = (LList)malloc(sizeof(LListType));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

//LList initLList() {
//	LList np = (LList)malloc(sizeof(struct llist));
//	
//
//}
void printList(LList list) {
	NodePtr np = list->head;
	if (list->head == NULL) {
		printf("\nEmpty");
	}
	else {
	printf("\nElements present in the Stack: \n");
	while (np != NULL) {
		printf(" %d\n", np->num);
		np = np->next;
	}
	
}

}

// implementation of stack function 
void push(int value, LList list) {
	NodePtr np = makeNode(value);
	if (list->head == NULL) {

		list->tail = np;
	}
	else {
		np->next = list->head;

	}
	list->head = np;

	//insert back
	/*NodePtr np = makeNode(value);
	if (list->head== NULL) {
		list->head = np;
	}
	else {
		list->tail->next = np;
	}
	list->tail = np;
	*/
}



int pop(LList list) {
	NodePtr np = list->head;
	if (list->head == NULL) {
		//if the list is empty
		printf("empty");
	}
	else {
		printf("\nRemoved element : % d", list->head->num);
		list->head = list->head->next;		
		free(np);

	}


}
// return the value to be removed
int top(LList list) {
	if (list->head == NULL) {
		printf("Empty");
	}
	else {
		printf("Top element(the next element to be removed) is %d", list->head->num);
	}
}

// implementation of the queue using singly linked list
// add an item to the queue
void enqueue(int value, LList list) {
	// allocate storage for new node
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> num = value;
	np -> next = NULL;
	// if empty queue, set head and tail point to it
	if(list -> head == NULL){
		list -> head = np;
		list -> tail = np;
	}
	// if queue is not empty, add it to the tail of list
	else{
		list -> tail -> next = np;
		list -> tail = np;
	}

}

// take an item off the queue
int  dequeue(LList list) {
	// end the program if the queue if empty
	if (list -> head == NULL){
		printf("The queue is empty");
		exit(1);
	}
	int hold = list -> head -> num;
	NodePtr temp = list -> head;
	list -> head = list -> head -> next;
	// queue becomes empty if head is null after remove the head node
	if (list -> head == NULL)
		list -> tail = NULL;
	free(temp);
	return hold;
}

int peek(LList list) {


}



