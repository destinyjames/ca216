NAME
  clr - clear the terminal screen

SYNOPSIS
  clr

DESCRIPTION
  clr clears the your terminal screen.

OPTIONS
  No options needed.

--------------------------------------------------------------------
NAME
  cd - changes directory to specified directory.

SYNOPSIS
  cd [DIRECTORY]

DESCRIPTION
  cd changes directory to specified. If no argument is present, cd
  reports the current working directory

OPTIONS
  ..
    changes to parent directory.

-------------------------------------------------------------------
NAME
  dir - list contents of directory

SYNOPSIS
  dir [OPTION] ...

DESCRIPTION
  dir lists all the files and sub-directories in your current working directory.

OPTIONS
  -a lists all entries including hidden files.

  -l uses a long listing format.

  -s sorts by file size, largest to smallest.

-------------------------------------------------------------------
NAME
  echo - displays a line of text followed by a new line

SYNOPSIS
  echo [STRING]

DESCRIPTION
  echo prints the STRING to] standard output

OPTIONS
  No options needed


NAME
  help - displays the manual for the shell script

SYNOPSIS
  help [COMMAND]

DESCRIPTION
  prints out argument if there isnt an argumend given it will print a new line

OPTIONS
  No options needed.


NAME
  pause - pause operation of the shell until <ENTER> is pressed

SYNOPSIS
  pause

DESCRIPTION
  pause puts the current operation of the shell on hold until user presses <ENTER>

OPTIONS
  No options needed.


NAME
  quit - quit the shell

SYNOPSIS
  quit

DESCRIPTION
  quit

OPTIONS
  No options needed.
-------------------------------------------------
NAME
  nano

SYNOPSIS
  nano [FILENAME]

DESCRIPTION
  nano is the small and friendly core editor of this shell program.

OPTIONS
  No options needed.
--------------------------------------------------
NAME
  environ - prints all or part of environment

SYNOPSIS
  environ

DESCRIPTION
  environ prints the values of the specified environment variable(s).

OPTIONS
  No options needed.

-------------------------------------------------------------------------

-- Internal Commands --
The Internal commands are custom to this shell. All eternal commands can also be run in my shell.
-------------------------------------------------------------------------

-----I/O Redirection -----
(I havent used this in my shell but i will explain what it is and how i would hve used it in my shell.)

programname arg1 arg2 < inputfile > outputfile

The characters used are <, >, and >>.

> - the programs output is put into an output file. It will create an output file if it doesnt exist.

>> - The program output is put into the end of the output file. If the output fiile does not exist it is created.
"Redirection simply means capturing output from a file, command, program,
script, or even code block within a script" [1]

--- Processes/Background + Foreground Execution ---

A process is like running a program. Each process has a unique PID it is used to identify the process.[2]

Child processes are always created after the parent process, parent processes will usually create child processes to run programs.

Background execution is another process run without waiting for a child to terminate and the procces usually runs without outputting anything.[3]

Foreground execution is a process that runs , waits for its children to terminate it will then show the output.[4]

-----References -----
[1] Anderson and P. Anderson, The UNIX [superscript] TM C shell field guide. Englewood Cliffs, NJ: Prentice Hall, 1986.

[2] A. SILBERSCHATZ, OPERATING SYSTEM CONCEPTS, 10th ed. [S.l.]: JOHN WILEY, 2021.

[3] RUBAIAT HOSSAIN, How to Run Linux Commands in the Background, 2021.

[4] Luke Reynolds, Understanding forgrround and background processes in Linux, 2021.
-------------------------------------------------------------------------------------------------------------------------
Student Name: Genesis Uwumangbe
Student Number: 20459666
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious. 
I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
