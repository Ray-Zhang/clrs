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
        // go left, prints nothing, don't set backFrom
        if (current -> left_c && backFrom != current -> left_c
                && backFrom != current -> right_c) {
            current = current -> left_c;
        }
        // go right, prints out current key, don't set backFrom
        else if (current -> right_c && backFrom != current -> right_c) {
            printf("%d\n", current -> key);
            current = current -> right_c;
        }
        // go up, may print out current key, set backFrom to current
        else {
            // when go up, print out if it's coming from it's left child (no right child)
            // or it has no child at all
            if (backFrom == current -> left_c || (!current -> left_c && !current -> right_c))
                printf("%d\n", current -> key);
            backFrom = current;
            current = current -> p;
        }
    }

    return;
}

Node * searchBST(Node * root, int key) {
    Node * current = root;
    while (current && current -> key != key) {
        if (key < current -> key)
            current = current -> left_c;
        else
            current = current -> right_c;
    }
    return current;
}

Node * minimumBST(Node * root) {
    if (!root)
        exit(1);
    Node * x = root;
    while (x -> left_c)
        x = x -> left_c;
    return x;
}

Node * maximumBST(Node * root) {
    if (!root)
        exit(1);
    Node * x = root;
    while (x -> right_c)
        x = x -> right_c;
    return x;
}

Node * successor(Node * x) {
    if (x -> right_c)
        return minimumBST(x -> right_c);
    Node * y = x -> p;
    while (y != NULL && x == y -> right_c) {
        x = y;
        y = y -> p;
    }
    return y;
}

Node * predecessor(Node * x) {
    if (x -> left_c)
        return maximumBST(x -> left_c);
    Node * y = x -> p;
    while (y != NULL && x == y -> left_c) {
        x = y;
        y = y -> p;
    }
    return y;
}
