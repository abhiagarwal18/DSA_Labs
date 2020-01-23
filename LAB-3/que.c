#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"que.h"

Queue newQ(){
    Queue q;
    q.head=NULL;
    q.tail=NULL;
    return q;
}

bool isEmptyQ(Queue q){
    if((q.head==NULL)&&(q.tail==NULL)){
        return true;
    }
    return false;
}

int lengthQ(Queue q){
    if(isEmptyQ(q)==true){
        return 0;
    }
    else{
        int len=0;
        struct node * temp = (struct node *)malloc(sizeof(struct node ));
        temp = q.head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
}

Queue delQ(Queue q){
    if(isEmptyQ(q)==false){
        if(lengthQ(q)==1){
            struct node * temp = (struct node *)malloc(sizeof(struct node ));
            temp = q.head;
            q.head =NULL;
            q.tail =NULL;
            free(temp);
            return q;
        }
        else if(lengthQ(q)>1){
            struct node * temp = (struct node *)malloc(sizeof(struct node ));
            temp = q.head;
            q.head= temp->next;
            free(temp);
            return q;
        }
    }
    else {
        printf("Underflow ! \n");
        return q;
    }
}

int frontQ(Queue q ){
    if(isEmptyQ(q)==false){
        struct node * temp = (struct node *)malloc(sizeof(struct node ));
        temp = q.head;
        return temp->element;
    }
    else{
        printf("Empty queue\n");
        return -1;
    }
}

Queue addQ(Queue q, int e){
    if(isEmptyQ(q)==false){
        struct node * temp = (struct node *)malloc(sizeof(struct node ));
        temp->element=e;
        temp->next=NULL;
        q.tail->next=temp;
        q.tail=temp;
        return q;
    }
    else{
        //creates a new element
        struct node * temp = (struct node *)malloc(sizeof(struct node ));
        temp->element=e;
        temp->next=NULL;
        q.head =temp;
        q.tail=temp;
        return q;
    }
}



