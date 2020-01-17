#include<stdio.h>
#include <stdlib.h>
#include"linkedlist.h"


int main(int argc, char * argv[]){
    FILE *fileptr = fopen(argv[1],"r");
    struct linkedList * head= (struct linkedList *) malloc(sizeof(struct linkedList));
    head->first=NULL;
    while(!feof(fileptr)){
        int temp;
        fscanf(fileptr, "%d",
            &temp);
        insertFirst(head, temp);

    }
    fclose(fileptr);
    printlist(head);
    while(head->count!=0){
        struct node * temp = (struct node *) malloc(sizeof(struct node));
        temp = deleteFirst(head);
    }
}