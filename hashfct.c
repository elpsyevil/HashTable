#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"



int hashFct(char* nom){
	int h = 0;

	for (int i=0;i<strlen(nom);i++){
		h+=(int)nom[i];
	}

return h%SIZE;
}