#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool a[20]; 


void BTT(int k, int n)
{
    if (k > n)
    {
      
        return;
    }

    a[k] = true;      
    BTT(k + 1, n);    

    a[k] = false;    
    BTT(k + 1, n);    
}

int main()
{
    int repetitions = 100;

    cout << "Inputs(n)\tAverageTime(us)\n";

    
    for (int n = 2; n <= 15; n++)
    {
        long long totalTime = 0;

        
        for (int i = 0; i < repetitions; i++)
        {
            auto start = high_resolution_clock::now();
            BTT(1, n);
            auto end = high_resolution_clock::now();

            totalTime += duration_cast<microseconds>(end - start).count();
        }

        double averageTime = (double)totalTime / repetitions;
        cout << n << "\t\t" << averageTime << endl;
    }

    return 0;

}
