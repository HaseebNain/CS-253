
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "WordObj.h"


#define true 1
#define false 0

#define DEBUG 0


/* P4 List.c */

//static NodePtr reverse(NodePtr);
static void print(const NodePtr node, char * (*toString)(const void *));

ListPtr createList(int(*compareTo)(const void *,const void *), 
                   char * (*toString)(const void *),
		   void (*freeObject)(const void *))
{



	ListPtr list;
	list = (ListPtr) malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->compareTo = compareTo;
	list->toString = toString;
	list->freeObject = freeWordObj;
	return list;
}

/**
 * Frees all elements of the given list and the <code>ListPtr</code> itself. 
 * Does nothing if L is <code>NULL</code>.
 *
 * @param L a pointer to a <code>List</code>.
 */
void freeList(const ListPtr list)
{

  if(list==NULL){
    return;
  }else{

    NodePtr curr = list->head;

    while(curr){//->next){ 
	NodePtr next = curr->next;
     freeNode(curr,list->freeObject);
     curr=NULL;
     curr = next;
     }
     free(list);
  }
} 


/**
 * Returns the size of the given list.
 *
 * @param L a pointer to a <code>List</code>.
 * @return The current size of the list.
 */
int getSize(const ListPtr L){

 if(L==NULL)
    return 0;

  return L->size;
}

/**
 * Checks if the list is empty.
 *
 * @param  L a pointer to a <code>List</code>.
 * @return true if the list is empty; false otherwise.
 */
Boolean isEmpty(const ListPtr L)
{



  if(L->size == 0||L==NULL)
    return true;
  else
    return false;

}

/**
 * Adds a node to the front of the list. After this method is called,
 * the given node will be the head of the list. (Node must be allocated
 * before it is passed to this function.) If the list and/or node are NULL,
 * the function will do nothing and return.
 *
 * @param list a pointer to a <code>List</code>.
 * @param node a pointer to the node to add.
 */
void addAtFront(ListPtr list, NodePtr node)
{
	if (list == NULL) return;
	if (node == NULL) return;

	node->next = list->head;
	node->prev = NULL;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		list->head = node;
	}
 	list->size++;
}

/**
 * Adds a node to the rear of the list. After this method is called,
 * the given node will be the tail of the list. (Node must be allocated
 * before it is passed to this function.) If the list and/or node are NULL,
 * the function will do nothing and return.
 *
 * @param list a pointer to a <code>List</code>.
 * @param node a pointer to the node to add.
 */
void addAtRear(ListPtr list, NodePtr node)
{

  if(node == NULL)
    return;// list;

   

  if(list == NULL)
    return;

  if(isEmpty(list)){
    list->head = node;
    list->tail = node;
    node->next = NULL;
    node->prev = NULL;

  }else{
  

    (list->tail)->next = node;
   
    node->prev = list->tail;
   list->tail = node;
  }
  list->size++;
 
}

/**
 * Removes the node from the front of the list (the head node) and returns
 * a pointer to the node that was removed. If the list is NULL or empty,
 * the function will do nothing and return NULL.
 *
 * @param list a pointer to a <code>List</code>.
 * @return a pointer to the node that was removed.
 */
NodePtr removeFront(ListPtr list)
{
if(isEmpty(list)||list == NULL)
      return NULL;


  NodePtr temp = list->head;
  if(list->size==1){
  list->head=list->tail=NULL;
  }
  if(list->size==2){
  list->head = list->tail;
  list->tail->prev = NULL;
  }
  if(list->size>=3){
        list->head = NULL;//list->head->next;
	list->head = temp->next;
	list->head->prev = NULL;
  }
  
  list->size--;      
  return temp;
  }


/**
 * Removes the node from the rear of the list (the tail node) and returns
 * a pointer to the node that was removed. If the list is NULL or empty,
 * the function will do nothing and return NULL.
 *
 * @param list a pointer to a <code>List</code>.
 * @return a pointer to the node that was removed.
 */
