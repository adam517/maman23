#include <stdio.h>
#include "HashTable.h"

/**
 * This program takes file names arguments, counts and prints how many times each number is presenting in each file
 * 
*/


int main(int argc, char* argv[]) {
    int i;
    HashTable * hashTable = initalize_hash_table();
    if(argc < MIN_ARGUMENTS) printf("no arguments enters, exit from program\n");
        for(i=LOOP_INIALIZE + 1;i<argc;i++){
            parse_file(hashTable,argv[i]);
        }
    print_result(hashTable);    
    freeHashTable(hashTable);
    return EXIT_CODE_SUCCESS;
}
