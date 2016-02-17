
/**
 * wf.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

const int MAX_LINE_LENGTH = 2048;
const char * delimiters = " 0123456789\t;{}()[].#<>\n\r+-/%*\"^~&=!|:\\?,";

ListPtr myList;

//1 = self-organized-list 0 = std-list
static int modeVal;
int main(int argc, char *argv[]) {

  FILE * myFile;
  char* temp;


  if(argc!=2){
    printf"Usage: wf {--self-organized-list|--std-list} <textfile>"
  }
  if(argv[1]=="--self-organized-list"||"--std-list"){
    if(argv[1]=="--self-organized-list"){
      modeVal = 1;
    }else{
      modeVal = 0;
    }
  }else{
    printf"Usage: wf {--self-organized-list|--std-list} <textfile>"
  }

  myFile = fopen(argv[2],"r");
  if(myFile == NULL){
    Error("Unable to Open File");
  }


  fgets(temp,MAX_LINE_LENGTH,myFile)
    for(int i = 0; temp[i];i++){
      temp[i] = tolower(temp[i]);
    }
  WordObjPtr wordSearch;
    char* token =  strtok(temp,delimiters);
    while(token){
      wordSearch = list.search(token);
      if(wordSearch==NULL)//list.search(token)==NULL){
	createWordObject(token,1);
      }else{
      wordSearch->frequency++;
    }



    }

  
  

  

  /*
  create a wordobj of the first word
  and then use search to see if the word is already an object, if it is increase its freq.
  if it isnt create a new word object and add it to the list.
  
  */

       
  

  }

int countWords (*char word){
 
  //start from beginning of file to end of file, counting word freq
 
  int wordCount;
  

  //while(file.hasnext()){
  //if(word == file.getWord)
  //wordCount++;
  //}
 
  //addToList(word,wordCount);
}

void addToList(*char word, *int freq){


  WordObjPtr myWord = createWordObj(word,freq);
  myList.addToRear(myWord);


}



