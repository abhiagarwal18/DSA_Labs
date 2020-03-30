#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



struct node{
    int ele;
    struct node * next;
};

typedef struct linkedlist{
    struct node * first;
    int count;
}Ls;


void myfree(void * ptr);
void * myalloc(long unsigned int size);
Ls  push(Ls l, int ele);
Ls createList(int N);
void createCycle(Ls * l);
bool testCyclic(Ls);
