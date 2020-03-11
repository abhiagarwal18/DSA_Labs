#include<stdlib.h>
#include<stdio.h>
#include"helper.h"


void mergeSort_iter(Element Ls[], int beg, int size){
	int i=0;
	int j=0;

	//printf("flag1 \n");
	int block_size = 1;
	for(block_size =1; block_size<size; block_size*=2){
	for(i=0; i<size; i = i + 2*block_size ){
		int start1 = i;
		int start2 = i+ block_size;
		//printf("%d\n", block_size);
		int size1 = (block_size< size-start1)? block_size : size-start1;
		int size2 = (block_size < size-start2 )? block_size : size-start2;
		//printf("start1 %d start2 %d size1%d size2 %d \n", start1, start2, size1, size2 );

		Element temp[block_size*2];
		if(start2<size){
		merge(Ls+start1, size1, Ls+start2, size2, temp);
		for(int m=0; m< size1+size2; m++){
			Ls[start1+m]= temp[m];
		}}
		}
	}
}

