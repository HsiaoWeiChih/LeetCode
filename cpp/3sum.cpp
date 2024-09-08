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
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> vSort = sortVec(nums);
        int iSize = vSort.size();
        vector<vector<int>> result;
        for(int i=0; i<iSize-2; i++)
        {
            if(i>0)
            {
                while(i<iSize-2 && vSort[i] == vSort[i-1])
                {
                    i++;
                }
                if(i >= iSize-2)
                    break;
            }
            int j = i+1;
            int k = iSize-1;
            int targetNum = 0 - vSort[i];
            if(targetNum < 0)
                break;
            while(j<k)
            {
                if(vSort[j] + vSort[k] == targetNum)
                {
                    vector<int> tmp = {vSort[i], vSort[j], vSort[k]};
                    result.push_back(tmp);
                    j++;
                    k--;
                    while(vSort[j] == vSort[j-1])
                    {
                        j++;
                        if(j>=k)
                            break;
                    }
                    while(vSort[k] == vSort[k+1])
                    {
                        k--;
                        if(k<=j)
                            break;
                    }
                }
                else
                {
                    if(vSort[j] + vSort[k] > targetNum)
                    {
                        k--;
                        while(vSort[k] == vSort[k+1])
                        {
                            k--;
                            if(k<=j)
                                break;
                        }
                    }
                    else
                    {
                        j++;
                        while(vSort[j] == vSort[j-1])
                        {
                            j++;
                            if(j>=k)
                                break;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> v = {1,-1,-1,0};
    Solution solu;
    solu.threeSum(v);

    return 0;
}