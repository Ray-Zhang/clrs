#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef struct
{
    int low;
    int high;
    int sum;
} MaxSubarrayRet_t;

void unittest(void);

MaxSubarrayRet_t findMaximumSubarrayBruteForce(int *, int, int);

MaxSubarrayRet_t findMaximumSubarrayRecursive(int *, int, int);

MaxSubarrayRet_t findMaximumSubarrayLinear(int *, int, int);

static MaxSubarrayRet_t findMaximumCrossSubarray(int *, int, int, int);

int main(int argc, char * argv[])
{
    unittest();
    exit(0);
}

MaxSubarrayRet_t findMaximumSubarrayBruteForce(int * array, int low, int high)
{
    int i, j;
    int sum;
    MaxSubarrayRet_t ret;
    ret.sum = INT_MIN;

    /* loop starting index of subarray */
    for (i = low; i <= high; i++)
    {
        sum = 0;
        /* loop ending index of subarray */
        for (j = i; j <= high; j++)
        {
            sum += array[j];
            if (sum > ret.sum)
            {
                ret.low = i;
                ret.high = j;
                ret.sum = sum;
            }
        }
    }

    return ret;
}

MaxSubarrayRet_t findMaximumSubarrayRecursive(int * array, int low, int high)
{
    MaxSubarrayRet_t ret, leftRet, rightRet, crossRet;
    int mid;
    if (low == high)
    {
        ret.low = low;
        ret.high = high;
        ret.sum = array[low];
        return ret;
    }
    else
    {
        mid = (low + high) / 2;
        leftRet = findMaximumSubarrayRecursive(array, low, mid);
        rightRet = findMaximumSubarrayRecursive(array, mid + 1, high);
        crossRet = findMaximumCrossSubarray(array, low, mid, high);
        if (leftRet.sum >= rightRet.sum && leftRet.sum >= crossRet.sum)
        {
            return leftRet;
        }
        else if (rightRet.sum >= leftRet.sum && rightRet.sum >= crossRet.sum)
        {
            return rightRet;
        }
        else
        {
            return crossRet;
        }
    }
}

MaxSubarrayRet_t findMaximumSubarrayLinear(int * array, int low, int high)
{
    MaxSubarrayRet_t ret, maxUntilI;
    int i;
    /* initialize max subarray and max array until index i as only the first element */
    maxUntilI.low = ret.low = low;
    maxUntilI.high = ret.high = low;
    maxUntilI.sum = ret.sum = array[low];

    for (i = low + 1; i <= high; i++)
    {
        // update max array until new index i
        if (maxUntilI.sum <= 0)
        {
            maxUntilI.low = i;
            maxUntilI.high = i;
            maxUntilI.sum = array[i];
        }
        else
        {
            maxUntilI.high++;
            maxUntilI.sum += array[i];
        }

        // determine max subarray until new index i
        if (maxUntilI.sum > ret.sum)
        {
            ret = maxUntilI;
        }
    }

    return ret;
}

static MaxSubarrayRet_t findMaximumCrossSubarray(int * array, int low, int mid, int high)
{
    MaxSubarrayRet_t ret;
    int i;
    int sum, leftSum, rightSum;

    leftSum = INT_MIN;
    rightSum = INT_MIN;
    sum = 0;
    for (i = mid; i >= low; i--)
    {
        sum += array[i];
        if (sum > leftSum)
        {
            ret.low = i;
            leftSum = sum;
        }
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++)
    {
        sum += array[i];
        if (sum > rightSum)
        {
            ret.high= i;
            rightSum = sum;
        }
    }
    ret.sum = leftSum + rightSum;
    return ret;
}

void unittest(void)
{
    MaxSubarrayRet_t testRet;
    int positives[9] = {1,2,3,4,5,6,7,8,9};
    int negatives[9] = {-1,-2,-3,-4,-5,-6,-7,-8,-9};

    testRet = findMaximumSubarrayBruteForce(positives, 0, 8);
    assert(testRet.low == 0 && testRet.high == 8);

    testRet = findMaximumSubarrayBruteForce(negatives, 0, 8);
    assert(testRet.low == 0 && testRet.high == 0);

    testRet = findMaximumSubarrayRecursive(positives, 0, 8);
    assert(testRet.low == 0 && testRet.high == 8);

    testRet = findMaximumSubarrayRecursive(negatives, 0, 8);
    assert(testRet.low == 0 && testRet.high == 0);

    testRet = findMaximumSubarrayLinear(positives, 0, 8);
    assert(testRet.low == 0 && testRet.high == 8);

    testRet = findMaximumSubarrayLinear(negatives, 0, 8);
    assert(testRet.low == 0 && testRet.high == 0);

    return;
}
