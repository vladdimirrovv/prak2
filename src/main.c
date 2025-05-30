#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "error.h"
#include "log.h"
#include "help.h"
#include <string.h>

int main(int argc, char* argv[]){
    int opt;
    int uflag = 0; 
    int pflag = 0;
    int hflag = 0;
    char* log_f; char* e_f;
    
    struct option long_option[] = {
	{"users", no_argument, NULL, 'u'},
	{"processes", no_argument, NULL, 'p'},
	{"help", no_argument, NULL, 'h'},
	{"log", required_argument, NULL, 'l'},
	{"errors", required_argument, NULL, 'e' },
	{0, 0, 0, 0}
    };
    
    for (int i = 1; i < argc; i++){
        if ((strcmp(argv[i], "-e")) == 0 || strcmp(argv[i], "--errors") == 0) errors(argv[i+1]);
    }
    
    while ((opt = getopt_long(argc, argv, "upl:e:h", long_option, NULL)) != -1){
	switch (opt){
	    case 'u': uflag = 1; break;
	    case 'p': pflag = 1; break;
	    case 'h': hflag = 1; break;
	    case 'l': log_f = optarg; break;
	    case 'e': e_f = optarg; break;
	    default:
		fprintf(stderr, "Unknown option. Use -h for help\n");
		exit(1);
	}
    }

    if (log_f) logging(log_f);
    if (uflag == 1) users();
    if (pflag == 1) processes();
    if (hflag == 1) help();
    return 0;
}
