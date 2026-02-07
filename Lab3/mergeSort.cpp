#include<iostream>
#include<ctime>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    while (i < n1)
        arr[k++] = a[i++];

    while (j < n2)
        arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    srand(time(0));
    cout << "InputSize\tAverageTime(s)\n";

    for (int n = 1000; n <= 10000; n += 1000)
    {
        double totalTime = 0.0;

        for (int k = 0; k < 100; k++)
        {
            int* arr = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = rand() % 100000;

            clock_t start = clock();
            mergeSort(arr, 0, n - 1);   
            clock_t end = clock();

            totalTime += double(end - start) / CLOCKS_PER_SEC;
            delete[] arr;            
        }

        double avgTime = (totalTime / 100);
        cout << n << "\t\t" << avgTime << endl;
    }

    return 0;
}
