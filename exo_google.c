#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int is_in_array(char c, char array[], int len)
{
	for (int i=0; i<len; i++){
		if(c==array[i]) return 1;
	}
	return 0;
}



char recurrent_letter(char* input){
    char letter_arr[1024]={0};
    int	 letter_arr_cnt=0;
    int len = 0;
    len = strlen(input);
    for (int i=0; i<len; i++){
	    if(is_in_array(input[i], letter_arr, len)) 
		return input[i];
	    else
		letter_arr[letter_arr_cnt++] = input[i];
    }
    return NULL;
	
}


int main() {
	printf("Input: ");
	char * input = calloc(1024, sizeof(char));
	fgets(input, 1024, stdin);
	char d = recurrent_letter(input);
	printf("%c", d);
	return 0;
}
