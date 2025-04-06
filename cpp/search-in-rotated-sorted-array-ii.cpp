#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int right = nums.size() - 1;
        int left = 0;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;

            if(nums[mid] == target)
                return true;

            if(nums[left] == nums[mid])
            {
                left++;
                continue;
            }
            
            if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && target < nums[mid])
                {
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[right]) 
                {
                    left = mid + 1;
                } 
                else 
                {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution test;
    vector<int> v = {1,0,1,1,1};
    cout << (test.search(v, 0) ? "T" : "F") << endl;

    return 0;
}