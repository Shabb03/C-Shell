WELCOME:
Here is my project for a shell made in C, the commands are given in the manual below

MANUAL:

cd: cd [arg1] | Change to the directory provided in standard input by making that directory the current working directory.

clr: clr() | Clear the terminal screen.

dir: dir() | List the name of files in the current working directory in vertical order, including hidden files starting with '.'.

environ: environ() | List all environment strings, environment strings are variables stored in unique memory locations for the program to access.

echo: echo [arg1, arg2 ... argn] | Copy text from standard input and display it to standard output.

help: help() | Display a manual for users with the list of built in commands along with their function.

pause: pause() | Pause the program until ENTER key is pressed.

quit: quit() | Exit the shell.

Background Execution: ./shell & | Executes a program in the background by taking the '&' character.
Background vs Foreground, A program that is indepeneded of the user's interaction is run in the background where-as a program that requires or uses human interaction is run in the foreground.