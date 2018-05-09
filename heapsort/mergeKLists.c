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

#define LEFT(x) (2*x+1)
#define RIGHT(x) (2*x+2)

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNodeMinHeap {
    struct ListNode ** heap;
    int size;
};

static void listNodeMinHeapify(struct ListNodeMinHeap * minHeap, int idx)
{
    int leftIdx, rightIdx, minIdx;
    if (idx < 0 || idx >= minHeap -> size)
        return;
    else
    {
        leftIdx = LEFT(idx);
        rightIdx = RIGHT(idx);
        if (leftIdx < minHeap -> size && (minHeap -> heap)[leftIdx] -> val < (minHeap -> heap)[idx] -> val)
        {
            minIdx = leftIdx;
        }
        else
        {
            minIdx = idx;
        }
        if (rightIdx < minHeap -> size && (minHeap -> heap)[rightIdx] -> val < (minHeap -> heap)[minIdx] -> val)
        {
            minIdx = rightIdx;
        }
        if (idx != minIdx)
        {
            struct ListNode * temp = (minHeap -> heap)[idx];
            (minHeap -> heap)[idx] = (minHeap -> heap)[minIdx];
            (minHeap -> heap)[minIdx] = temp;
            listNodeMinHeapify(minHeap, minIdx);
        }
    }
}

static void listNodeHeapExtractMin(struct ListNodeMinHeap * minHeap)
{

{

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int retListSize = 0;

    struct ListNodeMinHeap minHeap;
    minHeap.heap = lists;
    minHeap.size = listsSize;

    // create heap of ListNode based on ListNode.val
    for (int i = (listsSize / 2) - 1; i >= 0; i--)
    {
        listNodeMinHeapify(&minHeap, i);
    }

    return NULL;
}

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

/*
 * free memory allocated to next
 * when it doesn't point to NULL.
 */
void listNodeDel(struct ListNode * listnode)
{
    if (listnode -> next)
        free(listnode -> next);
    return;
}





// ------------------

int main(void)
{
    // create and initialize data to be tested
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

    mergeKLists(lists, 3);

    exit(0);
}

