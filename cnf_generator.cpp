#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
    srand(time(NULL));
    if (argc < 4) {
        printf("Wrong format\n");
        return 0;
    }
    int P = atoi(argv[1]);
    int Q = atoi(argv[2]);
    int W = atoi(argv[3]);
    
    int factory[Q + 1], able[Q + 1][W + 1], index[Q + 1][W + 1];
    vector<int> clause;
    freopen(argv[4], "r", stdin);
    for (int i = 1; i <= Q; i++)
        scanf("%d", &factory[i]);
    
    int id = 0;
    for (int i = 1; i <= Q; i++)
        for (int j = 1; j <= W; j++) {
            scanf("%d", &able[i][j]);
            if (able[i][j]) index[i][j] = ++id;
        }
    
    int clauses = W;
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= Q; j++) 
            if (able[j][i]) clause.push_back(index[j][i]);
        clause.push_back(0);
    }
    
    vector<int> s;
    for (int p = 1; p <= P; p++) {
        s.clear();
        for (int i = 1; i <= Q; i++) {
            if (factory[i] != p) continue;
            for (int j = 1; j <= W; j++)
                if (able[i][j]) s.push_back(index[i][j]);
        }
        int l = s.size();
        clauses += l * (l - 1) / 2;
        for (int i = 0; i < l; i++)
            for (int j = i + 1; j < l; j++) {
                clause.push_back(-s[i]);
                clause.push_back(-s[j]);
                clause.push_back(0);
            }
    }
    fclose(stdin);
    printf("p cnf %d %d\n", id, clauses);
    int l = clause.size();
    for (int i = 0; i < l; i++) {
        if (clause[i]) printf("%d ", clause[i]);
        else printf("%d\n", clause[i]);
    }
    return 0;
}