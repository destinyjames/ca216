// Author: Colin Ekedigwe
// Student number: 20403046
// I adhere to the DCU rules and regulations in regards to plagiarism on work handed up and understand this

// Round Robin explanation https://www.edureka.co/blog/round-robin-scheduling-in-c/
// https://www.tutorialandexample.com/round-robin-scheduling-in-c
// http://web.cse.ohio-state.edu/~soundarajan.1/courses/3430/silberschatz8thedition.pdf

#include <stdio.h>
#include <stdlib.h>

// Calling functions from our other files where parts of our code will run
#include "schedulers.h"
#include "task.h"
#include "list.h"
#include "cpu.h"

// Node head is empty pointing to nothing
// Initialing our Task id to 0
struct node *head = NULL;
int uniqueTasktid = 0;

// We are adding tasks to our list of variables here
void add(char* name, int priority, int burst)
{
    Task *task = malloc(sizeof(Task)); // Allocating a source of memory for each task + making an array
    (*task).name = name; // Each task is given a name
    (*task).tid = uniqueTasktid++; // Each task is given arrival time
    (*task).priority = priority; // Each task gets priority
    (*task).burst = burst; // Each task gets a burst
    insert(&head, task); //Inserting function to add node to the list
}

void schedule()
{
    struct node *tmp;

    // Assigning a quantum variable as 10, 10 quantum = 10ms
    int quantum = 10;
    // While loop, we keeping going until the head is empty, once its empty we stop
    while(head != NULL)
    {
    	// A tmp variable is now the head
        tmp = head;
        // Loop thorugh the nodes until the tmp is empty
        // https://www.geeksforgeeks.org/program-round-robin-scheduling-set-1/
        for(struct node *tmp=head; tmp != NULL; tmp=tmp->next)
        {
        	// If the burst time is greater than 0 the process can continue
            if(tmp->task->burst >0)
            {
            	// If the burst time is greater than 0 and gretaer than or equal to the quantum(10) we can proceed
                if(tmp->task->burst > 0 && tmp->task->burst <= quantum)
                {
                	//Run the program
                    run(tmp->task, tmp->task->burst);
                    // Processes are terminated
                    delete(&head, tmp->task);
                }
                else
                {
                	// Run the program
                    run(tmp->task, quantum);
                    // Remove the quantum from the burst time
                    tmp->task->burst -= quantum;
                }

            }
            else
            {
            	// Processes are terminated
                delete(&head, tmp->task);
            }
        }
    }
}
