#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return;          // found
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
}

int main()
{
    srand(time(0));
    cout << "InputSize\tAverageTime(us)\n";

    for (int n = 1000; n <= 20000; n += 1000)
    {
        double totalTime = 0;

        for (int k = 0; k < 100; k++)
        {
            int* arr = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = rand();

            // Binary search needs sorted array
            sort(arr, arr + n);

            int key = arr[n / 2];   // element surely present

            clock_t start = clock();
            binarySearch(arr, n, key);
            clock_t end = clock();

            totalTime += double(end - start) / CLOCKS_PER_SEC;

            delete[] arr;
        }

        double avgTime = (totalTime / 100) * 1000000;
        cout << n << "\t\t" << avgTime << endl;
    }
}
