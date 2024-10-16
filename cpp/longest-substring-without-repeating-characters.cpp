#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int longsub = 1;
        int sub1 = 1;
        int sub2 = 1;
        
        if(s.length() == 0)
            return 0;
        
        
        for(int i=1; i<s.length(); i++)
        {
            for(int j=i-1; j>=i-sub1; j--)
            {
                if(s[i] != s[j] && j == i-sub1)
                {
                    sub2++;
                    longsub = (sub2 > longsub) ? sub2 : longsub;
                    //swap(sub1, sub2);
                    sub1 = sub2;
                    sub2 = 1;
                    break;
                }
                else if(s[i] != s[j])
                {
                    sub2++;
                    longsub = (sub2 > longsub) ? sub2 : longsub;
                }
                else if(s[i] == s[j])
                {
                    //swap(sub1, sub2);
                    sub1 = sub2;
                    sub2 = 1;
                    break;
                    
                }
                
            }
            
        }
        return longsub;
    }
};

int main()
{
    Solution test;
    return 0;
}