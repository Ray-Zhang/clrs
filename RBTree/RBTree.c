#include "RBTree.h"
#include <stdlib.h>
#include <stdio.h>

static void leftRotate(RBTree * rbt, Node * x) {
    Node * y = x -> right;
    x -> right = y -> left;
    if (y -> left != rbt -> nil)
        y -> left -> parent = x;
    if (x -> parent == rbt -> nil)
        rbt -> root = y;
    else if (x == x -> parent -> left)
        x -> parent -> left = y;
    else
        x -> parent -> right = y;
    y -> left = x;
    x -> parent = y;

    return;
}

static void rightRotate(RBTree * rbt, Node * x) {
    Node * y = x -> left;
    x -> left = y -> right;
    if (y -> right != rbt -> nil)
        y -> right -> parent = x;
    if (x -> parent == rbt -> nil)
        rbt -> root = y;
    else if (x == x -> parent -> left)
        x -> parent -> left = y;
    else
        x -> parent -> right = y;
    y -> right = x;
    x -> parent = y;

    return;
}

static void rbInsertFixup(RBTree * rbt, Node * z) {
    while (z -> parent -> color == RED) {
        if (z -> parent == z -> parent -> parent -> left) {
            Node * y = z -> parent -> parent -> right;
            if (y -> color == RED) {
                z -> parent -> color = BLACK;
                y -> color = BLACK;
                z -> parent -> parent -> color = RED;
                z = z -> parent -> parent;
            }
            else {
                if (z == z -> parent -> right) {
                    z = z -> parent;
                    leftRotate(rbt, z);
                }
                z -> parent -> color = BLACK;
                z -> parent -> parent -> color = RED;
                rightRotate(rbt, z -> parent -> parent);
            }
        }
        else {
            Node * y = z -> parent -> parent -> left;
            if (y -> color == RED) {
                z -> parent -> color = BLACK;
                y -> color = BLACK;
                z -> parent -> parent -> color = RED;
                z = z -> parent -> parent;
            }
            else {
                if (z == z -> parent -> left) {
                    z = z -> parent;
                    rightRotate(rbt, z);
                }
                z -> parent -> color = BLACK;
                z -> parent -> parent -> color = RED;
                leftRotate(rbt, z -> parent -> parent);
            }
        }
    }
    rbt -> root -> color = BLACK;

    return;
}

static void rbTransplant(RBTree * rbt, Node * u, Node * v) {
    if (u -> parent == rbt -> nil) {
        rbt -> root = v;
    }
    else if (u == u -> parent -> left) {
        u -> parent -> left = v;
    }
    else {
        u -> parent -> right = v;
    }
    v -> parent = u -> parent;

    return;
}

static Node * rbMinimum(RBTree * rbt, Node * subroot) {
    Node * current = subroot;
    while (current -> left != rbt -> nil) {
        current = current -> left;
    }
    return current;
}

static void rbDeleteFixup(RBTree * rbt, Node * x) {
    while (x != rbt -> nil && x -> color == BLACK) {
        if (x == x -> parent -> left) {
            Node * w = x -> parent -> right;
            if (w -> color == RED) {
                w -> color = BLACK;
                x -> parent -> color = RED;
                leftRotate(rbt, x -> parent);
                w = x -> parent -> right;
            }
            if (w -> left -> color == BLACK && w -> right -> color == BLACK) {
                w -> color = RED;
                x = x -> parent;
            }
            else {
                if (w -> right -> color == BLACK) {
                    w -> left -> color = BLACK;
                    w -> color = RED;
                    rightRotate(rbt, w);
                    w = x -> parent -> right;
                }
                w -> color = x -> parent -> color;
                x -> parent -> color = BLACK;
                w -> right -> color = BLACK;
                leftRotate(rbt, x -> parent);
                x = rbt -> root;
            }
        }
        else {
            Node * w = x -> parent -> left;
            if (w -> color == RED) {
                w -> color = BLACK;
                x -> parent -> color = RED;
                rightRotate(rbt, x -> parent);
                w = x -> parent -> left;
            }
            if (w -> left -> color == BLACK && w -> right -> color == BLACK) {
                w -> color = RED;
                x = x -> parent;
            }
            else {
                if (w -> left -> color == BLACK) {
                    w -> right -> color = BLACK;
                    w -> color = RED;
                    leftRotate(rbt, w);
                    w = x -> parent -> left;
                }
                w -> color = x -> parent -> color;
                x -> parent -> color = BLACK;
                x -> left -> color = BLACK;
                rightRotate(rbt, x -> parent);
                x = rbt -> root;
            }
        }
    }
}

void rbInsert(RBTree * rbt, Node * z) {
    Node * y = rbt -> nil;
    Node * x = rbt -> root;
    while (x != rbt -> nil) {
        y = x;
        if (z -> key < x -> key)
            x = x -> left;
        else
            x = x -> right;
    }
    if (y == rbt -> nil) {
        rbt -> root = z;
        return;    // if the tree is empty, create root and return
    }
    z -> parent = y;
    if (z -> key < y -> key)
        y -> left = z;
    else
        y -> right = z;
    z -> left = rbt -> nil;
    z -> right = rbt -> nil;
    z -> color = RED;
    rbInsertFixup(rbt, z);

    return;
}

RBTree * makeRBTree() {
    RBTree * newrbt = (RBTree *) malloc(sizeof(RBTree));
    if (!newrbt)
        exit(1);
    newrbt -> nil = (Node *) malloc(sizeof(Node));
    if (!newrbt -> nil)
    {
        newrbt -> nil -> color = BLACK;    // sentinel node is always BLACK
        newrbt -> nil -> parent = NULL;
        newrbt -> nil -> left = newrbt -> nil;
        newrbt -> nil -> right = newrbt -> nil;
    }
    newrbt -> root = newrbt -> nil;
    return newrbt;
}

void rbDelete(RBTree * rbt, Node * z) {
    Node * x;
    Node * y = z;
    enum RedOrBlack y_orig_color = y -> color;
    if (z -> left == rbt -> nil) {
        x = z -> right;
        rbTransplant(rbt, z, z -> right);
    }
    else if (z -> right == rbt -> nil) {
        x = z -> left;
        rbTransplant(rbt, z, z -> left);
    }
    else {
        y = rbMinimum(rbt, z -> right);
        x = y -> right;
        y_orig_color = y -> color;
        if (y -> parent == z)
            x -> parent = y;
        else {
            rbTransplant(rbt, y, y -> right);
            y -> right = z -> right;
            y -> right -> parent = y;
        }
        rbTransplant(rbt, z, y);
        y -> left = z -> left;
        y -> left -> parent = y;
        y -> color = z -> color;
    }

    if (y_orig_color == BLACK)
        rbDeleteFixup(rbt, x);
}
