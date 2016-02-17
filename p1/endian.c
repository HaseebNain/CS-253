#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

if(argc <2){
printf("\nUsage: endian <x>\nx: positive integer less than 4294967295\n");
return 0;
}

if(argc >= 3){
printf("Too many arguements!");
}


int value = atoi(argv[1]);


//printf("%d",value);

if(value==0){
printf("No integer found!\n");
}

if(value <0){
printf("Positive integers only!\n");
return 0;
}

if(value>4294967295){
printf("Value out of range!\n");
return 0;
}

unsigned int myValue = (unsigned int)value;

printBits(myValue);
return 1;


}


void printBits(unsigned int x){

unsigned char mask;
int i;

for(i=0;i<sizeof(unsigned int)*8;i++){

mask = 1<<i;
printf("%u",((x&mask) ? 1:0));
//x =x<<1;

}


}
