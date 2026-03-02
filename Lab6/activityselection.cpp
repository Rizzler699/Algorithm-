#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    int start, finish;
};

bool cmp(const Activity& a, const Activity& b)
{
    return a.finish < b.finish;
}

int main()
{
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity a[n];

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].start >> a[i].finish;
    }

    sort(a, a + n, cmp);

    cout << "\nSelected Activities:\n";

    int i = 0;
    cout << "(" << a[i].start << ", " << a[i].finish << ")\n";

    for (int j = 1; j < n; j++)
    {
        if (a[j].start >= a[i].finish)
        {
            cout << "(" << a[j].start << ", " << a[j].finish << ")\n";
            i = j;
        }
    }

    return 0;
}