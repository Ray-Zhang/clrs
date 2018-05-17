#include "mergeableHeap.h"
#include <stdlib.h>
#include <stdio.h>

Node * makeHeap() {
    Node * retval = (Node *)malloc(sizeof(Node));
    if (retval == NULL)
        exit(1);
    else {
        retval -> prev = NULL;
        retval -> next = NULL;
        // this is the head of the list, we don't set its value and never access its value
        return retval;
    }
}

void insert(Node * mh_p, int val) {
    Node * prev = mh_p;
    Node * current = mh_p -> next;
    while (current) {
        if (val < current-> val)
            break;
        else {
            prev = current;
            current = current -> next;
        }
    }
    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        exit(1);
    newNode -> prev = prev;
    newNode -> val = val;
    newNode -> next = current;
    prev -> next = newNode;

    return;
}

int minimum(Node const * const mh_p) {
    if (mh_p -> next == NULL)
        exit(1);
    else
        return mh_p -> next -> val;
}

int extractMinimum(Node * mh_p) {
    if (mh_p -> next == NULL)
        exit(1);
    else {
        Node * minimum = mh_p -> next;
        int retval = mh_p -> next -> val;
        mh_p -> next = (mh_p -> next) -> next;
        free(minimum);
        return retval;
    }
}

Node * unionHeap(Node const * mha_p, Node const * mhb_p) {
    Node * retval = makeHeap();

    Node * current = mha_p -> next;
    while (current) {
        insert(retval, current -> val);
        current = current -> next;
    }
    current = mhb_p -> next;
    while (current) {
        insert(retval, current -> val);
        current = current -> next;
    }

    return retval;
}
