#include "d-ary.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static void showHeapData(DAryHeap * dAryHeap) {
    for (int i = 0; i < (dAryHeap -> size); i++) {
        printf("%d ", (dAryHeap -> data)[i]);
    }
    printf("\n");

    return;
}

DAryHeap * dAryHeapInit(int capacity, unsigned d) {
    DAryHeap * newHeap = (DAryHeap *)malloc(sizeof(DAryHeap));
    newHeap -> size = 0;    // initially includes 0 node in heap
    newHeap -> capacity = capacity;
    newHeap -> d = d;
    newHeap -> data = (int *)malloc(sizeof(int) * capacity);
    return newHeap;
}

void dAryHeapDel(DAryHeap * dAryHeap) {
    free(dAryHeap -> data);
    free(dAryHeap);
}

int extractMax(DAryHeap * dAryHeap) {
    if (dAryHeap -> size < 1)
        exit(1);
    int retval = (dAryHeap -> data)[0];
    (dAryHeap -> data)[0] = (dAryHeap -> data)[(dAryHeap -> size) - 1];
    (dAryHeap -> size)--;
    heapify(dAryHeap, 0);

    return retval;
}

void insert(DAryHeap * dAryHeap, int val) {
    if (dAryHeap -> size >= dAryHeap -> capacity)
        exit(1);
    (dAryHeap -> data)[dAryHeap -> size] = INT_MIN;
    (dAryHeap -> size)++;
    increaseK(dAryHeap, (dAryHeap -> size) - 1, val);
    showHeapData(dAryHeap);

    return;
}

int max(DAryHeap * dAryHeap) {
    if (dAryHeap -> size < 1)
        exit(1);
    return (dAryHeap -> data)[0];
}

void heapify(DAryHeap * dAryHeap, int idx) {
    if (idx >= (dAryHeap -> size) - 1)
        exit(1);
    if ( idx * (dAryHeap -> d) + 1 >= (dAryHeap -> size) - 1)    // do nothing for leaf node
        return;
    else {
        int largest = idx;
        for (int i = 1; i <= dAryHeap -> d; i++) {
            int child = idx * 3 + i;
            if (child >= dAryHeap -> size)
                break;
            else {
                if ((dAryHeap -> data)[child] > (dAryHeap -> data)[largest])
                    largest = child;
            }
        }
        if (idx != largest) {
            // exchange values at idx and largest
            int temp = (dAryHeap -> data)[idx];
            (dAryHeap -> data)[idx] = (dAryHeap -> data)[largest];
            (dAryHeap -> data)[largest] = temp;
            heapify(dAryHeap, largest);
        }
    }
}

void increaseK(DAryHeap * dAryHeap, int idx, int val) {
    if (idx >= dAryHeap -> size)
        exit(1);
    int * heapData = dAryHeap -> data;
    if ( val < heapData[idx] )
        return;
    heapData[idx] = val;
    int current = idx;
    int parent;
    while (current) {
        parent = (current - 1) / (dAryHeap -> d);
        if (heapData[current] <= heapData[parent]) {
            break;
        }
        else {
            int temp = heapData[current];
            heapData[current] = heapData[parent];
            heapData[parent] = temp;
            current = parent;
        }
    }

    return;
}
