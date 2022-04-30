#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
    srand(time(NULL));
    if (argc < 5) {
        printf("Wrong format\n");
        return 0;
    }
    int P = atoi(argv[1]);
    int Q = atoi(argv[2]);
    int W = atoi(argv[3]);
    double density = atof(argv[4]);
    int density2 = 0.02 * 10000;
    int density1 = min(1.0, 2 * density - 0.02) * 10000;
    
    int factory[Q + 1];
    for (int i = 1; i <= P; i++)
        factory[i] = i;
    for (int i = P + 1; i <= Q; i++)
        // factory[i] = (i % P == 0) ? P : i % P;
        factory[i] = rand() % P + 1;
    sort(factory + 1, factory + Q + 1);
    for (int i = 1; i <= Q; i++)
        printf("%d ", factory[i]);
    printf("\n");

    int board[P + 1][W + 1], able[Q + 1][W + 1];
    for (int i = 1; i <= P; i++)
        for (int j = 1; j <= W; j++) {
            if (i <= j) board[i][j] = (rand() % 10000 < density1 ? 1 : 0);
            else if (i > j) board[i][j] = (rand() % 10000 < density2 ? 1 : 0);
        }

    for (int i = 1; i <= Q; i++) {
        int id = factory[i];
        for (int j = 1; j <= W; j++) {
            if (board[id][j]) able[i][j] = 1;
            else able[i][j] = 0;
        }
    }

    for (int i = 1; i <= Q; i++) {
        for (int j = 1; j <= W; j++)
            printf("%d ", able[i][j]);
        printf("\n");
    }
    return 0;
}