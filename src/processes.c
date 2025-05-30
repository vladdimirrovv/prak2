#include <stdio.h>
#include <unistd.h>

void processes(){
    FILE* fp = popen("ps -eo pid,command --sort=pid", "r");
    if (fp == NULL) fprintf(stderr, "Error of opening file");
    char buf[100];
    while(fgets(buf, 100, fp) != NULL) fprintf(stdout, "%s", buf);
    pclose(fp);
}
