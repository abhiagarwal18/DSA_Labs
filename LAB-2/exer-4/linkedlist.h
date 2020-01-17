#include<stdio.h>
struct node
{
    int element;
    struct node* next;
};
struct linkedList
{
    struct node *first;
    int count;
};
void insertFirst(struct linkedList *head, int ele);
struct node *deleteFirst(struct linkedList *head);
void printlist(struct linkedList *head);
int search(struct linkedList *head, int ele);
struct node * deleteEle(struct linkedList * head, int ele);
