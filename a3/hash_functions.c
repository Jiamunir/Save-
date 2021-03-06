#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 8

/* Computes hash for data provided via fread and stores it in hash_val,
*  an array of char. The hash implementation is based on xor and the
*  computed hash is at most block_size bytes.
*/

char *hash(FILE *f) {
 int i;
// char* hash_val;
 char *hash_val = malloc(BLOCK_SIZE);
		for(i = 0; i < BLOCK_SIZE; i++) {//initializing block_size bytes of hash_val to value 0
			hash_val[i] = '\0';
			}

 char store_char;
 int j = 0;
		while(feof(f) == 0){ //end of file hasn't been reached
		if(fread(&store_char, 1, 1, f) == 1){ //read and store one char at a time
				if(j < BLOCK_SIZE) {
						hash_val[j]= (hash_val[j])^store_char;
						j++;
					}
				else { // j == block_size, computation wraps around
						j = 0;
						hash_val[j] = (hash_val[j])^store_char;
						j++;
				   }
				}
			}

	return hash_val;
}
