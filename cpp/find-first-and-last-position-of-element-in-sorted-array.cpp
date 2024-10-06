#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        bool flag = false;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                result.push_back(i);
                flag = true;
                break;
            }
        }
        if (flag)
        {
            for (int i = nums.size()-1; i >= 0; i--)
            {
                if (nums[i] == target)
                {
                    result.push_back(i);
                    break;
                } 
            }
        }
        else
            result.insert(result.begin(), 2, -1);

        return result;
    }
};

int main()
{
    Solution test;
    vector<int> v = {5, 7, 7, 8, 8, 10};

    vector<int> v1 = test.searchRange(v, 6);
    cout << v1[0] << endl;
    cout << v1[1] << endl;

    return 0;
}