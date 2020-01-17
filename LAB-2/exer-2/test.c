#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fptr1 ;
    FILE * fptr2;
    fptr1= fopen(argv[1],"r");
    if (fptr1 == NULL)
   {
      printf("Press any key to exit...\n");
      exit(0);
   }


    printf("flag 1\n");
    fptr2= fopen(argv[2],"w");
    if (fptr2 == NULL)
   {
      fclose(fptr1);
      printf("Press any key to exit...\n");
      exit(0);
   }
   char ch;
    printf("flag 2\n");
    while ((ch = fgetc(fptr1)) != EOF)
      fputc(ch, fptr2);

   printf("File copied successfully.\n");
    fclose(fptr1);
    fclose(fptr2);

    return 0;
}