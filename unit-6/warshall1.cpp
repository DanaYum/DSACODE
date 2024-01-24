
#include <iostream>

using namespace std;

void warshallAlgorithm(int graph[10][10], int N) {
    // Applying Warshall's Algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main() {
    // Input
    int N;
    cin >> N;

    // Creating and initializing the adjacency matrix
    int graph[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    // Applying Warshall's Algorithm
    warshallAlgorithm(graph, N);

    // Output
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

