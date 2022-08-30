// Author: Colin Ekedigwe
// Student number: 20403046
// I adhere to the DCU rules and regulations in regards to plagiarism on work handed up and understand this

// FCFS scheduling explanation https://www.javatpoint.com/os-fcfs-scheduling
// https://www.studytonight.com/operating-system/first-come-first-serve
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
    Task *task = malloc(sizeof(Task)); // Allocating a source of memory for each task
    (*task).name = name; // Each task is given a name
    (*task).tid = uniqueTasktid++; // Each task is given arrival time
    (*task).priority = priority; // Each task gets priority
    (*task).burst = burst; // Each task gets a burst
    insert(&head, task); //Inserting function to add node to the list
}

// Created a reverse function which will reverse the order of the linked list so its in ascending order
// https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
// https://www.techiedelight.com/reverse-linked-list-part-1-iterative-solution/
void reverseList(struct node** head)
{
    struct node* tmp = *head;
    struct node* next;
    struct node* previous = NULL;
    while(tmp != NULL) //looping through every node
    {
        next = tmp->next;
        tmp->next = previous;
        previous = tmp;
        tmp = next;
    }
    // head pointer is pointing to the new front
    *head = previous;
}

// Reverse linked list, run and calculate times for average waiting time and turn around time.
void schedule()
{
    // Assigning variables
    int num = 0;
    int total = 0;
    struct node *tmp=head; // Assigning linked list node and set pointer tmp to head as a temporary head
    int *waitingTime = (int*)malloc(sizeof(int)); // Array of wait times
    int *turnAroundTime = (int*)malloc(sizeof(int));// Array of turnAround
    float awt; // Average wait time
    float atat; // Average turn around time

	// Reverse linked list function
    reverseList(&head);

	// Going through the linked list until tmp head is empty
    for(struct node *tmp=head; tmp != NULL; tmp=tmp->next)
    {
        run(tmp->task, tmp->task->burst); // running task
        total++; // total number of process is calculated
    }

	// Making burst time into a list
    int burstTime[100]; // make burst time a list to collect burst time variables

    for(struct node *tmp=head; tmp != NULL; tmp=tmp->next) // loop through nodes
    {
        burstTime[num++] = tmp->task->burst; // Adding burst times to list
    }

    // Times for first process
    // Turn Around time = Exit time – Arrival time
    // Waiting time = Turn Around time – Burst time
    // https://www.thecrazyprogrammer.com/2014/11/c-cpp-program-for-first-come-first-served-fcfs.html
    waitingTime[0] = 0;
    turnAroundTime[0] = burstTime[0];

    // Waiting time calculation
    for(int i = 1; i < num; i++)
    {
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
    }
    // Turn around time calculation
    for(int i = 0; i < num; i++)
    {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }
    // AWT and ATAT calculation
    for(int i = 0; i < num; i++)
    {
        awt = awt + waitingTime[i];
        atat = atat + turnAroundTime[i];
    }

    // Averages calculated
    awt = awt/num;
    atat = atat/num;

    printf("\n-----------------TIMES---------------------\n\nAverage Waiting Time = %.2f ms\nAverage Turnaround Time = %.2f ms\n", awt, atat);
    // Processes are terminated
    delete(&head, tmp->task);
}


