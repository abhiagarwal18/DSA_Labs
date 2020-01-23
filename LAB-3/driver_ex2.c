#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"multiq.h"



int main(int argc, char * argv[]){
   // printf("flag 1\n");
    Queue q = newQ();
    MultiQ mq = createMQ(10);
    Task t1;
    t1.p=2;
    t1.tid=32;
    Task t2;
    t2.p=2;
    t2.tid=322;
    Task t3;
    t3.p=1;
    t3.tid=2;
    Task t4;
    t4.p=5;
    t4.tid=3232;

    mq = addMQ(mq, t1);
    mq = addMQ(mq, t2);
    mq = addMQ(mq, t3);
    mq = addMQ(mq, t4);
    printf("%d\n", sizeMQbyPriority(mq, 2) );


    return 0;
}
