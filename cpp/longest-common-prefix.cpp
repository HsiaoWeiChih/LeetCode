#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int NumStrs = strs.size();
        vector<string> prefix;
        
        if(NumStrs == 0)
        {
            return "";
        }
        else if(NumStrs == 1)
        {
            return strs[0];
        }
        else if(NumStrs > 1)
        {
            for(int i=0; i<strs[0].length(); i++)
            {
                int size = strs.size();
                for(int j=1; j<size; j++)
                {
                    if(strs[0][i] == strs[j][i])
                        continue;
                    else
                        return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};