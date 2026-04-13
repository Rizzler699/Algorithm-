#include <iostream>
#include <vector>
using namespace std;

void optSol(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    optSol(s, i, s[i][j]);
    optSol(s, s[i][j] + 1, j);
    cout << ")";
}

int main()
{
    int n;
    cout<<"Enter number of matrices :";
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = 10000000;

            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum cost = " << m[1][n - 1] << endl;

    cout << "Order: ";
    optSol(s, 1, n - 1);
    cout << endl;

    return 0;
}