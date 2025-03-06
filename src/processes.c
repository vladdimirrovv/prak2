#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include "processes.h"
#include <unistd.h>

void print_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            printf("PID: %s\n", entry->d_name);
        }
    }

    closedir(dir);
}