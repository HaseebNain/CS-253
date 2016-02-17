/*
 * UnitTestList.c
 *
 *      Author: marissa
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
//#include "Object.h"
#include "WordObj.h"
#include "Node.h"
#include "List.h"

/* 
 * macro to mimic the functionality of assert() from <assert.h>. The difference is that this version doesn't exit the program entirely.
 * It will just break out of the current function (or test case in this context).
 */
#define myassert(expr) if(!(expr)){ fprintf(stderr, "\t[assertion failed] %s: %s\n", __PRETTY_FUNCTION__, __STRING(expr)); return FALSE; }

ListPtr testlist;

int testCount = 0;
int passCount = 0;

void printTestInfo(char* testName, char *info)
{
	fprintf(stdout, "%s - %s\n", testName, info);
}

void printTestResult(char* testName, Boolean passed)
{
	if(passed == TRUE)
		fprintf(stdout, "%s - %s\n\n", "[PASSED]", testName);
	else
		fprintf(stdout, "%s - %s\n\n", "[FAILED]", testName);
}

NodePtr createTestNode(char* jobword)
{
	WordObjPtr job = createWordObj(jobword, 1);
	NodePtr node = createNode(job);
	return node;
}

Boolean addAtFrontWithNoNodes()
{
	NodePtr node = createTestNode("testA");

	addAtFront(testlist, node);

	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)


         
	return TRUE;
}

Boolean addAtFrontWithOneNode()
{
	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");

	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);

	myassert(testlist->size == 2);
	myassert(testlist->head == nodeA);
	myassert(testlist->tail == node);



	return TRUE;

}

Boolean addAtRearWithNoNodes()
{
	NodePtr node = createTestNode("testA");

	addAtFront(testlist, node);

	myassert(testlist->size == 1);
	myassert(testlist->head == node);
	myassert(testlist->tail == node);



	return TRUE;

}

Boolean addAtRearWithOneNode()
{

	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");


	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);

	myassert(testlist->size == 2);
	myassert(testlist->head == nodeA);
	myassert(testlist->tail == node);


        
	return TRUE;
}

Boolean addAtRearWithTwoNodes()
{

	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");
	NodePtr nodeB = createTestNode("testA");


	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);
	addAtFront(testlist,nodeB);

	myassert(testlist->size == 3);
	myassert(testlist->head == nodeB);
	myassert(testlist->tail == node);

	return TRUE;
}




Boolean removeFromListWithOneNode()
{

	NodePtr node = createTestNode("testA");

	addAtFront(testlist, node);
	removeNode(testlist, node);



	myassert(testlist->size == 0);
	myassert(testlist->head == NULL);
	myassert(testlist->tail == NULL);

	freeNode(node,testlist->freeObject);


        
	return TRUE;
}
Boolean addAtFrontWithTwoNodes()
{

	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");
	NodePtr nodeB = createTestNode("testA");


	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);
	addAtFront(testlist,nodeB);

	myassert(testlist->size == 3);
	myassert(testlist->head == nodeB);
	myassert(testlist->tail == node);




        
	return TRUE;
}

Boolean nullNodeTest()
{
 	NodePtr node = createTestNode("testA");

	addAtFront(testlist, node);

	myassert(testlist->size == 1);
	myassert(testlist->head == node);
	myassert(testlist->tail == node);


        
	return TRUE;


}

Boolean removeNodeOnListWithOneNode()
{
	NodePtr node = createTestNode("testA");


	addAtFront(testlist, node);
	


	
	removeNode(testlist,node);


	myassert(testlist->size == 0);
	myassert(testlist->head == NULL);
	myassert(testlist->tail == NULL);

	freeNode(node,testlist->freeObject);


       
	return TRUE;

}

Boolean getSizeOnListWithOneNode()
{
	NodePtr node = createTestNode("testA");
	addAtFront(testlist, node);

	myassert(testlist->size == 1);




	return TRUE;
	
}


Boolean getSizeOnListWithTwoNodes()
{
	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");
	addAtFront(testlist, node);
	addAtFront(testlist,nodeA);
	myassert(testlist->size == 2);

        
	return TRUE;

}


Boolean isEmptyTestOnEmptyList()
{


	myassert(testlist->size == 0);
	myassert(isEmpty(testlist)==1);

        
	return TRUE;
	
}

Boolean isEmptyTestOnNotEmptyList()
{
  
	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");
	addAtFront(testlist, node);
	addAtFront(testlist,nodeA);

	myassert(testlist->size == 2);
	myassert(isEmpty(testlist)==0);


	return TRUE;

}

Boolean removeRearOnListWithOneNode()
{
	NodePtr node = createTestNode("testA");

	addAtFront(testlist, node);

	removeRear(testlist);
	myassert(testlist->size == 0);
	
	myassert(testlist->head == NULL);
	myassert(testlist->tail == NULL);
	freeNode(node,testlist->freeObject);

 
	return TRUE;

}

Boolean removeFrontOnListWithOneNode()
{
	NodePtr node = createTestNode("testA");

	addAtFront(testlist, node);

	removeFront(testlist);
	myassert(testlist->size == 0);

	 myassert(testlist->head == NULL);
	 myassert(testlist->tail == NULL);


	freeNode(node,testlist->freeObject);

	return TRUE;

}

Boolean removeFrontOnListWithTwoNodes()
{
	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");

	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);

	removeFront(testlist);
	myassert(testlist->size == 1);

	 myassert(testlist->head == node);
	 myassert(testlist->tail == node);



	freeNode(nodeA,testlist->freeObject);
 
	return TRUE;

}

