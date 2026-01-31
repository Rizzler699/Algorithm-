#include <iostream>
using namespace std;

int NumDips(double v)
{
    if (v < 1.0)
        return 0;

    return 1 + NumDips(v - 0.425*v);
}

int main() {
int v;
   cout<<"Enter the velocity of the ball:";
   cin>>v;
          cout<<  NumDips(v);
    return 0;
}
