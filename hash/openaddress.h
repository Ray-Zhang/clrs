#define TRUE 1
#define FALSE 0

#define M 701

typedef struct {
    int key;
    void * data;
} KeyVal;

typedef struct {
    int isDeleted;
    int isUsed;
    KeyVal kv;
} HashItem;

int hashInsert(HashItem * hashTable, KeyVal kv);

int hashSearch(HashItem * hashTable, int key);

void hashDelete(HashItem * hashTable, int key);
