#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[n][n];

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[n];
    bool visited[n];

    for(int i = 0; i < n; i++) {
        dist[i] = 100000;
        visited[i] = false;
    }

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++) {

        int min = 100000, u;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for(int v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] && 
               dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest distances from source:\n";
    for(int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    return 0;
}