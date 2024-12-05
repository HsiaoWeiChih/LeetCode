#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int val_size = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == val)
            {
                val_size++;
            }
        }
        
        int temp;
        int flag = nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[flag];
                nums[flag] = val;
                flag--;
            }
        }
        
        return nums.size()-val_size;
    }
};

int main()
{
    Solution test;

    return 0;
}