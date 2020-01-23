#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"que.h"


int main(int argc, char * argv[]){
   // printf("flag 1\n");
    Queue q = newQ();
    FILE *fileptr = fopen(argv[1],"r");
    while(!feof(fileptr)){
        int temp;
        fscanf(fileptr, "%d",
            &temp);
        q=addQ(q, temp);

    }
    fclose(fileptr);
    int l = lengthQ(q);
    printf("size of the queue : %d\n", l );
    int temp = 0;
    temp =frontQ(q);
    printf("first element before deletion : %d  \n", temp);
    q = delQ(q);
    int frontele=frontQ(q);
    printf("first element after one deletion : %d \n",frontele );
    return 0;
}
