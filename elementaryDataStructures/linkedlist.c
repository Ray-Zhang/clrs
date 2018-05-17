#include "linkedlist.h"
#include <stdlib.h>

FreeList * createFreeList(int cap) {
    FreeList * newFreelist = (FreeList *) malloc(sizeof(FreeList));
    newFreelist -> objects = (Object *) malloc(sizeof(Object) * cap);
    newFreelist -> free = 0;
    for (int i = 0; i < cap; i++) {
        if (i == 0) {    // first object
            (newFreelist -> objects[i]).prev = -1;
            (newFreelist -> objects[i]).next = i + 1;
        }
        else if (i == cap - 1) {    // last object
            (newFreelist -> objects[i]).prev = i - 1;
            (newFreelist -> objects[i]).next = -1;
        }
        else {
            (newFreelist -> objects[i]).prev = i - 1;
            (newFreelist -> objects[i]).next = i + 1;
        }
    }

    return newFreelist;
}

void deleteFreeList(FreeList * fl) {
    free(fl -> objects);
    free(fl);

    return;
}

Object * allocateObject(FreeList * freelist) {
    Object * retval;
    if ((freelist -> objects)[freelist -> free].next == -1)
        exit(1);
    else {
        retval = (freelist -> objects) + (freelist -> free);
        freelist -> free = (freelist -> objects)[freelist -> free].next;
        return retval;
    }
}

void freeObject(FreeList * freelist, int idx) {
    (freelist -> objects)[idx].next = freelist -> free;
    freelist -> free = idx;

    return;
}
