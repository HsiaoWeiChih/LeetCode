#include <iostream>

using namespace std;

class Solution {
private:
    int getDigitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num -= num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        int newNum = num;
        if(num >= 10)
        {
            newNum = getDigitSum(num);
            return addDigits(newNum);
        }
        else
            return newNum;
    }
};

int main()
{

    return 0;
}