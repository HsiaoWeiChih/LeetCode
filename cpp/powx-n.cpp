#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if(n < 0)
            x = 1 / x;
        
        int absN = abs(n);
        double pow = 1;
        while (absN)
        {
            if(absN & 1)
                pow *= x;

            absN >>= 1;
            x *= x;
        }

        return pow;
    }
};

int main()
{
    Solution test;
    cout << test.myPow(-3.0, -5);
    return 0;
}