#include "RBTree.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static void showRBTree(RBTree * rbt, Node * subroot) {
    if (subroot != rbt -> nil) {
        showRBTree(rbt, subroot -> left);
        printf("%d: %s\n", subroot -> key, subroot -> color == BLACK ? "BLACK" : "RED");
        showRBTree(rbt, subroot -> right);
    }
    return;
}

void unittest(void) {
    RBTree * rbt = makeRBTree();
    for (int i = 0; i < 8; i++) {
        Node * newnode = (Node *) malloc(sizeof(Node));
        newnode -> key = i;
        newnode -> parent = rbt -> nil;
        newnode -> left = rbt -> nil;
        newnode -> right = rbt -> nil;
        rbInsert(rbt, newnode);
    }
    showRBTree(rbt, rbt -> root);
}

int main(void) {
    unittest();
}
