#include <stdio.h>
#include <stdlib.h>
#include "openaddress.h"

static inline unsigned hash(int key, int i) {
    return key % M + i;
}

int hashInsert(HashItem * hashTable, KeyVal kv) {
    int i = 0;
    while (i < M) {
        unsigned h = hash(kv.key, i++);
        if (!hashTable[h].isUsed) {
            hashTable[h].kv = kv;
            hashTable[h].isUsed = TRUE;
            hashTable[h].isDeleted = FALSE;
        }
        return h;
    }
    exit(1);
}

int hashSearch(HashItem * hashTable, int key) {
    int i = 0;
    int j;
    do {
        j = hash(key, i++);
        if (hashTable[j].isUsed && hashTable[j].kv.key == key) {
            return j;
        }
    } while ((hashTable[j].isUsed || hashTable[j].isDeleted) && i < M);
    return -1;
}

void hashDelete(HashItem * hashTable, int key) {
    int i = 0;
    int j;
    do {
        j = hash(key, i++);
        if (hashTable[j].isUsed && hashTable[j].kv.key == key) {
            hashTable[j].isUsed = FALSE;
            hashTable[j].isDeleted = TRUE;
            return;
        }
    } while ((hashTable[j].isUsed || hashTable[j].isDeleted) && i < M);
    return;
}
