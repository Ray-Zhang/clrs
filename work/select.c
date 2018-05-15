#include <stdio.h>
#include "select.h"
#include <string.h>

static int partition(int * const ary, const int start, const int end) {
    if (start >= end)
        return start;

    int r = getRandIdx(end - start + 1);
    exchangeElements(ary, start + r, end);
    int pivot = end;
    int i = start - 1, j = start;
    for (; j < end; j++) {
        if (ary[j] < ary[pivot]) {
            exchangeElements(ary, i + 1, j);
            i++;
        }
    }
    exchangeElements(ary, i + 1, pivot);

    return i + 1;
}

static inline int getRandIdx(int base) {
    return rand() % base;
}

static void exchangeElements(int * const ary, const int idx1, const int idx2) {
    int temp = ary[idx1];
    ary[idx1] = ary[idx2];
    ary[idx2] = temp;

    return;
}

int randomizedSelect(const int * const ary, int start, int end, int ith) {
    if (start >= end)
        return ary[start];

    int retVal;
    int * aryCopy = (int *)malloc(sizeof(int) * (end - start + 1));
    memcpy(aryCopy, ary, sizeof(int) * (end - start + 1));
    while (1) {
        int q = partition(aryCopy, start, end);
        if (q + 1 == ith) {
            retVal = aryCopy[q];
            free(aryCopy);
            break;
        }
        else if (q + 1 < ith) {
            start = q + 1;
        }
        else {
            end = q - 1;
        }
    }
    return retVal;
}
