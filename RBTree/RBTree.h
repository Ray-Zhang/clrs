enum RedOrBlack { RED, BLACK };

typedef struct _Node {
    int key;
    enum RedOrBlack color;
    struct _Node * parent;
    struct _Node * left;
    struct _Node * right;
} Node;

typedef struct {
    Node * root;
    Node * nil;    // sentinel node to mark "NO MORE NODE"
} RBTree;

RBTree * makeRBTree();

void rbInsert(RBTree * rbt, Node * z);

void rbDelete(RBTree * rbt, Node * z);
