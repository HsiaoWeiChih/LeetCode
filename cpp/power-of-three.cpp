#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
    here:
        if (n == 1)
        {
            return true;
        }
        else if (n < 3)
        {
            return false;
        }
        else if (n == 3)
        {
            return true;
        }
        else if (n % 3 != 0)
        {
            return false;
        }
        else
        {
            n /= 3;
            goto here;
        }
    }
};