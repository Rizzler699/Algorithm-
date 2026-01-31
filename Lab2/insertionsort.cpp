#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    srand(time(0));
    cout<<"Input size/tAverage time(in seconds)";

    for(int n=1000;n<10000;n+=1000)
    {
        double totaltime=0.0;

        for(int i=0;i<100;i++)
        {
        int *arr=new int[n];
        for(int j=0;j<n;j++)
        arr[j]=rand();

        clock_t start=clock();
        insertionSort(arr,n);
        clock_t end=clock();

        totaltime+=double(end-start)/CLOCKS_PER_SEC;
        }
        double averageTime = totaltime / 100.0;
        cout << n << "\t\t" << averageTime << endl;
    }
}

