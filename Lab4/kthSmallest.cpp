#include<iostream>
using namespace std;

int partition(int arr[], int low, int high)
{

    int pivot = arr[low];
 
    int j = high;
    for (int i = high; i > low; i--) {
        if (arr[i] > pivot)
            swap(arr[i], arr[j--]);
    }
    swap(arr[low], arr[j]);
    return j;
}

int smallestNum(int arr[],int low,int high,int k)
{
    int small=partition(arr,low,high);
    if(small+1==k)
    return arr[small];
    else
    if(small+1<k)
    {
        return smallestNum(arr,small+1,high,k);
    }
    else
    {
    return smallestNum(arr,low,small--,k);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter value of k ";
    cin>>k;
    cout<<smallestNum(arr,0,n-1,k);
    return 0;
}