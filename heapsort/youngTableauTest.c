#include "youngTableau.h"
#include <stdlib.h>
#include <assert.h>

void unittest(void) {
    YoungTableau * young = youngTableauCtor(4, 4);
    for (int i = 0; i < young -> rowSize; i++) {
        for (int j = 0; j < young -> colSize; j++) {
            youngTableauInsert(young, i * j);
        }
    }
    assert(!existInTableau(young, 5));
    assert(!existInTableau(young, 1));
    assert(0 == extractMin(young));
    assert(0 == extractMin(young));
    assert(0 == extractMin(young));
    assert(0 == extractMin(young));
    assert(0 == extractMin(young));
    assert(0 == extractMin(young));
    assert(0 == extractMin(young));
    assert(1 == extractMin(young));
    assert(2 == extractMin(young));
    assert(2 == extractMin(young));
    assert(3 == extractMin(young));
    assert(3 == extractMin(young));
    assert(4 == extractMin(young));
    assert(6 == extractMin(young));
    assert(6 == extractMin(young));
    assert(9 == extractMin(young));

    return;
}

int main(void) {
    unittest();

    return 0;
}
