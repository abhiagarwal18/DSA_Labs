#include<stdio.h>
#include <stdlib.h>
#include"stack.h"
/*#include"linkedlist.h"*/
int main(int argc, char * argv[]){
    FILE *fileptr = fopen(argv[1],"r");
    struct linkedList * head= (struct linkedList *) malloc(sizeof(struct linkedList));
    head->first=NULL;
    while(!feof(fileptr)){
        int temp;
        fscanf(fileptr, "%d",
            &temp);
        push(head, temp);

    }
    fclose(fileptr);
    printlist(head);//if want to use this then link linkedList.c too 
    printf("popping now \n");
    while(head->count!=0){
        struct node * temp = (struct node *) malloc(sizeof(struct node));
        temp = pop(head);
        printf("element popped : % d \n",temp->element );
    }
    printf("elements popped successfully ! \n");
    return 0;
}