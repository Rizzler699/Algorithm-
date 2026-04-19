#include <iostream>
using namespace std;

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    int edges[100][3];
    int dist[100];

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    for (int i = 0; i < V; i++) {
        dist[i] = 100000;
    }

    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 100000 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 100000 && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return 0;
        }
    }

    cout << "\nShortest distances from source:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " -> " << dist[i] << endl;
    }

    return 0;
}