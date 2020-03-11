#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "helper.h"
extern char *stack_var;
extern long long int length;

//insertInOrder() inserts last element in the sorted previous array 
void insertInOrder(cc * records, long long int  n ){
	//printf("%llu place\n", n );
	cc key = records[n-1];
	//shifting the array from 0 to i that are greater than the key to right
	long long int j=n-2;
	//int j= n-2;
	for(j = n-2; j>=0 && records[j].cardno>key.cardno; j--){
		//printf("%lld \n",j );
		records[j+1] = records[j];
	}
	records[j+1] = key;
	return;
}

void insertionSort(cc * records,  long long int n){
	if(n<=1){
		char temp;
		stack_var = &temp;
		return;
	}	
//	printf("flag 1 %llu \n", n);
	insertionSort(records, n-1 );
	insertInOrder(records, n);	
}

void printRecords(cc *records, long long int num ){
	printf("\n \n");
	printf(" records are : \n");	
	for(int i =0; i< num; i++){
		printf(" cardno: %lld \n",records[i].cardno );
	}
}