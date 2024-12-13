#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int flag;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(target == nums[i])
            {
                flag = i;
                goto here;
            }
            else if(target < nums[i])
            {
                flag = i;
                goto here;
            }
        }
        
        flag = nums.size();
        
        here:
        return flag;
    }
};