typedef struct {
    int l;
    int r;
    int * data;
    unsigned cap;
} Deque;

Deque * getDeque(unsigned cap);

void delDeque(Deque * deque);

void enqueueLeft(Deque * deque, int val);

int dequeueLeft(Deque * deque);

void enqueueRight(Deque * deque, int val);

int dequeueRight(Deque * deque);
