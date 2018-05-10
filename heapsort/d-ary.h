typedef struct {
    int capacity;
    unsigned size;
    int * data;
    unsigned d;    // determine how many children each node has at most
} DAryHeap;

DAryHeap * dAryHeapInit(int sz, unsigned _d);

void dAryHeapDel(DAryHeap * dAryHeap);

void insert(DAryHeap * dAryHeap, int val);

int max(DAryHeap * dAryHeap);

int extractMax(DAryHeap * dAryHeap);

void heapify(DAryHeap * dAryHeap, int idx);

void increaseK(DAryHeap * dAryHeap, int idx, int val);
