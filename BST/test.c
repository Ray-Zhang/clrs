#include "BST.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void unittest(void) {
    Node * bstRoot = NULL;
    for (int i = 0; i < 10; i += 2) {
        insertBST(&bstRoot, i);
    }
    for (int i = 1; i < 10; i += 2) {
        insertBST(&bstRoot, i);
    }
    //inorderWalk(bstRoot);
    inorderWalkNonrecursive(bstRoot);
    assert(searchBST(bstRoot, 9) -> key == 9);
    assert(searchBST(bstRoot, 10) == NULL);
    assert(minimumBST(bstRoot) -> key == 0);
    assert(maximumBST(bstRoot) -> key == 9);
    assert(successor(minimumBST(bstRoot)) -> key == 1);
    assert(predecessor(maximumBST(bstRoot)) -> key == 8);
    deleteNodeBST(bstRoot, 7);
    assert(searchBST(bstRoot, 9) -> key == 9);
    assert(searchBST(bstRoot, 7) == NULL);
    inorderWalkNonrecursive(bstRoot);
}

int main(void) {
    unittest();

    return 0;
}
