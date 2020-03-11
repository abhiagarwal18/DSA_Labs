#include<stdlib.h>
#include<stdio.h>
#include"helper.h"
extern char * stackvar;

void mergeSort_rec(Element Ls[], int beg, int size){
	if(size<=1){
		char temp;
		stackvar=&temp;
			return;
		}
		int middle = (size)/2;
		Element Ls1[middle];
		Element Ls2[size-middle];
		for(int i = 0; i < (middle); ++i)
			Ls1[i] = Ls[i];
		for(int i = 0; i < (size-middle); ++i)	
			Ls2[i] = Ls[middle+i];
		mergeSort_rec(Ls1, 0, middle);
		mergeSort_rec(Ls2, 0, size-middle);
		merge(Ls1,(middle), Ls2, (size-middle), Ls  );

}
