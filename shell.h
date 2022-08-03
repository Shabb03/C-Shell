#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"
#define SEPARATORSF "\t\n"
extern char **environ;

/***************** Function to clear the terminal screen ******************************************************/
void clr();

/***************** Function to display an opening shell prompt ************************************************/
void start_prompt();

/***************** Function to print the current directory ****************************************************/
void pwd();

/***************** Function to list contents of current directory *********************************************/
void dir();

/***************** Function to change directory into user provided one, ***************************************/
/***************** if it does not exist, print the current directory instead **********************************/
void cd(char** args);

/***************** Function to list the current environment variables *****************************************/
void environmen();

/***************** Function to print user input on command line onto the terminal *****************************/
void echo(char** args);

/***************** Function to display a list of built in shell commands and their purpose to the user ********/
void help();

/***************** Function to pause the program until the enter key is pressed *******************************/
void halt();

/***************** Function to check for an & character and determine if process runs in background or not ****/
int background(int argc, char** argv);

/***************** Function to read input from a text file and output the necessary commands ******************/
void batchfile(char** argv);