#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

/*
 initalize the HashTable, and set each posistion in the HashTable array to NULL
*/
HashTable* initalize_hash_table(void){
    size_t i;
    HashTable *hashTable = malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        fprintf(stderr, "Memory allocation failed for hashTable\n");
        exit(EXIT_CODE_ERROR);  
    }
    for (i = LOOP_INIALIZE; i < NUM; i++)
    {
       hashTable -> arr[i] = NULL;
    }
    return hashTable;
}
/*
    find the currect file in position number in the HashTable, and increaseing count by 1
*/

void countCalc(HashTable* hashTable, int number, char* fileName) {
    FileData * fileNode;
    FileData* newNode;
    if (number < 0 || number >= NUM) {
        printf("the current number: %d from the file: %s is not from the range [0,28],so we skip on it\n",number,fileName);
        return;
    }
    fileNode = hashTable -> arr[number];
    while(fileNode != NULL){
        if(strcmp(fileNode ->fileName , fileName)==0){
            fileNode ->count++;
            return;
        }
        fileNode = fileNode -> next;
    }

    /* if there is no current number in the current file until now, then create node that holds the file with the number */
   newNode = malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        fprintf(stderr, "Memory allocation failed for newNode\n");
        exit(EXIT_CODE_ERROR);  
    }
   newNode ->count = 1;
   strcpy(newNode->fileName,fileName);
   newNode ->next = hashTable -> arr[number];
   hashTable -> arr[number] = newNode;
}
/*
takes file name as input and if it succeeded open it, then moving to countCalc function with the current number and file name.
*/

void parse_file(HashTable * hashTable, char* fileName){

    int number; 
    FILE* file = fopen(fileName,"r");
    if (!file) {
        fprintf(stderr, "Error: cannot open file %s\n", fileName);
        exit(EXIT_CODE_ERROR);
    }
    while(fscanf(file,"%d",&number)==1){
        countCalc(hashTable,number,fileName);
    }

    fclose(file);

}
/*
    print the reuslt by iterate on every position in the HashTable array,
    and for each position iterate over all the FileData nodes and print the count inside each file
*/

void print_result(HashTable *HashTable){
    char string[10];
    size_t i;
    for (i = LOOP_INIALIZE; i < NUM; i++)
    {
        if(HashTable -> arr[i] !=NULL){
            FileData *node = HashTable -> arr[i];
            printf("%zu appears in",i);
            while(node!=NULL){
                if(node->count == 1) strcpy(string,"time");
                else strcpy(string,"times");
                printf(" file %s - %d %s",node->fileName, node -> count, string);
                if(node -> next!= NULL) printf(",");
                node = node ->next;
            }
        printf("\n");
        }
    }
}
/*
  perform free command on each node of FileData
*/

void freeHashTable(HashTable* hashTable) {
    int i;
    for (i = LOOP_INIALIZE; i < NUM; i++) {
        FileData* current = hashTable->arr[i];
        while (current != NULL) {
            FileData* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable);
}
