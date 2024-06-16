#define NUM 29
#define MAX_FILE_NAME 128
#define LOOP_INIALIZE 0
#define EXIT_CODE_ERROR 1
#define EXIT_CODE_SUCCESS 1
#define MIN_ARGUMENTS 2

/*
    define FileData data sturcture to hold up data of count of the number in position i from the hash table data sturcture, 
    and file name of each file
*/
typedef struct FileData
{
   int count;
   char fileName[MAX_FILE_NAME];
   struct FileData * next; 
} FileData;
/*
define HashTable data sturcture that holds up array in size 29 of FileData
*/
typedef struct HashTable
{
  FileData *arr[NUM];
} HashTable;

/*
define all the function that are implement in HashTable.c file
*/
HashTable* initalize_hash_table(void);
void countCalc(HashTable* hashTable, int number, char* fileName);
void parse_file(HashTable * hashTable, char* fileName);
void print_result(HashTable *HashTable);
void freeHashTable(HashTable* hashTable);
