#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int endIndex = nums.size() - 1;
        int startIndex = 0;
        int midIndex = 0;
        // find pivot
        if (nums[startIndex] < nums[endIndex])
        {
            // 無旋轉
        }
        else
        {
            while (startIndex < endIndex)
            {
                midIndex = (endIndex + startIndex) / 2;
                if (nums[midIndex] > nums[endIndex])
                {
                    startIndex = midIndex + 1;
                }
                else if (nums[midIndex] < nums[endIndex])
                {
                    endIndex = midIndex;
                }
            }
        }

        int pivot = startIndex;
        cout << "pivot = " << pivot << endl;

        vector<int> v;
        v.insert(v.begin(), nums.begin() + pivot, nums.end());
        v.insert(v.end(), nums.begin(), nums.begin() + pivot);

        for(int i=0;i<v.size(); i++)
        {
            cout << v[i] << endl;
        }

        // binary search
        startIndex = 0;
        endIndex = nums.size() - 1;
        while (startIndex <= endIndex)
        {
            int midIndex = startIndex + (endIndex - startIndex) / 2;
            int realMid = (midIndex + pivot) % nums.size();

            if (nums[realMid] == target)
            {
                return realMid;
            }
            else if (nums[realMid] < target)
            {
                startIndex = midIndex + 1;
            }
            else
            {
                endIndex = midIndex - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution test;
    vector<int> v = {3,1};
    test.search(v, 3);

    return 0;
}