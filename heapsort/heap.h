#define LEFT(x) (2*x+1)
#define RIGHT(x) (2*x+2)
#define PARENT(x) ((x-1)/2)

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    struct ListNode ** data;
    int size;
} Heap;

void init(Heap *, int);

void del(Heap *);

void listNodeMinHeapify(Heap *, int);

int listNodeHeapExtractMin(Heap *);
