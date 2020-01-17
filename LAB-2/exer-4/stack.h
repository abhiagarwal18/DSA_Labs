#include<stdio.h>
struct node
{
    int element;
    struct node* next;
};
struct stack
{
    struct node *first;
    int count;
};
void push( struct stack *head, int ele);
struct node * pop(struct stack * head);
void printlist(struct stack *head);
