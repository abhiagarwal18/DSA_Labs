#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

void insertFirst(struct linkedList *head, int ele){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->element=ele;
    temp->next=head->first;
    head->first=temp;
    head->count++;
    printf("inserted first element\n");
}

struct node * deleteFirst(struct linkedList * head){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp = head->first;
    head->first= temp->next;
    head->count--;
    printf("deleted first element\n");
    return temp;
}

void printlist(struct linkedList * head){
    printf("flag 2\n");
    struct node * ptr = head -> first;
    printf("flag 3\n");
    printf("[ ");
    while(ptr != NULL ){
        printf("%d, ", ptr->element );
        ptr= ptr->next;
    }
    printf(" ] \n");
}

int search(struct linkedList * head, int ele){
    struct node * temp = head->first;
    while(temp != NULL){
        if(temp->element == ele){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


struct node * deleteEle(struct linkedList * head, int ele){
   struct node * temp = head->first;
   while(temp != NULL){
    if(temp->next->element==ele){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr = temp->next;
        temp->next= ptr->next;
        head->count--;
        return ptr;
    }
    temp = temp->next;
   }
}