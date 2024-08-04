#include <iostream>

using namespace std;

class Solution {
private:
    bool isBetweenNum(int x, unsigned int num1, unsigned int num2) {
        if(x >= num1*num1 && x < num2*num2)
            return true;
        else
            return false;
    }
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;

        int result = 0;
        for(unsigned int i=0; i<=x; i++){

            if(isBetweenNum(x, i, i+1)) {
                result = i;
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution test;
    cout << test.mySqrt(8) << endl;

    return 0;
}