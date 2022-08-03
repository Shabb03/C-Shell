/***************** Include Libraries *****************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

int main (int argc, char ** argv)
{
    int bg = background(argc, argv);
    
    if (argc > 1 && bg) {
        batchfile(argv);
        exit(0);
    }
    
    char buf[MAX_BUFFER];
    char * args[MAX_ARGS];
    char ** arg;
    char * prompt = "====>";
    start_prompt();

    while (!feof(stdin)) {
        pwd();
        fputs (prompt, stdout); 

        if (fgets (buf, MAX_BUFFER, stdin )) { 
            arg = args;     
            *arg++ = strtok(buf,SEPARATORS); 

            while ((*arg++ = strtok(NULL,SEPARATORS))) {}

                if (args[0]) {  

/*****************  Check for built in commands *****************/
                    
                    if (!strcmp(args[0],"clr")) {
                        clr();
                        continue;
                    }
                    if (!strcmp(args[0],"dir")) {
                        dir();
                        continue;
                    }
                    if (!strcmp(args[0],"environ")) {
                        environmen();
                        continue;
                    }
                    if (!strcmp(args[0],"cd")) {
                        cd(args);
                        continue;
                    }
                    if (!strcmp(args[0],"echo")) {
                        echo(args);
                        continue;
                    }
                    if (!strcmp(args[0],"help")) {
                        help();
                        continue;
                    }
                    if (!strcmp(args[0],"pause")) {
                        halt();
                        continue;
                    }
                    if (!strcmp(args[0],"quit")) {
                        exit(0);
                    }

/*****************  Else pass command onto OS using fork and exec *****************/

                    pid_t pid;
                    pid = fork();
                    if (pid < 0) {
                        printf("Shell fork failed. Exiting Shell");
                        exit(0);                        
                    }
                    else if (pid==0) {
                        execv(args[0], args);
                    }
                    else {
                        wait(NULL);
                    }
                }
        }
    }
    return 0;
}
