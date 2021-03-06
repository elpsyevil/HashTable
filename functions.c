#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

void insert(char* name,int age) {

   DataItem *item = (DataItem*) malloc(sizeof(DataItem));
   item->name = name;  
   item->age= age;

   //get the hash 
   int hashIndex = hashFct(name);

   //move in array until an empty !!!!!! hadi machi daroria or deleted cell
   while(hashArray[hashIndex] != NULL) {
      //go to next cell
      ++hashIndex;
      
      //wrap around the table
      hashIndex %= SIZE;
   }
   
   hashArray[hashIndex] = item;
}


void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%s,%d)",hashArray[i]->name,hashArray[i]->age);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}


void delete(DataItem* item) {
   int name= item->name;

   //get the hash 
   int hashIndex = hashFct(name);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
   
      if(hashArray[hashIndex]->name == name) {
         DataItem* temp = hashArray[hashIndex]; 
         
         //assign a dummy item at deleted position || set to NULL
         hashArray[hashIndex] = NULL; 
         return temp;
      }
      
      //go to next cell
      ++hashIndex;
      
      //wrap around the table
      hashIndex %= SIZE;
   }      
   
   return NULL;        
}

int hashFct(char* nom){
   int h = 0;

   for (int i=0;i<strlen(nom);i++){
      h+=(int)nom[i];
   }

   return h%SIZE;
}

struct DataItem *search(int key) {

  int hashIndex = hashFct(key);

   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];

      ++hashIndex;

      hashIndex %= SIZE;
   }

   return NULL;
}

