#include <iostream>
#include <set>

using namespace std;

class Solution {
private:
    int squaterDigit(int n)
    {
        int result = 0;
        while(n > 0)
        {
            result += (n % 10) * (n % 10);
            n = (n - (n % 10)) / 10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        set<int> s;
        bool result = false;
        while(!s.count(n))
        {
            if(n == 1)
            {
                result = true;
                break;
            }
            s.insert(n);
            n = squaterDigit(n);
        }
        return result;
    }
};

int main()
{
    Solution test;
    cout << test.isHappy(19);

    return 0;
}