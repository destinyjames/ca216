/*
Student Name: Genesis Uwumangbe
Student Number: 20459666
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious. 
I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.


The main concept of this shell:
- Runs a while loop intill you call quit

*/



//includes
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <dirent.h>
#include "myshell.h"
#include "utility.c"
#define BUFFER 1024    // max line buffer
#define MAX_ARGS 64    // max # args
#define SEPARATORS " \t\n" // token sparators

extern char **environ;


//used 
/*
some of my code is from the lab work i then expanded on it with my own code
 https://loop.dcu.ie/mod/book/view.php?id=1796411&chapterid=377036
author:  Ian G Graham
*/
int main (int argc, char ** argv)
{
    char buf[BUFFER];  // line buffer
    char * args[MAX_ARGS];   // pointers to arg strings
    char ** arg;    // working pointer thru args
    char * prompt = "==> " ;     // shell prompt
    intro(); // this prints the welcome to my shell funtion
    
/* keep reading input until "quit" command or eof of redirected input */

    while (!feof(stdin)) {

        /* get command line from input */

        fputs (prompt, stdout); // write prompt
        if (fgets (buf, BUFFER, stdin )) { // read a line
            /* tokenize the input into args array */

            arg = args;
            *arg++ = strtok(buf,SEPARATORS); // tokenize input
            while ((*arg++ = strtok(NULL,SEPARATORS)));
            // last entry will be NULL if (args[0]) {                     

            if(args[0] == NULL)
            {
                continue;
            }
            /* check for internal/external command */
            else if (!strcmp(args[0],"clr")) { // "clear" command
                system("clear");
                continue;
            }

            else if (!strcmp(args[0],"quit"))   // "quit" command
                break;                          // break out of 'while' loop

            else if (!strcmp(args[0],"cd")) // "cd" command
            {
                cd(args); // call cd function
            }

            else if (!strcmp(args[0],"dir")) // "dir" command
            {
                if(args[1] == NULL)
                  system("ls -al");
                 else if(!strcmp(args[1], "-l"))
                    system("ls -l");
                else if (!strcmp(args[1], "-a"))
                    system("ls -a");
                else if (!strcmp(args[1], "-s"))
                    system("ls -S");
            }

            else if (!strcmp(args[0],"environ")) // "environ" command
            {
                 int i;
                 for (i = 0; environ[i] != NULL; i++)
                    printf("%s\n",environ[i]);
            }

            else if (!strcmp(args[0],"help")) // "help" command i used the more command to print out the manual and you would have to press enter to see the rest
                                              // if you want to find the manual for a specific internal command  i used sed to link to my readme file it will print the appropriate section
            {
                if(args[1] == NULL){
                    system("more ../manual/readme.md");

                }
                else if (!strcmp(args[1], "cd")){
                    system("sed -n -e 14,26p ../manual/readme.md");
                }
                else if (!strcmp(args[1], "clr")){
                    system("sed -n -e 1,11p ../manual/readme.md");
                }
                else if (!strcmp(args[1], "dir")){
                    system("sed -n -e 29,43p ../manual/readme.md");
                }
                else if (!strcmp(args[1], "environ")){
                    system("sed -n -e 110,119p ../manual/readme.md");
                }
                else if (!strcmp(args[1], "echo")){
                    system("sed -n -e 46,56p ../manual/readme.md");
                }
                else if (!strcmp(args[1], "help")){
                    system("sed -n -e 59,69p ../manual/readme.md");
                }
                else if (!strcmp(args[1], "pause")){
                    system("sed -n -e 72,80p ../manual/readme.md");
                }
                else if (!strcmp(args[1], "quit")){
                    system("sed -n -e 85,95p ../manual/readme.md");
                }


                continue;
            }
            
            else if (!strcmp(args[0],"pause")) // "pause" command
            {
                pause_shell(); // call pause_shell function
            }
            else
            {
                external_commands(args); // call external_commands function
            } 
        }
    }
return 0;
}
