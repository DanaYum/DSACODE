#include<iostream>
#define n 4
#define INF 99999
using namespace std;

void Warshall(int g[][n]) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                g[i][j] = ((g[i][k] & g[k][j]) | g[i][j]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (g[i][j] == INF)
                cout << "INF\t";
            else
                cout << g[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int g[n][n];

    cout << "Enter the adjacency matrix (enter INF for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0 && i != j)
                g[i][j] = INF;
        }
    }

    Warshall(g);
    return 0;
}
