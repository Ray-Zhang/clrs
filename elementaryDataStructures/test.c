#include "queue.h"
#include <assert.h>

void unittest(void) {
    // queue test
    Queue * testQ = queueInit(3);
    enqueue(testQ, 1);
    enqueue(testQ, 2);
    assert(dequeue(testQ) == 1);
    enqueue(testQ, 3);
    enqueue(testQ, 1);
    assert(dequeue(testQ) == 2);
    assert(dequeue(testQ) == 3);
    assert(dequeue(testQ) == 1);
    enqueue(testQ, 1);
    assert(dequeue(testQ) == 1);
    queueDelete(testQ);

    return;
}

int main(void) {
    unittest();

    return 0;
}
