#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void logging(const char* lfp){
    FILE* fp;
    fp = fopen(lfp, "w");
    if ((fp = fopen(lfp, "w")) == NULL){
	fprintf(stderr, "can't open log file for writing\n"); 
	exit(1);
    }
    if (dup2(fileno(fp), 1) == -1)
        fprintf(stderr, "can't redirect output\n");
    fclose(fp);
}
