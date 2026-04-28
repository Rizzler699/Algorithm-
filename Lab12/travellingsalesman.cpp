#include <iostream>
using namespace std;

int n;
int cost[10][10];
int visited[10];

int tsp(int city, int count, int currCost) {
    if (count == n && cost[city][0] > 0) {
        return currCost + cost[city][0];
    }

    int ans = 100000;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && cost[city][i] > 0) {
            visited[i] = 1;
            int temp = tsp(i, count + 1, currCost + cost[city][i]);
            if (temp < ans) {
                ans = temp;
            }
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[0] = 1;

    int result = tsp(0, 1, 0);

    cout << "Minimum travelling cost = " << result;

    return 0;
}