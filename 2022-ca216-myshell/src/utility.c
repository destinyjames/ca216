
/*
Student Name: Genesis Uwumangbe
Student Number: 20459666
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious. 
I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
*/

// function prototyples

void cd(char *argv[]);
void pause_shell();
int external_commands(char **args);
void echo(char *argv[]);


// this function is printed at the start of my shell
void intro() 
{  
    printf("-------------------------------------------"); 
    printf("\n**** Welcome to Destinys Shell  ****"); 
   
    printf("\n\nName:  Genesis Uwumangbe");
    printf("\nStudent Number: 20459666");
    printf("\n\n-------------------------------------------"); 
    char* username = getenv("USER"); 
    printf("\n ***** USER is: @%s *****", username); 
    printf("\nUse \"help\" to access the shell's my manual.");
    printf("\nUse \"quit\" to exit the shell.");

    printf("\n"); 
    sleep(1); 
}