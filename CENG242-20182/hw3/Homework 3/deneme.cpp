#include <cmath>
#include <iostream>

using namespace std;

int numLength(int x)
    {
        return (int)ceil(0.00000001 + log10((double)x));
    }

int main()
    {
        while (1)
        {
            int x;
            cin>>x;
            cout<<numLength(x)<<endl;
        }
        
    }