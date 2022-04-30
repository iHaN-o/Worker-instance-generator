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
    int density = atof(argv[4]) * 10000;
    int factory[Q + 1];
    for (int i = 1; i <= P; i++)
        factory[i] = i;
    for (int i = P + 1; i <= Q; i++)
        factory[i] = (i % P == 0) ? P : i % P;
        // factory[i] = rand() % P + 1;
    sort(factory + 1, factory + Q + 1);
    for (int i = 1; i <= Q; i++)
        printf("%d ", factory[i]);
    printf("\n");
    if (P < W) {
        for (int i = 1; i <= Q; i++) {
            for (int i = 1; i <= W; i++)
                if (rand() % 10000 < density) printf("1 ");
                else printf("0 ");
            printf("\n");
        }
        return 0;
    }
    int W2 = rand() % (max(W / 10, 1)) + W / 15;
    int W1 = W - W2;
    int P1 = W1 - 1;
    int P2 = P - P1;
    int board[P + 1][W + 1], able[Q + 1][W + 1];
    for (int i = 1; i <= P; i++)
        for (int j = 1; j <= W; j++) {
            if (i <= P1) board[i][j] = 1;
            else board[i][j] = (j <= W2 ? 1 : 0);
        }

    for (int i = 1; i <= Q; i++) {
        int id = factory[i];
        for (int j = 1; j <= W; j++) {
            if (board[id][j]) able[i][j] = (rand() % 10000 < density ? 1 : 0);
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