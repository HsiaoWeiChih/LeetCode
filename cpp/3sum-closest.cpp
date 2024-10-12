#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> sortVec(vector<int> nums)
    {
        int vSize = nums.size();
        for(int i=vSize-1; i>0; i--)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    int tmp = nums[j+1];
                    nums[j+1]= nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return nums;
    }

    unsigned int distance(long long x, long long y)
    {
        if(x > y)
            return x-y;
        else
            return y-x;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> vSort = sortVec(nums);
        int size = vSort.size();
        int result = INT_MAX;
        bool bFindEqual = false;
        for(int i=0; i<size-2; i++)
        {
            int j = i+1;
            int k = size-1;
            int restTarget = target - vSort[i];
            while(j<k)
            {
                if(vSort[j] + vSort[k] == restTarget)
                {
                    result = target;
                    bFindEqual = true;
                    break;
                }
                else if(vSort[j] + vSort[k] > restTarget)
                {
                    if(distance(target, result) > distance(target, vSort[i] + vSort[j] + vSort[k]))
                        result = vSort[i] + vSort[j] + vSort[k];
                    
                    k--;
                }
                else
                {
                    if(distance(target, result) > distance(target, vSort[i] + vSort[j] + vSort[k]))
                        result = vSort[i] + vSort[j] + vSort[k];
                    
                    j++;
                }
            }

            if(bFindEqual)
                break;
        }
        return result;
    }
};

int main()
{
    vector<int> v = {1, 1, 1, 1};
    Solution test;
    cout << test.threeSumClosest(v, -100);
    return 0;
}