/***************** Include Libraries **************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/***************** Function to clear the terminal screen ******************************************************/
void clr() {                  
    system("clear");
}

/***************** Function to display an opening shell prompt ************************************************/
void start_prompt() {         
    clr();
    printf("\t\t\t*******************************\n"
           "\t\t\t***   WELCOME TO MY SHELL   ***\n"
           "\t\t\t***                         ***\n"
           "\t\t\t*** For a list of built in  ***\n"
           "\t\t\t*** command prompts please  ***\n"
           "\t\t\t*** input 'help'            ***\n"
           "\t\t\t***                         ***\n"
           "\t\t\t***        THANK YOU        ***\n"
           "\t\t\t*******************************\n\n\n");
}

/***************** Function to print the current directory ****************************************************/
//reference: https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program
void pwd() {                  
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s", cwd);
}

/***************** Function to list contents of current directory *********************************************/
void dir() {
    system("ls -al");
}

/***************** Function to change directory into user provided one, ***************************************/
/***************** if it does not exist, print the current directory instead **********************************/
void cd(char** args) {
    if (args[1] != NULL) {
        chdir(args[1]);
    }
    else {
        pwd(); 
    }
}

/***************** Function to list the current environment variables *****************************************/
//reference: https://stackoverflow.com/questions/2085302/printing-all-environment-variables-in-c-c
void environmen() { 
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n",environ[i]);
    }
}

/***************** Function to print user input on command line onto the terminal *****************************/
void echo(char** args) {
    int i = 1;
    printf("\n");
    while (args[i] != NULL) {
        printf("%s ", args[i]);
        i++;
    }
    printf("\n\n");
}

/***************** Function to display a list of built in shell commands and their purpose to the user ********/
void help() {
    printf("\nList of built in shell commands:\n"
    ">clr: clear terminal screen\n"
    ">dir: list contents of current directory\n"
    ">environ: list all environment strings\n"
    ">cd: change directory\n"
    ">echo: print argument onto terminal\n"
    ">pause: pause the shell until 'ENTER' is pressed\n"
    ">quit: exit the shell\n\n"
    );
}

/***************** Function to pause the program until the enter key is pressed *******************************/
void halt() {
    char ch;
    while (1) {
        scanf("%c", &ch);
        if (ch == '\n') {
            break;
        }
    }
}

/***************** Function to check for an & character and determine if process runs in background or not ****/
int background(int argc, char** argv) {
    if (argc > 1 && !strcmp(argv[1],"&")) {
        return 0;
    }
    return 1;
}

/***************** Function to read input from a text file and output the necessary commands ******************/
void batchfile(char** argv) {

    FILE *f = fopen(argv[1], "r");
    char line[50];
    while(fgets(line, sizeof(line), f) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        char * token = strtok(line, " ");

        while(token != NULL) {
            if (!strcmp(token,"cd")) {
                token = strtok(NULL, " ");
                chdir(token);
                continue;
            }
            if (!strcmp(token,"echo")) {
                token = strtok(NULL, " ");
                printf("%s\n", token);
                continue;
            }
            else {
                break;
            }
        }

        if (!strcmp(line,"clr")) {
            clr();
            continue;
        }
        if (!strcmp(line,"dir")) {
            dir();
            continue;
        }
        if (!strcmp(line,"environ")) {
            environmen();
            continue;
        }
    }
    fclose(f);
}
