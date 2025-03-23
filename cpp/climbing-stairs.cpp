#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            //Why this doesn't work?
            /*
            if(n == 1)
                return 1;
            if(n == 2)
                return 2;
            
            return climbStairs(n-1) + climbStairs(n-2);*/
            // ans 重複計算太多
            
            //this method can reduce the calculation of the same step
            static vector<int> t = vector<int>(46, -1);
            
            if(t[n] != -1)
                return t[n];
            
            if(n <= 2)
                return t[n] = n;
                
            return t[n] = climbStairs(n-1) + climbStairs(n-2);
        }
    };