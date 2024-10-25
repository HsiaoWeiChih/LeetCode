#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x == 0)
            return true;
        else
        {
            int temp = x;
            vector<int> a;
            while(temp!=0)
            {
                a.push_back(temp%10);
                temp /= 10;
            }
            int asize = a.size();
            for(int j=asize; j>1; j-=2)
            {
                if(x%10 != a.back())
                {
                    return false;
                }
                a.pop_back();
                x /= 10;
            }
            return true;
        }
    }
};