#include<stdio.h>
#include<stdlib.h>
#include"helper.h"
#include<sys/time.h>



int main(int argc, char const * argv[]){

	//declaring file
	int len=0;
	int size=5;
	record * data = (record * )malloc(sizeof(record)*size);

	//reading the file
	FILE * fptr = fopen(argv[1],"r");
	if(fptr==NULL){
		printf("Error opening the file\n");
		exit(1);
	}
	const char * ftemplate = "%[^ ] %llu \n";
	record temp;
	while(!feof(fptr)){
		fscanf(fptr, ftemplate, temp.name, &temp.empid);
		fgetc(fptr);
		if(len+1 > size){
			size=size*2;
			data = (record *)realloc(data, sizeof(record)*size);
		}

			data[len] = temp;
			len++;
			//printf("record number %d read \n", length);
	
	} 
	fclose(fptr);
	printf("length = %d \n", len);
	printRecords(data, len);
	printf("sorting\n");
	//quicksortIter(data, 0,len-1,3);
	//insertionsortIter(data, len);
	//printRecords(data,len);
	//insertionsortIter(data, len);
	//mySort(data, len,3);
	
	int estimated_cutoff =estimate_cutoff(data,len,0.001); 
	printf("estimated cutoff = %d\n", estimated_cutoff);
	printf("writing the sorted list in the output file ");
	FILE *f = fopen(argv[2], "wb");
	for(int n=0;n<len;n++) {
        fprintf(f,"%s %lld\n",data[n].name, data[n].empid);
     }
	fclose(f);


}