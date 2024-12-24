#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;

        int digitCount = 0;
        while(n > 0)
        {
            if(n % 2 == 1)
                digitCount++;

            if(digitCount >= 2)
                return false;
            n = n >> 1;
        }
        return true;
    }
};

int main()
{
    Solution test;
    auto b = test.isPowerOfTwo(3);
    cout << (b? "true":"false") << endl;
    return 0;
}