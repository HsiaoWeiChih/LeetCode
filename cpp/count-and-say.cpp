#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        
        string oldstr = "1";
        string newstr;
        int num = 0;
        
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<oldstr.length(); j++)
            {
                if(oldstr[j] != oldstr[j+1])
                {
                    num++;
                    string s = to_string(num);
                    newstr = newstr + s + oldstr[j];
                    num = 0;
                }
                else
                {
                    num++;
                }
                
                
            }
            num = 0;
            oldstr = newstr;
            newstr = "";
        }
        
        return oldstr;
    }
};