NodePtr removeRear(ListPtr list)
{
   if(isEmpty(list)||list == NULL)
      return NULL;
	 
   
      NodePtr temp = list->tail;
      
      
      if(list->size==1)
      list->head=list->tail=NULL;
     
      if(list->size==2){
      
      list->tail = list->head;
      list->head->next = NULL;
     
      
      }
      if(list->size>=3){
      
      	list->tail = NULL;
	list->tail = temp->prev;
	list->tail->next = NULL;
	//  list->tail=temp->prev;
	//      list->tail->next = NULL;
      
      }
      
      
   
		
   	 list->size--;
     return temp;
  
  }



/**
 * Removes the node pointed to by the given node pointer from the list and returns
 * the pointer to it. Assumes that the node is a valid node in the list. If the node 
 * pointer is NULL, the function will do nothing and return NULL. 
 *
 * @param list a pointer to a <code>List</code>.
 * @param node a pointer to the node to remove.
 * @return a pointer to the node that was removed.
 */
NodePtr removeNode(ListPtr list, NodePtr node)
{

  NodePtr tmp = node;

if(list == NULL)
 return NULL;
if(node == NULL)
return NULL;


 if(list->size==1){
   list->head = list->tail = NULL;
   list->size--;
   return tmp;
 }
   
 if(list->size==2){
   
   if(node==list->head){
     list->head = list->tail;
     list->tail->prev=NULL;

   }
   if(node==list->tail){
     list->tail = list->head;
          list->head->next = NULL;
   }

   list->size--;
   return tmp;
   

 }

//checks to see if the node is at the front of the list, if it is not than the node is removed and the pointers will point around the node.
  if(node==list->head){
   
   list->head = node->next;
     list->head->prev = NULL;
   list->size--;
     return tmp;
   
 }
if(node==list->tail){
  list->tail = node->prev;
     list->tail->next = NULL;
   list->size--;
     return tmp;
 }


   node->next->prev = node->prev;
   node->prev->next = node->next;
   node = NULL;

 list->size--;
 return tmp;

}

/**
 * Searches the list for a node with the given key and returns the pointer to the
 * found node.
 *
 * @param list a pointer to a <code>List</code>.
 * @param key the value of the key to search for.
 * @return a pointer to the node that was found. Or <code>NULL</code> if a node with the given key is not 
 * found or the list is <code>NULL</code> or empty.
 */
NodePtr search(const ListPtr list, const void* key)
{

  if(list==NULL) return NULL;

  NodePtr curr = list->head;
  
  //  NodePtr keyNode = createNode(key);
  while(curr!=NULL){

    //comapres the jobid to the key, returning the node if it is found
    // printf("%s",((WordObj)(key))->word);
    if(list->compareTo(curr->obj,key)==0){
      return curr;
    }
      curr = curr->next;
  }
  return NULL;
  	
}

/**
 * Reverses the order of the given list.
 *
 * @param list a pointer to a <code>List</code>.
 */
void reverseList(ListPtr list)
{
 
if(isEmpty(list)||list->size==1){
 return;
 } else{ 

   NodePtr curr = list->head; 
   NodePtr temp = NULL;   

   NodePtr newHead = list->tail;
   NodePtr newTail = list->head;


   while (curr!=NULL){ 
      
        //walks through the list, swapping the next and previous pointers. Must traverse the list backwards because
        // next is actually previous in this case. 
        temp = curr->prev; 
        curr->prev = curr->next; 
        curr->next = temp;               
        curr = curr->prev;
	
      }      

   list->head = newHead;
   list->tail = newTail;
 }

  
}

void printList(const ListPtr list)
{
	if (list) print(list->head, list->toString);
}



static void print(const NodePtr node, char * (*toString)(const void *))
{
	int count = 0;
	char *output;
        NodePtr temp = node;
	while (temp) {
		output = (*toString)(temp->obj);
		printf(" %s -->",output);
		free(output);
		temp = temp->next;
		count++;
		if ((count % 6) == 0)
			printf("\n");
	}
    printf(" NULL \n");
}
 

		

