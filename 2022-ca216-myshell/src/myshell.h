/*
Student Name: Genesis
Student Number: 20459666
In submitting this project, I declare that the project material, 
which I now submit, is my own work. Any assistance received by way of borrowing from the work of others has been cited 
and acknowledged within the work. I make this declaration in the knowledge that a breach of the rules pertaining to project submission 
may carry serious consequences.
*/




#include <limits.h>
#include <string.h>




void echo(char *argv[])
{
    for (int i = 1; argv[i]; i++)
        printf("%s ", argv[i]);
    printf("\n");
}

//function for "cd" command
void cd(char *argv[])
{
    char dir[200];
    getcwd(dir, sizeof(dir));

    if(argv[1] == NULL)
    {
        printf("%s\n", dir); //print current directory
    }
    else
    {
        chdir(argv[1]);
        getcwd(dir, sizeof(dir));
        setenv("PWD", dir, 1);
    }
}


//function for "pause" 
void pause_shell()
{
    printf("To continue, press enter.\n");
    while(getchar() != '\n');
}




// external commands
int external_commands(char **args) // implemented some code from https://brennan.io/2015/01/16/write-a-shell-in-c/
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
        perror("myshell");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("myshell");
  } else {
    // Parent process
    do {
        wpid = waitpid(pid, &status, WUNTRACED);
    } 
    while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
