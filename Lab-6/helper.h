#include<stdio.h>
#include<stdlib.h>

typedef struct record
{
	char name[10];
	float cgpa ;

} Element;




void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[] );
void mergeSort_rec(Element Ls[], int beg, int size);
void mergeSort_iter(Element Ls[], int beg, int size) ;
