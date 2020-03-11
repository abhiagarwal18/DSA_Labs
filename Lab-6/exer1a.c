#include<stdlib.h>
#include<stdio.h>
#include"helper.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	
	int i=0;
	int j=0;
	int k=0;
	while( i<sz1 && j< sz2) {
		if(Ls1[i].cgpa<=Ls2[j].cgpa){
			Ls[k++]= Ls1[i++];
		}
		else{
			Ls[k++]=Ls2[j++];
		}
	}
	while(i<sz1){
		Ls[k++]= Ls1[i++];
	}

	while(j<sz2){
			Ls[k++] = Ls2[j++];
		}
	
	return;

}
/* RECURSIVE*/
void mergeSort(Element Ls[], int beg, int size){
	if(size<=1){
			return;
		}
		int middle = (size)/2;
		Element Ls1[middle];
		Element Ls2[size-middle];
		for(int i = 0; i < (middle); ++i)
			Ls1[i] = Ls[i];
		for(int i = 0; i < (size-middle); ++i)	
			Ls2[i] = Ls[middle+i];
		mergeSort(Ls1, 0, middle);
		mergeSort(Ls2, 0, size-middle);
		merge(Ls1,(middle), Ls2, (size-middle), Ls  );

}


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



int main(){

	FILE * fptr;
	fptr = fopen("1024.txt", "r");
	if(fptr == NULL){
		printf(" ERROR! can't open the file \n");
		exit(1);
	}
	int length=0;
	int size =10;
	Element * data = (Element * )malloc(sizeof(Element)*size);

	const char * ftemplate = "%[^,],%f\n";
	while(!feof(fptr)){
		Element temp;
		fscanf(fptr, ftemplate, temp.name,&temp.cgpa);
		fgetc(fptr);
		if(length+1 > size){
			size=size*2;
			data = (Element *)realloc(data, sizeof(Element)*size);
		}

			data[length] = temp;
			length++;
			//printf("record number %d read \n", length);
	}

Element test[] = {
		{"", 1},
		{"", 2},
		{"", 1.5},
		{"", 7},
		{"", 9.5},
		{"", 1.2},
		{"", 3.0},
		{"", 4.12},
		{"", 3.3},
	};




	
	fclose(fptr);
	printf("%d length \n", length );
	printf("sorting now\n");
	mergeSort_iter(test,0,9);
	printf("sorted !\n");
	for(int i=0; i<9; i++){
		printf("sorted rec cg : %f \n",test[i].cgpa );
	}
	return 0;
}









