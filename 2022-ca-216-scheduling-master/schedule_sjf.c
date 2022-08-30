#include <stdio.h>
#include <stdlib.h>
#include "schedulers.h"
#include "task.h"
#include "list.h"
#include "cpu.h"

struct node *head = NULL;
int uniquetid = 0;  




 
//This function is used to make the link list be in accending order because it was in 
// i used this link to help me reverse a list https://www.geeksforgeeks.org/reverse-a-linked-list/
void rList(struct node** head) 

{
    struct node *free = *head;    // assigned pointers and variables
    struct node* before = NULL;
    struct node* next;
    while(free != NULL)
    {
        next = (*free).next;  
        (*free).next = before;   
        before = free;
        free = next;
    }
    *head = before;   
}

/*All the code bellow is what i use to schedule using sjf i assigned variables
then i created a burnt list to store burst time. i then used malloc to make an array
to store the wait time and i also did the same for thr turn around time*/
void schedule()
{
	int burst[200]; //make burstTime a list to collect burst time variables
    int calc = 0; //this variable will be used to calculate


    // I used this link to help me understand how to use malloc with linked lists
    // https://stackoverflow.com/questions/29522264/correct-way-to-use-malloc-and-free-with-linked-lists
    int *wTime = (int*)malloc(sizeof(int));
    int *TAT = (int*)malloc(sizeof(int));
    float avrwaittime;
    float avrTAT;

    
    rList(&head); // i called the rList function. i used to arrange the list 



    struct node *original = head; //i assigned the head node to the struct i assigned it as original as i am usuing the original head
    struct node *Change = NULL; //i named the node change as it will change through the nodes
    Task *temporary;
    
    while(original != NULL) //this while loop will run untill original is empty
    {  
        Change = (*original).next;
                  
        while(Change != NULL) //this while loop will run untill change is empty
        {
            if(original->task->burst > Change->task->burst) //if swap node is less than the main node
            {  
                temporary = (*original).task; //i assigned a variable to the original task
                (*original).task = (*Change).task; //Now the original task will become the change task
                (*Change).task = temporary; //the change node becomes the temporary
            }  
            Change = (*Change).next; //i assigned the change node to a new one
        }  
        original = (*original).next; // allocated it to the next original node
    }   

    for(struct node *free=head; free != NULL; free=(*free).next)
    {
        run((*free).task, (*free).task->burst);
    }
    
    for(struct node *free=head; free != NULL; free=(*free).next) //this loop will loop through nodes
    {
        burst[calc++] = free->task->burst; //here i am adding the burst time to the burst list
    }

    //assigning the turnaround time and wait time
     wTime[0] = 0;
    TAT[0] = burst[0];

    for(int i = 1; i < calc; i++) //This calculation is used to find the waiting time
    {
        wTime[i] = wTime[i-1] + burst[i-1];
    }
    for (int i = 1; i < calc; i++) //This calculation is used to find the turn around time
    {
        TAT[i] = wTime[i] + burst[i]; 
    }
    for(int i = 0; i < calc; i++) //calculating the averages for waiting time and turn around time
    {
        avrTAT = avrTAT + TAT[i];
        avrwaittime = avrwaittime + wTime[i];
    }
    // dividing the average wait time and the average turn aound time.
    avrwaittime = avrwaittime/calc;
    avrTAT = avrTAT/calc;
    printf("\nAverage waiting time = %.2f ms\n", avrwaittime);
    printf("Average turnaround time = %.2f ms  \n", avrTAT);
    for(struct node *free=head; free != NULL; free=(*free).next)//iterate through nodes to delete process
    {
        delete(&head, (*free).task);// this function is used to terminate the processes
    }
}

// this function is used to add up the vtask variables
void add(char* name, int priority, int burst) 
{
    // i used the struct that was already provides for us in task.h
    Task *task = malloc(sizeof(Task)); // created an array and allocating a source of memory for each task
    (*task).name = name; // each task is given a name
    (*task).tid = uniquetid++; // Each task is given a unique id
    (*task).priority = priority; // Each task gets a priority
    (*task).burst = burst; // each task gets a burst

    insert(&head, task); // this funtion is used to add the node to a list
}


// References

// i used this link to help me sort linked list 
// https://www.javatpoint.com/program-to-sort-the-elements-of-the-singly-linked-list

// i used these websites to help me calculate the avrage wait time and average turnaround time
// i also used this website to help with some parts of my code
// https://www.edureka.co/blog/sjf-scheduling-in-c/
// https://www.geeksforgeeks.org/difference-between-turn-around-time-tat-and-waiting-time-wt-in-cpu-scheduling/
/*-------------------------------------------------------------------------------------
Author: Genesis Uwumangbe
Student number: 20459666

I understand that the University regards breaches of academic integrity and plagiarism as grave and serious. 
I have read and understood the DCU Academic Integrity and Plagiarism Policy. 
I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
 */
