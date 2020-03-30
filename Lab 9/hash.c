#include<stdio.h>
#include<string.h>
#include"helper.h"
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int hasher( char * string , int baseNumber , int tableSize ){
    int number=0;
    int sum = 0 ; 
    int i=0;
    while(string[i]!='\0'){
        sum +=  string[i];
        i++;
    }
    /*
    for( int i = 0 ; i < strlen(string) ; i++){
        sum += (int)string[i];
    }*/
    number = ( sum % baseNumber) % tableSize ;
    return number ;
}

int collision_counter( char **array , int length , int baseNumber , int tableSize ){
    
    int counter = 0 ;
    
    int * hashtable = (int *) malloc(sizeof(int) * tableSize);
    
    for(int i = 0 ; i < tableSize ; i++){
        hashtable[i] = -1 ;
    }

    for(int i =0; i < length ; i++ ){
        hashtable[hasher(*array++, baseNumber , tableSize)] += 1 ;
    } 

    for(int i =0 ; i <tableSize ; i++){
        if(hashtable[i] == -1){
            counter += 0;
        }
        else {
            counter+= hashtable[i];
        }
    }
    return counter;
}

void best_hasher(char ** array, int length, int * baseNumber, int * tableSize){
    int min = INT_MAX;
    *baseNumber = -1; 
    *tableSize = -1 ;
    int table_sizes [] = {5000, 50000,500000};
    int base_numbers[][6] = {
        {5051, 5443 , 8447, 5000011, 5000081, 5000101},
        {50551, 50707, 80929, 50000329, 50002861, 50003873},
        {755569, 765041, 768107, 500001529, 500002961, 500009927},
    } ;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<6; j++){
            int test_ts = table_sizes[i];
            int test_base= base_numbers[i][j];
            printf("Test_ts = %d --- Test_base= %d \n", test_ts, test_base );
            int collision=collision_counter(array, length, test_base, test_ts);
            printf("%d\n", collision);
            if(collision< min){
                *baseNumber = test_base;
                *tableSize = test_ts;
                min = collision;
            }
        }
    }
    return;
}

char** parser(char* filename, int* length){
    FILE *fp = fopen(filename,"r");
    int wordcount = 1000;
    int count =0;
    *length=0;
    char **array = malloc(wordcount* sizeof(char *));
    while(!feof(fp)){
        int validity = 0;
        char sentence[100];
        fscanf(fp, "%s" , sentence);
        char c;
        int i =0;
        c=sentence[i];
        while(c!='\0'){
            if(!((c>='a'&&c<='z')||(c>='A' && c<='Z'))){
                validity =1;
                break;
            }
            c =sentence[++i];

        }
        if(validity){
            continue;
        }
        array[count] = (char*)malloc(sizeof(char)*(strlen(sentence)+1));
        strcpy(array[count],sentence);
        if(++count>=wordcount-1){
            wordcount*=2;
            array=realloc(array, wordcount*sizeof(char*));

        }

    }
    fclose(fp);
    *length = count;
    return array;
}












