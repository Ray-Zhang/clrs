#include "BST.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void unittest(void) {
    Node * bstRoot = NULL;
    for (int i = 0; i < 3; i++) {
        insertBST(&bstRoot, i);
    }
    inorderWalk(bstRoot);
    inorderWalkNonrecursive(bstRoot);
}

int main(void) {
    unittest();

    return 0;
}
