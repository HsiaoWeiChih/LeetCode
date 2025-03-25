/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void loopFindSubset(vector<vector<int>>& result, vector<int>& nums, int current, vector<int> currentNums)
    {
        if(current == nums.size()-1)
        {
            vector<int> tmp = currentNums;
            tmp.push_back(nums[current]);
            result.push_back(currentNums);
            result.push_back(tmp);
        }
        else
        {
            vector<int> tmp = currentNums;
            tmp.push_back(nums[current]);
            loopFindSubset(result, nums, current+1, tmp);
            loopFindSubset(result, nums, current+1, currentNums);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        loopFindSubset(result, nums, 0, tmp);
        return result;
    }
};
// @lc code=end

