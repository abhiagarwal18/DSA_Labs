#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"cycle.h"
//link reversal algorithm

bool testCyclic(Ls l){
    struct node * last = (struct node * )malloc(sizeof(struct node));
    struct node * current = (struct node * )malloc(sizeof(struct node));
    struct node *  forward = (struct node * )malloc(sizeof(struct node));
    last=NULL;
    current = l.first;
    while(current){
        forward= current->next;
        current->next=last;
        last = current;
        current = forward;
}
 if(last == l.first){
                return true;
        }
    return false;
}
