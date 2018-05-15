#include <stdlib.h>
#include "quicksort.h"
#include <stdio.h>

void quicksort(int * ary, const int start, const int end) {
    if (start < end) {
        int pivot = hoarePartition(ary, start, end);
        quicksort(ary, start, pivot);
        quicksort(ary, pivot + 1, end);
    }
}

static int hoarePartition(int * ary, const int start, const int end) {
    int x = ary[start];
    int j = end + 1;
    int i = start - 1;
    while (1) {
        do {
            --j;
        } while (ary[j] > x);
        do {
            ++i;
        } while (ary[i] < x);
        if (i < j) {
            int temp = ary[i];
            ary[i] = ary[j];
            ary[j] = temp;
        }
        else {
            return j;
        }
    }
}

static IdxPair * partitionDot(int * ary, const int start, const int end) {
    int i, k;
    i = k = start - 1;
    int j = start;
    int x = ary[end];
    IdxPair * retval = (IdxPair *)malloc(sizeof(IdxPair));
    for (; j < end; j++) {
        if (ary[j] < x) {
            // exchange ary[j], ary[i+1] and ary[k+1]
            i++;k++;
            int temp = ary[i];
            ary[i] = ary[j];
            ary[j] = ary[k];
            ary[k] = temp;
        }
        else if (ary[j] == x) {
            k++;
            ary[j] = ary[k];
            ary[k] = x;
        }
    }
    ary[end] = ary[k + 1];
    ary[k + 1] = x;
    
    retval -> q = i + 1;
    retval -> t = k;
    return retval;
}

void quicksortDot(int * ary, const int start, const int end) {
    if (start < end) {
        IdxPair * pair = partitionDot(ary, start, end);
        quicksortDot(ary, start, pair -> q - 1);
        quicksortDot(ary, pair -> t + 1, end);
    }
}

void tailRecursiveQuicksort(int * ary, const int start, const int end) {
    int p = start, r = end;
    while (p < r) {
        int pivot = hoarePartition(ary, p, r);
        if (pivot <= p + (p - r) / 2) {
            tailRecursiveQuicksort(ary, p, pivot - 1);
            p = pivot + 1;
        }
        else {
            tailRecursiveQuicksort(ary, pivot + 1, r);
            r = pivot - 1;
        }
    }
}
