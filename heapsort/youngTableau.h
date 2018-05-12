#define EXIST 1
#define NONEXIST 0

typedef struct {
    int ** data;
    unsigned rowSize;
    unsigned colSize;
} YoungTableau;

YoungTableau * youngTableauCtor(int colSz, int rowSz);

void youngTableauDtor(YoungTableau * youngTableau);

void youngTableauInsert(YoungTableau * youngTableau, int val);

void showYoungTableau(YoungTableau * youngTableau);

static void tableaufy(YoungTableau * youngTableau, const int row, const int col);

int extractMin(YoungTableau * youngTableau);

int existInTableau(const YoungTableau * youngTableau, const int val);
