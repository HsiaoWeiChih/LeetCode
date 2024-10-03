#include <iostream>
#include <vector>
#include <algorithm> // 用於 std::sort

using namespace std;

class Solution
{
private:
    int findTheSmallestOfLargerNum(int pos, vector<int> &nums)
    {
        int result = -1; // no number can find
        for (int i = pos + 1; i < nums.size(); i++)
        {
            if (result != -1)
            {
                if (nums[result] > nums[i] && nums[pos] < nums[i])
                    result = i;
            }
            else
            {
                if (nums[pos] < nums[i])
                    result = i;
            }
        }
        return result;
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        int pos = nums.size() - 2;
        int largerPos = -1;
        int switchPos = -1;

        // 從最後開始找到一個數字，符合後面的數字比該數字大，而且是比該數字大當中最小的
        for (int i = pos; i >= 0; i--)
        {
            largerPos = findTheSmallestOfLargerNum(i, nums);
            if (largerPos != -1)
            {
                switchPos = i;
                break;
            }
        }

        if (switchPos == -1) // 該排列已經是最後一個
        {
            std::sort(nums.begin(), nums.end());
        }
        else
        {
            int temp = nums[switchPos];
            nums[switchPos] = nums[largerPos];
            nums[largerPos] = temp;
            std::sort(nums.begin() + switchPos + 1, nums.end());
        }
    }

    void printVec(vector<int> vec)
    {
        // 輸出排序後的結果
        for (int num : vec)
        {
            std::cout << num << " ";
        }
    }
};

int main()
{
    std::vector<int> vec = {2, 3, 1};
    Solution test;
    test.nextPermutation(vec);
    test.printVec(vec);

    return 0;
}