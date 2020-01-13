/***********file:   Ops.c *********/


//HAVE MODIFIED THE QUESTION FILES FOR SOLUTION
#include <stdio.h>
#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;


//already implemented
SeqList createlist()
{
    SeqList sl;
    sl.head = nextfreeloc++;
    sl.size = 0;
    st[sl.head].next = -1;
    return (sl);
}

//already implemented
void printJob(Job j)
{
    printf("JOB ID = %d, Priority = %d, Execution time = %d, Arrival time = %d \n", j.id, j.pri, j.et, j.at);
}

//already implemented
int inputJobs(JobList list)
{
    int i;
    int size;

    printf("\n Size of list(no. of jobs) :");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("\nEnter job ID");
        scanf("%d", &list[i].id);
        printf("Enter Priority (from 0 - 2)");
        scanf("%d", &list[i].pri);
        printf("\n Execution Time");
        scanf("%d", &list[i].et);
        printf("\n Arrival Time");
        scanf("%d", &list[i].at);
    }
    return size;
}


//self implemented
SeqList insert(Job j, SeqList sl)
{
    int i, temp;
    for (i = sl.head; st[i].next != -1; i = st[i].next)
    {
        if (compare(st[st[i].next].ele, j) == GREATER)
            break;
    }
    temp = nextfreeloc++;
    st[temp].next = st[i].next;
    st[temp].ele = j;
    st[i].next = temp;
    sl.size++;
    return sl;
}

//self implemented
void insertelements(JobList list, int size, SeqList s[])
{
    for (int i = 2; i >= 0; i--)
    {
        for (int k = 0; k < size; k++)
        {
            Job j = list[k];
            if (j.pri == i)
            {
                s[i] = insert(j, s[i]);
            }
        }
    }
}

void copy_sorted_ele(SeqList s[], JobList ele)
{
    int len = 0;
    for (int i = 2; i >= 0; i--)//copying Priority-wise
    {
        Location k = st[s[i].head];
        while (k.next != -1)
        {
            k = st[k.next];
            ele[len++] = k.ele;
        }
    }
}


void printlist(SeqList sl)
{
    printf("size of list = %d\n", sl.size);
    for (int i = st[sl.head].next; i != -1; i = st[i].next)
    {
        printJob(st[i].ele);
    }
}

//self implemented
void printJobList(JobList list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printJob(list[i]);
    }
}


void sortJobList(JobList list, int size)
{
    SeqList seq[3];
    seq[0] = createlist();
    seq[1] = createlist();
    seq[2] = createlist();
    insertelements(list, size, seq);
    /* used for checking :-
    printlist(seq[0]);
    printlist(seq[1]);
    printlist(seq[2]);
    */
    copy_sorted_ele(seq, list);
}
