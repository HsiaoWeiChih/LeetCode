#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0;
        int mid = 0;
        int right = nums.size()-1;
        while(mid <= right)
        {
            if(nums[mid] == 0)
            {
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            { // 2
                swap(nums[right], nums[mid]);
                right--;
            }
        }
    }
};

int main()
{
    Solution test;
    vector<int> v = {1, 0, 2, 1};
    test.sortColors(v);
    for(auto iter : v)
    {
        cout << iter << " ";
    }
    return 0;
}