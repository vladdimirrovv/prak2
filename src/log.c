#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include <unistd.h>
static FILE *log_file = NULL;

void set_log_file(const char *path) {
    if (log_file) {
        fclose(log_file);
    }
    log_file = fopen(path, "w");
    if (!log_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    dup2(fileno(log_file), 1);
}
