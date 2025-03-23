#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
    
            
            set<int> mySet;
            int total = 0;
            for(int i=0; i<nums.size(); i++)
            {
                if(mySet.count(nums[i]) == 0)
                {
                    mySet.insert(nums[i]);
                    total += nums[i];
                }
                    
            }
            
            total *= 2;
            
            for(int i=0; i<nums.size(); i++)
            {
                total -= nums[i];
            }

            return total;
            
        }
    };