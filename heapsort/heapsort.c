#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/* public function declaration section */
void maxHeapifyIterative(int*, int, int);
void unittest(void);

/* private functions declaration section */
static inline int left(int);
static inline int right(int);
static inline int parent(int);

int main(void)
{
    unittest();
    exit(0);
}

void maxHeapifyIterative(int * array, int n, int idx)
{
    int i = idx;
    int leafStartIdx = n / 2;
    int largest;
    while (i < leafStartIdx)
    {
        int l = left(i), r = right(i);
        if (l < n && array[l] > array[i])
            largest = l;
        else
            largest = i;
        if (r < n && array[r] > array[largest])
            largest = r;
        
        if (i != largest)
        {
            int temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            i = largest;
        }
    }
}

static inline int left(int idx)
{
    return idx * 2 + 1;
}

static inline int right(int idx)
{
    return idx * 2 + 2;
}

static inline int parent(int idx)
{
    return (idx - 1) / 2;
}

void unittest(void)
{
    int testsample[7] = {3,5,7,2,8,9,6};
    int resultsample[7] = {3,5,9,2,8,7,6};

    maxHeapifyIterative(testsample, 7, 2);
    assert(memcmp(testsample, resultsample, sizeof(testsample)) == 0);
}
