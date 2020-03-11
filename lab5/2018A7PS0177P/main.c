#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include "helper.h"
long long int length =0; //global variable
char * stack_var;
int main(){
	FILE * fptr;
	//fptr = fopen("10", "r");
	//fptr = fopen("100", "r");
	//fptr = fopen("1000", "r");
	//fptr = fopen("10000", "r");
	//fptr = fopen("20000", "r");
	//fptr = fopen("50000", "r");
	//fptr = fopen("80000", "r");
	fptr = fopen("100000", "r");
	//fptr = fopen("1000000", "r");
	//fptr = fopen("10000000", "r");
	if(fptr == NULL){
		printf(" ERROR! can't open the file \n");
		exit(1);
	}

	struct timeval t1, t2;
	double elapsedTime;
	int size = 100;
	cc * records = (cc *) malloc(sizeof(cc) * size);
	const char * ftemplate = "\"%llu,%[^,],%[^,],%[^,],%[^\"]\"";
	
	while(!feof(fptr)){
		cc temp;
		fscanf(fptr, ftemplate, &temp.cardno,temp.bcode,temp.expdate,temp.fname, temp.lname);
		fgetc(fptr);
	if(length+1> size){
	
			size = size *2;
			records=(cc *)realloc(records, sizeof(cc)*size);
		}
		records[length] = temp;
		length++;
		//printf("record number %llu read \n", length);
	}
	
	fclose(fptr);
	printf("Total number of records in the list = %lld \n", length);
	printf("File has been read successfully \n");
	//printRecords(records, length);
	gettimeofday(&t1,NULL);
	printf("Sorting now :\n");
	char trial;
	char * stackbase = &trial;
	insertionSort(records, length);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; 
	
	
	//printf("%ld \n",temp );
	printRecords(records, length);
	printf("Total time is %lf ms.\n", elapsedTime);
	long long int stack_space_used = (long long int) (stackbase-stack_var);
	printf("Stack Space used = %lld \n", stack_space_used );

	return 0;
}

