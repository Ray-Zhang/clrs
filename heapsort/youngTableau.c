#include "youngTableau.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

static void showYoungTableau(YoungTableau * youngTableau) {
    for (int i = 0; i < youngTableau -> rowSize; i++)
        for (int j = 0; j < youngTableau -> colSize; j++) {
            printf("%d ", (youngTableau -> data)[i * youngTableau -> colSize + j]);
        }

    return;
}

YoungTableau * youngTableauCtor(int colSz, int rowSz) {
    YoungTableau * newYoungTableau = (YoungTableau *)malloc(sizeof(YoungTableau));
    newYoungTableau -> colSize = colSz;
    newYoungTableau -> rowSize = rowSz;
    newYoungTableau -> data = (int *)malloc(sizeof(int) * colSz * rowSz);
    int tableauSize = colSz * rowSz;
    for (int i = 0; i < tableauSize; i++) {
        (newYoungTableau -> data)[i] = INT_MIN;
    }
    showYoungTableau(newYoungTableau);

    return newYoungTableau;
}

void youngTableauDtor(YoungTableau * youngTableau) {
    free(youngTableau -> data);
    free(youngTableau);
}
