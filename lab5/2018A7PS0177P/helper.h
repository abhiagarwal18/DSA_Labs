#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern char *stack_var;
extern  long long int length;

typedef struct credit_card{
	unsigned long long int cardno;
	char  bcode[5];
	char expdate[7];
	char fname[50];
	char lname[50]; 
}cc;


void  insertInOrder(cc * records,  long long int n);
void  insertionSort(cc * records,  long long int n );
void  printRecords(cc * records,  long long int num);