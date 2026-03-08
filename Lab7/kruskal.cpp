#include <iostream>
using namespace std;

int parent[100];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[a] = b;
}

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[n][n];

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // initialize parent
    for(int i = 0; i < n; i++)
        parent[i] = i;

    int edges = 0, total = 0;

    cout << "\nEdges in MST:\n";

    while(edges < n - 1) {
        int min = 100000, u = -1, v = -1;

        // find minimum edge
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int a = find(u);
        int b = find(v);

        if(a != b) {
            cout << u << " - " << v << " = " << min << endl;
            total += min;
            unionSet(a, b);
            edges++;
        }

        cost[u][v] = cost[v][u] = 100000; // mark used
    }

    cout << "Total cost: " << total;

    return 0;
}