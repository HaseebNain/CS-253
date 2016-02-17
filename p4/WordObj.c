



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "WordObj.h"


WordObjPtr createWordObj(const char *word, const unsigned long int freq){

  WordObjPtr  newObject = (WordObjPtr) malloc (sizeof(WordObj));
  newObject->frequency = freq;
  newObject->word = (char *) malloc(sizeof(char)*(strlen(word)+1));
  
  strcpy(newObject->word,word);

  return newObject;


}



char *toString(const void *obj){

	WordObjPtr myobj = (WordObjPtr) obj;
	char *temp;
	temp = (char *)malloc(sizeof(char)*strlen(myobj->word)+1+MAX_WORD_LENGTH+4);
	sprintf(temp, "[%s] %lu", myobj->word, myobj->frequency);
	return temp;

}
void freeWordObj(const void *obj){

	WordObjPtr myobj = (WordObjPtr) obj;
	if (myobj == NULL) return;
	free(myobj->word);
	free(myobj);

}
int compareTo(const void *str1, const void *str2)
{

  WordObjPtr val = (WordObjPtr)str1;
  WordObjPtr val2 = (WordObjPtr)str2;

  // char *strVal = (((WordObj)(str1))->word);
  //char *strVal2 =(((WordObj)(str2))->word);// (char*)str2;
 
  // printf("%s",(str1)->word);

  return strcmp((val->word), (val2->word));

}
