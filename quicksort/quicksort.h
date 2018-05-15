typedef struct {
    int q;
    int t;
} IdxPair;

void quicksort(int * ary, const int start, const int end);

static int hoarePartition(int * ary, const int start, const int end);

static IdxPair * partitionDot(int * ary, const int start, const int end);

void quicksortDot(int * ary, const int start, const int end);

void tailRecursiveQuicksort(int * ary, const int start, const int end);
