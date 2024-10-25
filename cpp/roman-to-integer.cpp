#include <iostream>

using namespace std;

class Solution {
public:
    int val(char c)
    {
        if(c == 'M') return 1000;
        else if(c == 'D') return 500;
        else if(c == 'C') return 100;
        else if(c == 'L') return 50;
        else if(c == 'X') return 10;
        else if(c == 'V') return 5;
        else return 1;
    }
    int romanToInt(string s) {
        int num = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(val(s[i]) >= val(s[i+1]))
                num += val(s[i]);
            else if(val(s[i]) < val(s[i+1]))
                num -= val(s[i]);
        }
        return num;
    }
};