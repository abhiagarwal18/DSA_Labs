/***********file:   main.c *********/
#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 int i; int size;
 JobList list;
 size = inputJobs(list);
 printf("Jobs are :\n");
 printJobList(list, size);
 sortJobList(list, size);
 printf("sorted jobs are :\n");
 printJobList(list, size);
 return 0;
}
 
