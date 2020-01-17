#include <stdio.h>
#include<string.h>

int is_int(char* s){
	for(int i=0;i<strlen(s); i++){

	if(s[i] < '0' ||  s[i] > '9')
	{
		return 0;}
	}
	return 1;
	}

int main(int argc, char *argv[]) {
      for(int i=0;i<argc;i++){
      if(is_int(argv[i])==1){
      printf("\n %d ", atoi(argv[i]));
      }
      else{
      printf("\n %s ", argv[i]);
}}}
