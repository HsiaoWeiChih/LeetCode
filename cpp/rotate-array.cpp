#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
           
            vector<int> back;
    
            k %= nums.size();
            
            for(int i=0; i<k; i++)
            {
                back.push_back(nums[(nums.size()-k+i)]);
            }
            
            for(int i=0; i<nums.size()-k; i++)
            {
                nums[nums.size()-1-i] = nums[nums.size()-1-i-k];
            }
            
            for(int i=0; i<k; i++)
            {
                nums[i] = back[i];
            }
        }
    };