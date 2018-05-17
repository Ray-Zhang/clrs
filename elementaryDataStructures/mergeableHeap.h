typedef struct _Node {
    struct _Node * prev;
    int val;
    struct _Node * next;
} Node;

Node * makeHeap();

void insert(Node * mh_p, int val);

int minimum(Node const * const mh_p);

int extractMinimum(Node * mh_p);

Node * unionHeap(Node const * mha_p, Node const * mhb_p);
