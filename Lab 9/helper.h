#include<stdio.h>
#include<stdlib.h>

int hasher( char * string , int baseNumber , int tableSize );
int collision_counter( char **array , int length , int baseNumber , int tableSize );
//char ** parser(char * filename, int * length);
char **parser(char * filename, int * length);

void best_hasher(char ** array, int length, int * baseNumber, int * tableSize );

