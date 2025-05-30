#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

void users(){
    struct passwd *pw;
    while ((pw = getpwent()) != NULL)
	fprintf(stdout, "Пользователь %s: %s\n", pw->pw_name, pw->pw_dir);
    endpwent();
}
