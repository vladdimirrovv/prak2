#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "log.h"
#include "errors.h"
#include "help.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;
    char *errors_path = NULL;
    struct option long_option[] = {
    	{"users", no_argument, NULL, 'u'},
	    {"processes", no_argument, NULL, 'p'},
	    {"help", no_argument, NULL, 'h'},
	    {"log", required_argument, NULL, 'l'},
	    {"errors", required_argument, NULL, 'e' },
	    {0, 0, 0, 0}    
    };

    while ((opt = getopt_long(argc, argv, "upe:l:h", long_option, NULL)) != -1) {
        switch (opt) {
            case 'u':
                print_users();
                break;
            case 'p':
                print_processes();
                break;
            case 'l':
                log_path = optarg;
                set_log_file(log_path);
                break;
            case 'e':
                errors_path = optarg;
                set_errors_file(errors_path);
                break;
            case 'h':
                print_help();
                return 0;
            default:
                fprintf(stderr, "Неизвестный аргумент: %c\n", opt);
                return 1;
        }
    }

    return 0;
}