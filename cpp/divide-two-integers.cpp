#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        bool positive = (dividend<0 == divisor<0);;
        // 轉正數
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        
        unsigned int result = 0;
        // Perform the division
        while (a >= b) {
            int q = 0;
            while (a > (b << (q + 1)))
                q++;
            a -= b << q;
            result += 1 << q;
        }

        if(result == (1<<31) && positive)
            return INT_MAX;
           
        return positive ? result : -result;
    }
};

int main()
{
    Solution test;
    cout << test.divide(-2147483648, -2147483648);
    return 0;
}
