#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> result;
            
            vector<int> row1;
            row1.push_back(1);
            
            result.push_back(row1);
            
            if(numRows > 1)
            {
                for(int i=1; i<numRows; i++) 
                {
                    result.push_back(getNextRow(result[i-1]));
                }
            }
            return result;
        }
        vector<int> getNextRow(vector<int> nums) {
            vector<int> result;
            result.push_back(nums.at(0));
            int size = nums.size();
            if(size > 1) {
                for(int i=1; i<size; i++) {
                    result.push_back(nums[i-1] + nums[i]);
                }
            }
            result.push_back(nums[size-1]);
            return result;
        }
    };