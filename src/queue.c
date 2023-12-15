#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if(q->size < MAX_QUEUE_SIZE){
        	q->proc[q->size] = proc; 
        	q->size++;     
        }else{
        	return;
        }
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        struct pcb_t * res = NULL;
	if (!empty(q)){
		int pri = q->proc[0]->priority;
    		int idx = 0;
    		for (int i = 1; i < q->size; i++) {
        		if (q->proc[i]->priority < pri) {
            		pri = q->proc[i]->priority;
            		idx = i;
        		}
    		}
    		res = q->proc[idx];
    		for (int i = idx; i < q->size - 1; i++) {
        		q->proc[i] = q->proc[i + 1];
    		}
    		q->size--;
	}
	return res;
}

