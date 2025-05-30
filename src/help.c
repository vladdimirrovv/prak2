#include <stdio.h>
#include <unistd.h>

void help(){
    printf("Usage [options]\n");
    printf("-u, --users		show list of users and their home directories\n");
    printf("-p, --processes	        show list of running processes\n");
    printf("-l PATH, --log PATH	redirect output to the file\n");
    printf("-e PATH, --errors PATH	redirect error output to the file\n");
    printf("-h, --help		show this help message\n");
}
