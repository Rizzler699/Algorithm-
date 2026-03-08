#include <iostream>
using namespace std;

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

    int visited[n] = {0};
    visited[0] = 1;

    int edges = 0, total = 0;

    cout << "\nEdges in MST:\n";

    while(edges < n - 1) {
        int min = 100000, a = -1, b = -1;

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                for(int j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j]) {
                        if(cost[i][j] < min) {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }

        cout << a << " - " << b << " = " << min << endl;

        total += min;
        visited[b] = 1;
        edges++;
    }

    cout << "Total cost: " << total;

    return 0;
}