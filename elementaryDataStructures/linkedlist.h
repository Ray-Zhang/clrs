typedef struct {
    int next;
    int prev;
    void * data;
} Object;

typedef struct {
    int free;
    Object * objects;
} FreeList;

FreeList * createFreeList(int cap);

void deleteFreeList(FreeList * fl);

Object * allocateObject(FreeList * freelist);

void freeObject(FreeList * freelist, int idx);
