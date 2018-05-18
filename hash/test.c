#include "openaddress.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void unittest(void) {
    HashItem * testHT = (HashItem *) malloc(sizeof(HashItem) * M);
    for (int i = 0; i < M; i++) {
        testHT[i].isDeleted = FALSE;
        testHT[i].isUsed = FALSE;
    }
    if (!testHT)
        exit(1);
    KeyVal kv;
    for (int i = 0; i < 10000; i += 222) {
        kv.key = i;
        kv.data = (void *)malloc(sizeof(int));
        hashInsert(testHT, kv);
    }
    assert(hashSearch(testHT, 222) == 222);
    hashDelete(testHT, 222);
    assert(hashSearch(testHT, 222) == -1);
}

int main(void) {
    unittest();

    exit(0);
}
