#include "d-ary.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void unittest(void) {
    DAryHeap * testHeap = dAryHeapInit(10, 3);

    for (int i = 0; i < 10; i++) {
        insert(testHeap, i);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", (testHeap -> data)[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        assert((9 - i) == extractMax(testHeap));
    }

    dAryHeapDel(testHeap);
}

int main(void) {
    unittest();

    return 0;
}

