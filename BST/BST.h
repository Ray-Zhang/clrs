typedef struct _Node {
    struct _Node * p;
    struct _Node * left_c;
    struct _Node * right_c;
    int key;
} Node;

void insertBST(Node ** root, int key);

void inorderWalk(Node * root);

void inorderWalkNonrecursive(Node * root);
