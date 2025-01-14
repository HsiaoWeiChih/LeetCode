#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        int sum = 0;
        int maxsum = INT_MIN;
        
        for(int i=0; i<size; i++)
        {
            if(nums[i] > 0)
            {
                sum += nums[i];
            }
            else if(nums[i] < 0)
            {
                sum += nums[i];
            }
            
            if(maxsum<sum)
            {
                maxsum = sum;
            }
            if(sum<0)
                sum = 0;
            
        }
        return maxsum;
    }
};