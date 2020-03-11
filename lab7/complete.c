#include<stdlib.h>
#include<stdio.h>
#include"helper.h"
#include<math.h>
#include<stdbool.h>
#include<sys/time.h>


void swapRecords( record * rec1, record * rec2 ){
	record  temp = * rec1;
	* rec1 = *rec2;
	* rec2 = temp;
	return;
}

//beg and end are the array index of the records


int partition(record * data, int beg, int end) { 	
	long long int temp = data[end].empid;
	//printf("temp = %lld \n",temp );
    int i = (beg - 1); //before the beginning index
    for (int j = beg; j <end ; j++) { 
        if (data[j].empid <= temp) { 
            i++; 
            swapRecords(&data[i], &data[j]); 
        } 
    } 
    swapRecords(&data[i + 1], &data[end]); 
    return (i + 1); 
} 

void quicksortIter(record * data, int start, int end, int S){
	int len = end-start+1;
	int explicit_stack[len];
	int top = -1; //To denote the initial header of the stack
	explicit_stack[++top]=start;
	explicit_stack[++top]= end;

	//printf("flag 1\n");
	while(top>=0){
		//printf("flag2\n");

		end = explicit_stack[top--];
		start = explicit_stack[top--];
		int pivot = partition(data, start, end);
		if(end-start+1 <= S  ){
			continue;
		}

			if(pivot-start-1>0){
			explicit_stack[++top] =start;
			explicit_stack[++top]= pivot-1;}
			if(end-pivot-1>0){
			explicit_stack[++top] =pivot+1;
			explicit_stack[++top] =end;}
	}
}
void insertionsortIter( record * data , int len){
	for(int i =1;i< len; i++){
		record key = data[i];
		int j = i-1;
		while(j>=0 && data[j].empid>key.empid){
			data[j+1]= data[j];
			j--;
		}
		data[j+1] =key;
	}
	return;
}

void mySort(record * data, int len, int S){
	quicksortIter(data, 0,len-1, S);
	insertionsortIter(data, len);
}

void printRecords(record * data, int len){
	for(int i=0; i<len; i++){
		printf("Name = %s   empid = %lld \n",data[i].name, data[i].empid );

	}
	return;
}



void test_run(record * data,int len, int max_len, double* istime, double* qstime) {
	
	record * data_copy = (record * )malloc(sizeof(record) * len );
	for(int i=0; i<len; i++){
		data_copy[i]=data[i];
	}
	
	len = (len < max_len ? len : max_len);
	double elapsed_time_1, elapsed_time_2;
	struct timeval t1, t2,t3,t4;
	gettimeofday(&t1, NULL);
	insertionsortIter(data, len);
	gettimeofday(&t2, NULL);
	elapsed_time_1 = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsed_time_1 += (t2.tv_usec - t1.tv_usec) / 1000.0;
	*istime = elapsed_time_1;
	

	gettimeofday(&t3, NULL);
	quicksortIter(data_copy,0,len-1,0 );
	gettimeofday(&t4, NULL);
	elapsed_time_2 = (t4.tv_sec - t3.tv_sec) * 1000.0;
	elapsed_time_2 += (t4.tv_usec - t3.tv_usec) / 1000.0;
	*qstime = elapsed_time_2;
	
	
}

int estimate_cutoff(record * data, int len,  double approx_range) {
	double istime, qstime;
	
	int min = 10, max = 1000;
	do {
		printf(" NEW ITERATION FOR CUTOFF ! \n");
		int mid = (min + max) / 2;
		test_run(data,len, mid, &istime, &qstime);
		printf("middle = %d  istime = %lf, qstime = %lf\n", mid, istime, qstime);
		if(fabs(istime - qstime) < approx_range) return mid;
		else max = mid;
	} while(true);
}

