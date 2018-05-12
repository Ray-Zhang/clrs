#include "youngTableau.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void showYoungTableau(YoungTableau * youngTableau) {
    for (int i = 0; i < youngTableau -> rowSize; i++) {
        for (int j = 0; j < youngTableau -> colSize; j++) {
            printf("%d ", (youngTableau -> data)[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return;
}

YoungTableau * youngTableauCtor(int rowSz, int colSz) {
    YoungTableau * newYoungTableau = (YoungTableau *)malloc(sizeof(YoungTableau));
    newYoungTableau -> rowSize = rowSz;
    newYoungTableau -> colSize = colSz;
    newYoungTableau -> data = (int **)malloc(sizeof(int *) * rowSz);
    for (int i = 0; i < rowSz; i++) {
        (newYoungTableau -> data)[i] = (int *)malloc(sizeof(int) * colSz);
    }
    for (int i = 0; i < rowSz; i++) {
        for (int j = 0; j < colSz; j++) {
            (newYoungTableau -> data)[i][j] = INT_MAX;
        }
    }

    return newYoungTableau;
}

void youngTableauDtor(YoungTableau * youngTableau) {
    free(youngTableau -> data);
    free(youngTableau);
}

void youngTableauInsert(YoungTableau * youngTableau, int val) {
    // when tableau is full, error
    if ((youngTableau -> data)[youngTableau -> rowSize - 1][youngTableau -> colSize - 1]
            > INT_MAX)
        exit(1);
    int ** data = youngTableau -> data;
    int currentRow = youngTableau -> rowSize - 1, currentCol = youngTableau -> colSize - 1;
    data[currentRow][currentCol] = val;
    int rowLargest = currentRow, colLargest = currentCol;
    while (1) {
        if (currentRow - 1 >= 0
                && data[currentRow - 1][currentCol] > data[currentRow][currentCol]) {
            rowLargest = currentRow - 1;
            colLargest = currentCol;
        }
        if (currentCol - 1 >= 0
                && data[currentRow][currentCol - 1] > data[rowLargest][colLargest]) {
            rowLargest = currentRow;
            colLargest = currentCol - 1;
        }
        if (rowLargest != currentRow || colLargest != currentCol) {
            int temp = data[currentRow][currentCol];
            data[currentRow][currentCol] = data[rowLargest][colLargest];
            data[rowLargest][colLargest] = temp;
            currentRow = rowLargest;
            currentCol = colLargest;
        }
        else
            break;
    }

    return;
}

static void tableaufy(YoungTableau * youngTableau, const int row, const int col) {
    int rowSmallest, colSmallest;
    int ** data = youngTableau -> data;
    if (col + 1 < youngTableau -> colSize
            && data[row][col+1] < data[row][col]) {
        rowSmallest = row;
        colSmallest = col + 1;
    }
    else {
        rowSmallest = row;
        colSmallest = col;
    }
    if (row + 1 < youngTableau -> rowSize
            && data[row+1][col] < data[rowSmallest][colSmallest]) {
        rowSmallest = row + 1;
        colSmallest = col;
    }
    if (rowSmallest != row || colSmallest != col) {
        int temp = data[row][col];
        data[row][col] = data[rowSmallest][colSmallest];
        data[rowSmallest][colSmallest] = temp;
        tableaufy(youngTableau, rowSmallest, colSmallest);
    }
}

int extractMin(YoungTableau * youngTableau) {
    int retval = youngTableau -> data[0][0];
    (youngTableau -> data)[0][0] = INT_MAX;
    tableaufy(youngTableau, 0, 0);

    return retval;
}

int existInTableau(const YoungTableau * youngTableau, const int val) {
    // search from the last element in first row
    int rowIdx = 0, colIdx = youngTableau -> colSize;
    int ** data = youngTableau -> data;
    while (colIdx >= 0 && rowIdx < youngTableau -> rowSize) {
        if ( data[rowIdx][colIdx] == val )
            return EXIST;
        else if ( data[rowIdx][colIdx] < val ) {
            colIdx--;
        }
        else {
            rowIdx++;
        }
    }
    return NONEXIST;
}
