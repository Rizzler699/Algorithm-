#include <iostream>
#include<ctime>
using namespace std;


int partition(int arr[], int low, int high)
{

    int pivot = arr[low];
 
    int k = high;
    for (int i = high; i > low; i--) {
        if (arr[i] > pivot)
            swap(arr[i], arr[k--]);
    }
    swap(arr[low], arr[k]);
    return k;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int idx = partition(arr, low, high);
        quickSort(arr, low, idx - 1);
        quickSort(arr, idx + 1, high);
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
            quickSort(arr, 0, n - 1);   
            clock_t end = clock();

            totalTime += double(end - start) / CLOCKS_PER_SEC;
            delete[] arr;            
        }

        double avgTime = (totalTime / 100);
        cout << n << "\t\t" << avgTime << endl;
    }

    return 0;
}

