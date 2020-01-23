#include<stdio.h>
#include<stdbool.h>
struct node
{
    int element;
    struct node * next;
};

typedef struct queue{
    struct node * head;
    struct node * tail;
}Queue;

Queue newQ();
bool isEmptyQ(Queue q);
Queue addQ(Queue q, int e);
int front(Queue q);
Queue delQ(Queue q);


int lengthQ(Queue q);