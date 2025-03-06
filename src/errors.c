#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include <unistd.h>

static FILE *errors_file = NULL;

void set_errors_file(const char *path) {
    if (errors_file) {
        fclose(errors_file);
    }
    errors_file = fopen(path, "w");
    if (!errors_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    dup2(fileno(errors_file), 2);
}

