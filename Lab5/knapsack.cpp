#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int n, int W) {
   
    if(n == 0 || W == 0)
        return 0;

    if(wt[n-1] > W)
        return knapsack(wt, val, n-1, W);

    else {
        int take = val[n-1] + knapsack(wt, val, n-1, W - wt[n-1]);
        int skip = knapsack(wt, val, n-1, W);
        return max(take, skip);
    }
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], val[n];

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter capacity: ";
    cin >> W;

    int result = knapsack(wt, val, n, W);

    cout << "Maximum Profit: " << result;

    return 0;
}