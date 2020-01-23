#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#include"multiq.h"

MultiQ loadData(FILE * f){

    char c;
    MultiQ mq = createMQ(10);
    int line_count =0 ;
    for (c = getc(f); c != EOF; c = getc(f))
        if (c == '\n') // Increment count if this character is newline
            line_count = line_count + 1;

    char line[100];
    for(int count =0; count<line_count;count++)
    {
        if(fgets(line,sizeof(line),f)==NULL)
            break;
        else{
            Task temp;
            temp.tid=0;
            temp.p=0;
            temp.tid=atoi(strtok(line,','));
            temp.p=atoi(strtok(NULL,','));
            mq=addMQ(mq, temp);
        }
    }
    return mq;

}

MultiQ testDel(int num,MultiQ mq){
    for(int i=0; i<num; i++){
        mq= delNextMQ(mq);
        printf("iteration %d of deletion\n", i+1);
    }
    return mq;
}

int main(int argc, char const *argv[])
{
    FILE *fileptr =fopen(argv[1],"r");
    if(fileptr == NULL){
        fprintf(stderr, "cant open this file \n");
        exit(1);
    }
    MultiQ mq = createMQ(10);
    mq = loadData(fileptr);
    mq = testDel(3,mq);
    fclose(fileptr);

    return 0;
}


