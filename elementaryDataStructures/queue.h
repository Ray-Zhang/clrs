typedef struct {
    unsigned head;
    unsigned tail;
    unsigned cap;
    int * data;
} Queue;

Queue * queueInit(int cap);

void queueDelete(Queue * queue);

void enqueue(Queue * queue, int val);

int dequeue(Queue * queue);