Boolean removeRearOnListWithTwoNodes()
{
	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");

	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);

	removeRear(testlist);
	myassert(testlist->size == 1);

	myassert(testlist->head == nodeA);
	myassert(testlist->tail == nodeA);

	freeNode(node,testlist->freeObject);


	return TRUE;

}

Boolean searchTestOnListWithNode()
{
	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testB");

	WordObjPtr testSearch = createWordObj("testA",1);
	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);

	myassert(testlist->size == 2);
	myassert(testlist->head == nodeA);
	myassert(testlist->tail == node);

	myassert(search(testlist,testSearch)==node);

        

	return TRUE;

}

Boolean searchTestOnListWithOutNode()
{
	NodePtr node = createTestNode("testB");
	NodePtr nodeA = createTestNode("testB");

	WordObjPtr testSearch = createWordObj("testA",1);
	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);

	myassert(testlist->size == 2);
	myassert(testlist->head == nodeA);
	myassert(testlist->tail == node);

	myassert(search(testlist,testSearch)==NULL);


	return TRUE;

}

Boolean reverseListTestWithOneNode()
{
	NodePtr node = createTestNode("testA");

	addAtFront(testlist, node);

	reverseList(testlist);
	myassert(testlist->size == 1);

	  myassert(testlist->head == node);
	  myassert(testlist->tail == node);

       
	return TRUE;

}

Boolean reverseTestOnListWithTwoNodes()
{
	NodePtr node = createTestNode("testA");
	NodePtr nodeA = createTestNode("testA");

	addAtFront(testlist, node);
	addAtFront(testlist, nodeA);

	reverseList(testlist);
	myassert(testlist->size == 2);
	myassert(testlist->head == node);
	myassert(testlist->tail == nodeA);


	return TRUE;
}





void beforeTest(char* testName)
{
	printTestInfo(testName, "Running...");
	testlist = createList(compareTo, toString, freeWordObj);
	testCount++;
}
void afterTest(char* testName, Boolean result)
{
	printTestResult(testName, result);
	freeList(testlist);
	passCount += result;
}




void runUnitTests()
{
	Boolean result;
	char *testName;

	testName = "addAtFrontWithNoNodes";
	beforeTest(testName);
	result = addAtFrontWithNoNodes();
	afterTest(testName, result);

	testName = "addAtFrontWithOneNode";
	beforeTest(testName);
	result = addAtFrontWithOneNode();
	afterTest(testName, result);

	testName = "addAtFrontWithTwoNodes";
	beforeTest(testName);
	result = addAtFrontWithTwoNodes();
	afterTest(testName, result);


	testName = "addAtRearWithNoNodes";
	beforeTest(testName);
	result = addAtRearWithNoNodes();
	afterTest(testName, result);

	testName = "addAtRearWithOneNode";
	beforeTest(testName);
	result = addAtRearWithOneNode();
	afterTest(testName, result);

	testName = "addAtRearWithTwoNodes";
	beforeTest(testName);
	result = addAtRearWithTwoNodes();
	afterTest(testName, result);


	testName = "removeFromListWithOneNode";
	beforeTest(testName);
	result = removeFromListWithOneNode();
	afterTest(testName, result);

	testName = "nullNodeTest";
	beforeTest(testName);
	result = nullNodeTest();
	afterTest(testName, result);

	testName = "removeNodeOnListWithOneNode";
	beforeTest(testName);
	result = removeNodeOnListWithOneNode();
	afterTest(testName,result);

	testName = "getSizeOnListWithOneNode";
	beforeTest(testName);
	result = getSizeOnListWithOneNode();
	afterTest(testName,result);

	testName = "getSizeOnListWithTwoNodes";
	beforeTest(testName);
	result = getSizeOnListWithTwoNodes();
	afterTest(testName,result);

	testName = "isEmptyTestOnEmptyList";
	beforeTest(testName);
	result = isEmptyTestOnEmptyList();
	afterTest(testName,result);

	testName = "isEmptyTestOnNotEmptyList";
	beforeTest(testName);
	result = isEmptyTestOnNotEmptyList();
	afterTest(testName,result);

	testName = "removeRearOnListWithOneNode";
	beforeTest(testName);
	result = removeRearOnListWithOneNode();
	afterTest(testName,result);

	testName = "removeFrontOnListWithOneNode";
	beforeTest(testName);
	result = removeFrontOnListWithOneNode();
	afterTest(testName,result);

	testName = "removeFrontOnListWithTwoNodes";
	beforeTest(testName);
	result = removeFrontOnListWithTwoNodes();
	afterTest(testName,result);

	testName = "removeRearOnListWithTwoNodes";
	beforeTest(testName);
	result = removeRearOnListWithTwoNodes();
	afterTest(testName,result);

	testName = "searchTestOnListWithNode";
	beforeTest(testName);
	result = searchTestOnListWithNode();
	afterTest(testName,result);

	testName = "searchTestOnListWithOutNode";
	beforeTest(testName);
	result = searchTestOnListWithOutNode();
	afterTest(testName,result);

	testName = "reverseListTestWithOneNode";
	beforeTest(testName);
	result = reverseListTestWithOneNode();
	afterTest(testName,result);

	testName = "reverseListTestWithTwoNodes";
	beforeTest(testName);
	result = reverseTestOnListWithTwoNodes();
	afterTest(testName,result);


	//etc.../**



	fprintf(stdout, "Test Cases: %d\n",  testCount);
	fprintf(stdout, "Passed: %d\n", passCount);
	fprintf(stdout, "Failed: %d\n", testCount - passCount);
}

int main(int argc, char *argv[])
{
	runUnitTests();
	exit(0);
}
