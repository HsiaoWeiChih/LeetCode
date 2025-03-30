#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int temp;
        int end = nums.size() - 1;
        for (int i = 0; i <= end; i++)
        {
            if (i >= 1)
            {
                if (nums[i - 1] == 0)
                    i--;
            }

            if (nums[i] != 0)
            {
                continue;
            }
            for (int j = i; j < end; j++)
            {
                swap(nums[j], nums[j + 1]);
            }
            end--;
        }
    }
};