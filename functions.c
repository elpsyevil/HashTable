#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"


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
