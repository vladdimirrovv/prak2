#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void errors(const char* lfp){
    FILE* fp;
    if ((fp = fopen(lfp, "w")) == NULL){
	fprintf(stderr, "can't open error file for writing\n"); 
	exit(1);
    }
    if (dup2(fileno(fp), 2) == -1)
        fprintf(stderr, "can't redirect output\n");
    fclose(fp);
}
