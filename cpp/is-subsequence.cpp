#include <iostream>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if("" == s)
            return true;
        int it = 0;
        bool bFlag = false;
        bool result = false;
        for(int i=0; i<s.length(); i++)
        {
            bFlag = false;
            for(int j=it; j<t.length(); j++)
            {
                if(s[i] == t[j])
                {
                    bFlag = true;
                    it = j+1;
                    break;
                }
            }
            if(bFlag && i==s.length() - 1)
            {
                result = true;
                break;
            }
            else if(bFlag)
                continue;
            else
            {
                result = false;
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution test;
    cout << test.isSubsequence("abc", "ahbgdc");
    return 0;
}