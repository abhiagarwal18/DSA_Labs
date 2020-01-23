#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"multiq.h"


MultiQ createMQ(int num){
    MultiQ mq;
    mq.num_of_queue=num;
    mq.q = malloc(num * sizeof(Queue));
    for(int i=0;i<num; i++){
        mq.q[i]= newQ();
    }
    return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
    mq.q[t.p-1]=addQ(mq.q[t.p-1], t.tid);
    return mq;
}

Task nextMQ(MultiQ mq){
    for(int i=mq.num_of_queue-1; i>=0; i--){
        if(isEmptyQ(mq.q[i])== false){
            Task temp ;
            temp.p = i+1;
            temp.tid = frontQ(mq.q[i]);
            return temp;
        }
    }
    Task *temp  = (Task *)malloc(sizeof(Task));
    return *temp;
    }

MultiQ delNextMQ(MultiQ mq){
    for(int i=mq.num_of_queue-1; i>=0;i--){
        if(isEmptyQ(mq.q[i])==false){
            mq.q[i]=delQ(mq.q[i]);
            return mq;
        }
    }
    return mq;
}


bool isEmptyMQ(MultiQ mq){
    for(int i= 0; i<mq.num_of_queue;i++){
        if(isEmptyQ(mq.q[i])==false){
            printf("Queue of priority %d is not empty\n", i+1);
            return false;
        }

    }
    return true;
}



int sizeMQ(MultiQ mq){
    int len = 0;
    for (int i = 0; i < mq.num_of_queue; ++i)
    {
        len = len + lengthQ(mq.q[i]);
    }
    return len;
}

int sizeMQbyPriority(MultiQ mq, Priority p){
    return lengthQ(mq.q[p-1]);
}


Queue getQueueFromMQ(MultiQ mq, Priority p){
    return mq.q[p-1];
}

