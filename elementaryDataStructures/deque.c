#include <stdlib.h>
#include "deque.h"

static int getNextIdx(Deque * deq, int idx) {
    if (idx == deq -> cap - 1)
        return 0;
    else
        return idx + 1;
}

static int getPrevIdx(Deque * deq, int idx) {
    if (idx == 0)
        return deq -> cap - 1;
    else
        return idx - 1;
}

static inline void resetDeque(Deque * deq) {
    deq -> l = -1;
    deq -> r = -1;
}

static inline void firstEnqueue(Deque * deq, int val) {
    deq -> l = 0;
    deq -> r = 0;
    (deq-> data)[0] = val;
}

Deque * getDeque(unsigned cap) {
    Deque * newDeq = (Deque *) malloc(sizeof(Deque));
    newDeq -> data = (int *) malloc(sizeof(int) * cap);
    newDeq -> cap = cap;
    newDeq -> l = -1;
    newDeq -> r = -1;

    return newDeq;
}

void  delDeque(Deque * deque) {
    free(deque -> data);
    free(deque);

    return;
}

void enqueueLeft(Deque * deque, int val) {
    if (deque -> l == -1)
    {
        firstEnqueue(deque, val);
    }
    else {
        int nextLeft = getPrevIdx(deque, deque -> l);
        if (nextLeft == deque -> r)
            exit(1);
        else {
            deque -> l = nextLeft;
            (deque -> data)[deque -> l] = val;
        }
    }

    return;
}

int dequeueLeft(Deque * deque) {
    if (deque -> l == -1)
        exit(1);    // deq is already full
    int retval = (deque -> data)[deque -> l];
    if (deque -> l == deque -> r) {
        resetDeque(deque);
    }
    else {
        deque -> l = getNextIdx(deque, deque -> l);
    }

    return retval;
}

void enqueueRight(Deque * deque, int val) {
    if (deque -> r == -1)
    {
        firstEnqueue(deque, val);
    }
    else {
        int nextRight = getNextIdx(deque, deque -> r);
        if (nextRight == deque -> l)
            exit(1);    // deq is already full
        else {
            deque -> r = nextRight;
            (deque -> data)[deque -> r] = val;
        }
    }

    return;
}

int dequeueRight(Deque * deque) {
    if (deque -> r == -1)
        exit(1);    // empty deq, can't dequeue
    int retval = (deque -> data)[deque -> r];
    if (deque -> l == deque -> r) {
        resetDeque(deque);
    }
    else {
        deque -> r = getPrevIdx(deque, deque -> r);
    }

    return retval;
}
