#include <iostream>
#include <queue>  // Include the queue header
using namespace std;

#define MAX_V 100

void enqueue(queue<int>& q, int vertex) {
    q.push(vertex);
}

int dequeue(queue<int>& q) {
    int front = q.front();
    q.pop();
    return front;
}
//adjList[i][j] is 1 if there is an edge between vertex i and j else 0
void bfsOfGraph(int V, int adjList[MAX_V][MAX_V]) {
    bool visited[MAX_V] = {false};//An array of boolean values to keep track of whether a vertex has been visited during the traversal.
    queue<int> q;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) 
        {
            enqueue(q, i);
            visited[i] = true;
            //Dequeue a vertex from the queue, print it, and then explore its neighbors.
            while (!q.empty()) 
            {
                int currentVertex = dequeue(q);
                cout << currentVertex << " ";

                for (int j = 0; j < V; ++j) {
                    if (adjList[currentVertex][j] == 1 && !visited[j]) {
                        enqueue(q, j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    int adjList[MAX_V][MAX_V] = {0};

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
        adjList[v][u] = 1; // Assuming an undirected graph
    }

    bfsOfGraph(V, adjList);

    return 0;
}
