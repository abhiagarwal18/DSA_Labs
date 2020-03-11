#include<stdlib.h>
#include<stdio.h>
#include"helper.h"
#include<sys/time.h>

char * stackvar;


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

int main(){

	FILE * fptr;
//	fptr = fopen("1024.txt", "r");
fptr = fopen("2048", "r");
	//fptr = fopen("4096", "r");
	//fptr = fopen("10240.txt", "r");

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

	Element data_copy[length];
	for(int i=0; i<length;i++){
		data_copy[i]= data[i];
	}
/*
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

*/	fclose(fptr);
	printf("%d length \n", length );
	printf("sorting now\n");

	struct timeval t1, t2,t3,t4;
	double elapsedTime_1;
	double elapsedTime_2;
	gettimeofday(&t1,NULL);
	mergeSort_iter(data,0,length);
	gettimeofday(&t2,NULL);
	printf("sorted using iterative merge sort !\n");\
	gettimeofday(&t3, NULL);
	mergeSort_rec(data_copy,0,length);
	gettimeofday(&t4,NULL);
	printf("sorted copy of the array using recursive merge sort ! \n");
	elapsedTime_1 = (t2.tv_sec - t1.tv_sec) * 1000.0; 
	elapsedTime_1 += (t2.tv_usec - t1.tv_usec) / 1000.0;
	elapsedTime_2 = (t4.tv_sec - t3.tv_sec) * 1000.0; 
	elapsedTime_2 += (t4.tv_usec - t3.tv_usec) / 1000.0;
	char trial;
	char *space2 = &trial;
	printf("rec merge sort : time = %lf ms space =%ld bytes \n",elapsedTime_2, space2-stackvar );
	printf("iter merge sort : time=%lf ms \n " , elapsedTime_1);

	/*
	for(int i=0; i<1024; i++){
		printf("sorted rec cg : %f \n",data[i].cgpa );
	}*/
	return 0;
}









