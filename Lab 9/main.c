#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"helper.h"

int main(){
	int length =0;
	char ** array = parser("aliceinwonderland.txt", &length);
    int baseNumber =5;
    int tableSize = 5;
    printf("Number of valid strings are %d \n", length );
    best_hasher(array, length, &baseNumber, &tableSize);
    printf("Most optimized hasher has values : \n");\
    printf("baseNumber=%d  tableSize= %d \n",baseNumber, tableSize );
    printf("collision values finally = %d\n",collision_counter( array , length , baseNumber , tableSize ) );




	return 0;
}