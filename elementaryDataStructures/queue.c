#include "queue.h"
#include <stdlib.h>

static int nextSlotIdx(Queue * const queue, int idx) {
    if (idx == queue -> cap - 1)
        return 0;
    else
        return idx + 1;
}

Queue * queueInit(int cap) {
    Queue * newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue -> head = -1;    // indicating no element in queue
    newQueue -> tail = 0;
    newQueue -> cap = cap;
    newQueue -> data = (int *) malloc(sizeof(int) * cap);

    return newQueue;
}

void queueDelete(Queue * queue) {
    free(queue -> data);
    free(queue);

    return;
}

void enqueue(Queue * queue, int val) {
    if (queue -> head == queue -> tail) {
        exit(1);    // queue is full, do nothing
    }
    if (queue -> head == -1) {
        queue -> head = 0;
    }
    (queue -> data)[queue -> tail] = val;
    queue -> tail = nextSlotIdx(queue, queue -> tail);

    return;
}

int dequeue(Queue * queue) {
    if (queue -> head == -1)
        exit(1);
    int retval = (queue -> data)[queue -> head];
    queue -> head = nextSlotIdx(queue, queue -> head);
    if (queue -> head == queue -> tail) {
        // queue is empty after dequeue, reset head and tail
        queue -> head = -1;
        queue -> tail = 0;
    }
    return retval;
}
