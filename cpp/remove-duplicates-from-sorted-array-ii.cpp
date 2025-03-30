#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int iSize = nums.size();
        int tmp = nums[0];
        int cnt = 1;
        vector<int> newNums;
        newNums.push_back(tmp);
        for(int i=1; i<iSize; i++)
        {
            if(tmp == nums[i] && cnt < 2)
            {
                newNums.push_back(tmp);
                cnt++;
            }
            else if(tmp == nums[i]) // 超過2個數字
            {
                cnt++;
            }
            else // 換新的數字
            {
                tmp = nums[i];
                cnt = 1;
                newNums.push_back(tmp);
            }
        }
        nums = newNums;
        return newNums.size();
    }
};