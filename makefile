hash: hash.o HashTable.o
		gcc -ansi -Wall -pedantic hash.o HashTable.o -o hash

hash.o: hash.c HashTable.h
		gcc -c -ansi -Wall -pedantic hash.c -o hash.o

HashTable.o: HashTable.c HashTable.h
		gcc -c -ansi -Wall -pedantic HashTable.c -o HashTable.o