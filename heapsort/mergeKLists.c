/*
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* retListNode = NULL;
    struct ListNode* cur = retListNode;

    Heap hp;
    hp.data = lists;
    hp.size = listsSize;

    // create heap of ListNode based on ListNode.val
    for (int i = (listsSize / 2) - 1; i >= 0; i--)
    {
        listNodeMinHeapify(&hp, i);
    }

    while ((hp.size) > 0)
    {
        struct ListNode * newItem = (struct ListNode*)malloc(sizeof(struct ListNode));
        newItem -> val = listNodeHeapExtractMin(&hp);
        newItem -> next = NULL;
        if (cur)
        {
            cur -> next = newItem;
            cur = newItem;
        }
        else
        {
            cur = newItem;
            retListNode = newItem;
        }
    }

    return retListNode;
}












// ------------------
void listNodeInit(struct ListNode * listnode, int v, struct ListNode * n)
{
    listnode -> val = v;
    listnode -> next = n;
    return;
}

void showList(struct ListNode * head)
{
    struct ListNode * currentNode = head;
    while (currentNode)
    {
        printf("%d ", currentNode -> val);
        currentNode = currentNode -> next;
    }
    printf("\n");
    return;
}

int main(void)
{
    // test data
    struct ListNode * head1, * head2, * head3;
    head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 -> val = 1; head1 -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 -> next -> val = 4; head1 -> next -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 -> next -> next -> val = 5; head1 -> next -> next -> next = NULL;

    head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2 -> val = 1; head2 -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2 -> next -> val = 3; head2 -> next -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2 -> next -> next -> val = 4; head2 -> next -> next -> next = NULL;

    head3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head3 -> val = 2; head3 -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head3 -> next -> val = 6; head3 -> next -> next = NULL;

    struct ListNode * lists[3] = { head1, head2, head3 };

    struct ListNode * testRet = mergeKLists(lists, 3);
    showList(testRet);

    exit(0);
}

