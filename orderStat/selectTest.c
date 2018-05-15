#include "select.h"
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void unittest(void) {
    int test[10] = {1,2,3,4,5,6,7,8,9,10};

    assert(randomizedSelect(test, 0, 9, 1) == 1);
    assert(randomizedSelect(test, 0, 9, 2) == 2);
    assert(randomizedSelect(test, 0, 9, 3) == 3);
    assert(randomizedSelect(test, 0, 9, 4) == 4);
    assert(randomizedSelect(test, 0, 9, 5) == 5);
    assert(randomizedSelect(test, 0, 9, 6) == 6);
    assert(randomizedSelect(test, 0, 9, 7) == 7);
    assert(randomizedSelect(test, 0, 9, 8) == 8);
    assert(randomizedSelect(test, 0, 9, 9) == 9);
    assert(randomizedSelect(test, 0, 9, 10) == 10);

    return;
}

int main(void) {
    srand(time(NULL));
    unittest();

    return 0;
}
