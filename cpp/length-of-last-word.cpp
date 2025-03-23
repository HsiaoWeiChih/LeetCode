#include <iostream>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int len = s.length();
            int last_len = 0;
            for(int i=len-1; i>=0; i--)
            {
                if(s[i] != 32)
                    last_len++;
                else if(s[i] == 32 && last_len>0)
                    break;
            }
            return last_len;
        }
    };