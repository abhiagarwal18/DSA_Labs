#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void push(struct stack * head, int ele){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->element= ele;
    temp->next= head->first;
    head->first=temp;
    head->count++;
}

struct node * pop(struct stack * head ){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = head->first;
    head->first=temp->next;
    head->count--;
    return temp;
}

void printlist(struct stack * head){
    struct node * ptr = head -> first;
    printf("[ ");
    while(ptr != NULL ){
        printf("%d, ", ptr->element );
        ptr= ptr->next;
    }
    printf(" ] \n");
}