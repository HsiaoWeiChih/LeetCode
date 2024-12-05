#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        bool ans = false;
        int flag = -1;
    
        if(needle.length() == 0)
            return 0;
        
        if(needle.length() > haystack.length())
            return -1;
        
        int j=0;
        
        int iter = haystack.length() - needle.length();
        
        for(int i=0; i<=iter; i++)
        {
            
            if(haystack[i] == needle[j])
            {
                int ii = i;
                int jj = j;
                while(haystack[ii] == needle[jj])
                {
                    if(jj == needle.length()-1)
                    {
                        ans = true;
                        flag = i;
                        break;
                    }
                    ii++;
                    jj++;
                }
            }
            if(ans == true)
                break;
        }
        
        if(ans == true)
        {
            return flag;
        }
        else
        {
            return -1;
        }
        
    }
};

int main()
{
    Solution test;

    return 0;
}