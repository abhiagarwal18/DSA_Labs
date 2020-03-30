#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"cycle.h"
#include<time.h>
#include<sys/time.h>
extern int totalspace;


int main()
{
    /* code */
    int N = 1000;
    Ls l;
    struct timeval t1,t2;
    double elapsedTime;
    srand(time(NULL));
    l = createList(N);
    createCycle(&l);
    printf("total space used : %d \n",totalspace );
    gettimeofday(&t1, NULL);
    bool result = testCyclic(l);
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Elapsed time for checking is %f \n",elapsedTime );
    printf("value of N : %d \n",N );
    return 0;
}
