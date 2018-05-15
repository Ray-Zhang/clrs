#include <stdlib.h>

static int partition(int * const ary, const int start, const int end);

static inline int getRandIdx(int base);

static void exchangeElements(int * const ary, const int idx1, const int idx2);

int randomizedSelect(const int * const ary, int start, int end, int ith);
