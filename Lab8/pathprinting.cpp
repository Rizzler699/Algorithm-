#include <iostream>
#include <vector>
using namespace std;

#define INF 100000

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(n, INF);
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1, minDist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    cout << "\nShortest distances from source:\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    cout << "\nPaths:\n";
    for (int i = 0; i < n; i++) {
        if (i == src) continue;

        cout << "Path to " << i << ": ";
        int temp = i;
        vector<int> path;

        while (temp != -1) {
            path.push_back(temp);
            temp = parent[temp];
        }

        for (int j = path.size() - 1; j >= 0; j--) {
            cout << path[j];
            if (j != 0) cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}