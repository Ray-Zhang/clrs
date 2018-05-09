#include "heap.h"
#include <stdlib.h>

void init(Heap * hp, int sz)
{
    hp -> data = (struct ListNode**)malloc(sizeof(struct ListNode*) * sz);
    hp -> size;

    return;
}

void del(Heap * hp)
{
    free(hp -> data);

    return;
}

void listNodeMinHeapify(Heap * minHeap, int idx)
{
    int leftIdx, rightIdx, minIdx;
    if (idx < 0 || idx >= minHeap -> size)
        return;
    else
    {
        leftIdx = LEFT(idx);
        rightIdx = RIGHT(idx);
        if (leftIdx < (minHeap -> size) && ((minHeap -> data)[leftIdx] -> val) < ((minHeap -> data)[idx] -> val))
        {
            minIdx = leftIdx;
        }
        else
        {
            minIdx = idx;
        }
        if (rightIdx < (minHeap -> size) && ((minHeap -> data)[rightIdx] -> val) < ((minHeap -> data)[minIdx] -> val))
        {
            minIdx = rightIdx;
        }
        if (idx != minIdx)
        {
            struct ListNode * temp = (minHeap -> data)[idx];
            (minHeap -> data)[idx] = (minHeap -> data)[minIdx];
            (minHeap -> data)[minIdx] = temp;
            listNodeMinHeapify(minHeap, minIdx);
        }
    }
}

int listNodeHeapExtractMin(Heap * minHeap)
{
    int retVal;
    // exit program when heap is empty
    if (minHeap -> size <= 0)
        exit(1);
    // when heap root has more than one element,
    // return first element and remove it from the list
    // also need to Heapify the root
    else if ((minHeap -> data)[0] ->next)
    {
        retVal = (minHeap -> data)[0] -> val;
        (minHeap -> data)[0] = (minHeap -> data)[0] -> next;
        listNodeMinHeapify(minHeap, 0);
    }
    // when heap root only has one element,
    // return the element, also remove the root node
    else
    {
        retVal = (minHeap -> data)[0] -> val;
        if (minHeap -> size > 1)
        {
            (minHeap -> data)[0] = (minHeap -> data)[(minHeap -> size) - 1];
            (minHeap -> size)--;
            listNodeMinHeapify(minHeap, 0);
        }
        else
        {
            (minHeap -> size)--;
        }
    }
    return retVal;
}
