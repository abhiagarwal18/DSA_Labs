#include<stdio.h>
#include<stdlib.h>
#include"cycle.h"

int totalspace=0;


void * myalloc(long unsigned int size)
{
    void * temp = malloc(size+ sizeof(long unsigned int));
    *((int*)temp)=size;
    temp = temp +sizeof(long unsigned int);
    totalspace = totalspace +  size+ sizeof(long unsigned int);
    return temp;
}

void myfree(void * ptr){
int size = *(int*)ptr;
free(ptr);
totalspace-=size;
}

Ls push(Ls l, int ele){
    struct node * temp= (struct node *)myalloc(sizeof(struct node ));
    temp->next = l.first;
    temp->ele=ele;
    l.first=temp;
    l.count++;
    return l;

}


Ls createList(int N){
    Ls l;
    l.first=NULL;
    l.count=0;
    for(int i =0; i<N; i++){
        int ele = rand();
        l= push(l, ele);
    }
    return l;
}


void createCycle(Ls  *l){
    if(l->count==0){
        printf("empty list \n");
        return;
    }
    int check = rand()%2;
    int r = rand()%(l->count);
    if(check){
        printf("creating cycle \n");
        struct node * temp1 = l->first;
        struct node * temp2 = l->first;
        while(temp1->next != NULL){
            temp1=temp1->next;
        }
        while(--r>=0){
            temp2 = temp2->next;
        }
        temp1->next = temp2;

    }
    else{
        printf("cycle not created \n ");

    }

    }











