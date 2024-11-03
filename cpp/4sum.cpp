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

    vector<vector<int>> threeSum(vector<int>& nums, int target, int vi) {
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
            long long targetNum = (long long)target - (long long)vSort[i];
            while(j<k)
            {
                if(vSort[j] + vSort[k] == targetNum)
                {
                    vector<int> tmp = {vi, vSort[i], vSort[j], vSort[k]};
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
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> vSort = sortVec(nums);
        int iSize = vSort.size();
        vector<vector<int>> result;
        for(int i=0; i<iSize-3; i++)
        {
            if(i>0)
            {
                while(i<iSize-3 && vSort[i] == vSort[i-1])
                {
                    i++;
                }
                if(i >= iSize-3)
                    break;
            }
            
            vector<int> tmp = vector<int>(vSort.begin()+i+1, vSort.end());
            vector<vector<int>> tmpResult = threeSum(tmp, target - vSort[i], vSort[i]);
            result.insert(result.begin(), tmpResult.begin(), tmpResult.end());
        }

        return result;
    }
};

int main()
{
    vector<int> v = {1000000000,1000000000,1000000000,1000000000};
    Solution solu;
    vector<vector<int>> test = solu.fourSum(v, 0);
    for(int i=0; i<test.size(); i++)
    {
        for(int j=0; j<test[i].size(); j++)
        {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}