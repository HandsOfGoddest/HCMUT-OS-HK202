#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	
	if (q->size == MAX_QUEUE_SIZE) // Check if queue is full or not
		return;
	q->proc[q->size++] = proc;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	 
	if (q->size == 0) // first check if ready queue is empty
		return NULL;
	
	// If ready queue is not null
	int highest_pri_index = 0; // Highest Priority Proc's Index
	int pWalker; // Break point checking where is the highest priority proc's index
	for (pWalker = 1; pWalker < q->size; pWalker++)
	{
		if (q->proc[pWalker]->priority > 
				      q->proc[highest_pri_index]->priority)
		{
			highest_pri_index = pWalker;
		}
	}
	struct pcb_t *deq_proc = q->proc[highest_pri_index]; // dequeue proc
	// shifting queue back
	for (pWalker = highest_pri_index + 1; pWalker < q->size; pWalker++)
	{
		q->proc[pWalker - 1] = q->proc[pWalker];
	}
	q->size--;

	return deq_proc;
}

