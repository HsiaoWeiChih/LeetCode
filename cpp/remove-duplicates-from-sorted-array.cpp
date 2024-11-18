#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int leng = 1;
        int popnum = 0;
        
        if(nums.size() == 1)
        {
            leng = 1;
            return leng;
        }
        if(nums.size() == 0)
        {
            leng = 0;
            return leng;
        }
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[leng-1] == nums[i])
            {
                popnum++;
            }
            else if(nums[leng-1] != nums[i])
            {
                leng++;
                nums[leng-1] = nums[i];
            }
        }
        
        for(int i=1; i<popnum; i++)
        {
            nums.pop_back();
        }
        return leng;
    }
};