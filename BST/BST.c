#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

#define LEFT 0
#define RIGHT 1

static Node * makeNode(Node * parent, int key) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    if (!newNode)
        exit(1);
    newNode -> p = parent;
    newNode -> left_c = NULL;
    newNode -> right_c = NULL;
    newNode -> key = key;

    return newNode;
}

void insertBST(Node ** root_p, int key) {
    // when root is NULL, which means there's no Node yet
    if (!(*root_p)) {
        *root_p = makeNode(NULL, key);
    }
    else {
        int whichChild;
        Node * current = *root_p;
        Node * parent;
        while (current) {
            parent = current;
            if (key <= current -> key) {
                current = current -> left_c;
                whichChild = LEFT;
            }
            else {
                current = current -> right_c;
                whichChild = RIGHT;
            }
        }
        current = makeNode(parent, key);
        if (whichChild == LEFT)
            parent -> left_c = current;
        else
            parent -> right_c = current;
    }

    return;
}

void inorderWalk(Node * root) {
    if (root) {
        inorderWalk(root -> left_c);
        printf("%d\n", root -> key);
        inorderWalk(root -> right_c);
    }

    return;
}

void inorderWalkNonrecursive(Node * root) {
    Node * current = root;
    Node * backFrom = NULL;
    while (current) {
        // go left
        if (current -> left_c && backFrom != current -> left_c) {
            current = current -> left_c;
        }
        // go right
        else if (current -> right_c && backFrom != current -> right_c) {
            printf("%d\n");
            current = current -> right_c;
        }
        // go up
        else if () {
            // when go up, print out if it's the right child of its parent
            if (current == current -> p -> righ_c)
                printf("%d\n");
            backFrom = current;
            current = current -> p;
        }
    }

    return;
}
