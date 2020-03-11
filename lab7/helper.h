#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[10];
	long long int empid;
} record;



void swapRecords( record * rec1, record * rec2 );
int partition(record * data, int beg, int end) ;
void quicksortIter(record * data, int start, int end, int S);
void insertionsortIter( record * data , int len);
void mySort(record * data, int len, int S);
void printRecords(record * data, int len);
void test_run(record * data,int len, int max_len, double* istime, double* qstime);
int estimate_cutoff(record * data,int len, double approx_range);
