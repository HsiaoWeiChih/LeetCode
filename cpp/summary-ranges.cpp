#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    string transString(int start, int end)
    {
        if(start == end)
            return to_string(start);
        else
            return to_string(start) + "->" + to_string(end);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        int iStartIndex = -1;
        int iEndIndex = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(iStartIndex == -1)
                iStartIndex = i;
            
            if(i==nums.size()-1)
            {
                iEndIndex = i;
                result.push_back(transString(nums[iStartIndex], nums[iEndIndex]));
            }
            else if(i<nums.size()-1 && nums[i+1] == nums[i]+1)
                continue;
            else if(i<nums.size()-1 && nums[i+1] != nums[i]+1)
            {
                result.push_back(transString(nums[iStartIndex], nums[i]));
                iStartIndex = -1;
            }
        }
        return result;
    }
};