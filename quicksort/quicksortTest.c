#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "quicksort.h"

void unittest(void) {
    int input[12] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    int sorted[12] = {2, 4, 5, 6, 7, 8, 9, 11, 12, 13, 19, 21};
    quicksort(input, 0, 11);
    assert(!memcmp(input, sorted, 12));

    int recTest[12] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    tailRecursiveQuicksort(recTest, 0, 11);
    assert(!memcmp(recTest, sorted, 12));

    int equals[6] = {1, 1, 2, 1, 2, 3};
    int equalsSorted[6] = {1, 1, 1, 2, 2, 3};
    quicksortDot(equals, 0, 5);
    assert(!memcmp(equals, equalsSorted, 6));

    return;
}

int main(void) {
    unittest();

    return 0;
}
