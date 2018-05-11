typedef struct {
    int * data;
    unsigned colSize;
    unsigned rowSize;
} YoungTableau;

YoungTableau * youngTableauCtor(int colSz, int rowSz);

void youngTableauDtor(YoungTableau * youngTableau);
