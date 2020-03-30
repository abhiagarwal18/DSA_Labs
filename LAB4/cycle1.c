#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"cycle.h"
//hare and tortoise algorithm

bool testCyclic(Ls l)
{
    struct node* hare = (struct node *)myalloc(sizeof(struct node));
    struct node* tort = (struct node *)myalloc(sizeof (struct node));
    hare->next = l.first;
    tort->next = l.first;
    if((l.count == 0)||(l.count==1)||(l.count== 2)){
    return false;
    }
    else
    {
        while((hare->next!=NULL)&&(tort!=NULL)&&(hare!=NULL)){
            hare= hare->next->next;
            tort= tort->next;
            if(hare == tort){
                return true;
            }
        }
        return false;
    }
}