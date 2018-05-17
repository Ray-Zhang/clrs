#include "queue.h"
#include "deque.h"
#include "linkedlist.h"
#include <assert.h>

void unittest(void) {
    // queue test starts
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
    // queue test ends

    // deq test starts
    Deque * testDeq = getDeque(3);
    enqueueLeft(testDeq, 1);
    assert(dequeueRight(testDeq) == 1);
    enqueueRight(testDeq, 2);
    enqueueRight(testDeq, 3);
    enqueueLeft(testDeq, 1);
    assert(dequeueRight(testDeq) == 3);
    assert(dequeueRight(testDeq) == 2);
    assert(dequeueRight(testDeq) == 1);
    delDeque(testDeq);
    // deq test ends

    FreeList * testFl = createFreeList(3);
    assert(testFl -> free == 0);
    allocateObject(testFl);
    allocateObject(testFl);
    assert(testFl -> free == 2);
    freeObject(testFl, 0);
    freeObject(testFl, 1);
    assert(testFl -> free == 1);
    deleteFreeList(testFl);

    return;
}

int main(void) {
    unittest();

    return 0;
}
