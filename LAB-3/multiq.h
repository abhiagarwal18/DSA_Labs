#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"que.h"

typedef int Priority;
typedef int TaskID;

typedef struct multq
{
    Queue * q;
    int num_of_queue;
}MultiQ;

typedef struct task{
    TaskID tid;
    Priority p;
}Task;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
bool isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ mq, Priority p);

