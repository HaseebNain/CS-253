
/*
	List.h: Defines the interface for a doubly-linked list.
*/

#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "Node.h"
//#include "Object.h"
#include "WordObj.h"


typedef struct list List;
typedef struct list * ListPtr;

struct list {
	int size;
	NodePtr head;
	NodePtr tail;
int (*compareTo)(const void *, const void *);
	char * (*toString)(const void *);
	void (*freeObject)(const void *);
};

/* prototypes of public methods */

/* constructor */
ListPtr createList(int(*compareTo)(const void *,const void *),
                   char * (*toString)(const void *),
		   void (*freeObject)(const void *));

void freeList(const ListPtr L); /* destructor */

int getSize(const ListPtr L);

Boolean isEmpty(const ListPtr L);

void addAtFront(ListPtr list, NodePtr node);
void addAtRear(ListPtr list, NodePtr node);

NodePtr removeFront(ListPtr list);
NodePtr removeRear(ListPtr list);
NodePtr removeNode(ListPtr list, NodePtr node);

NodePtr search(const ListPtr list, const void* key);

void reverseList(ListPtr  L);

void printList(const ListPtr L);


#endif /* __LIST_H */ 
