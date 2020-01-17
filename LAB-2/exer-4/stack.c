#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


void push(struct linkedList * head, int ele){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->element= ele;
    temp->next= head->first;
    head->first=temp;
    head->count++;
}

struct node * pop(struct linkedList * head ){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = head->first;
    head->first=temp->next;
    head->count--;
    return temp;
}
