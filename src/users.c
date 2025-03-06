#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>
#include "users.h"
#include <unistd.h>

void print_users() {
    struct passwd *pw;
    setpwent();
    while ((pw = getpwent()) != NULL) {
        printf("%s: %s\n", pw->pw_name, pw->pw_dir);
    }
    endpwent();
}