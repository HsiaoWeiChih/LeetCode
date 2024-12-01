#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
    // 沒用到
    void sortVec(vector<pair<int, int>>& v)
    {
        int size=v.size();
        for(int i=size-2; i>=0; i--)
        {
            for(int j=0; j<i+1; j++)
            {
                if(v[j].first > v[j+1].first)
                {
                    auto tmp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = tmp;
                }
            }
        }
        std::sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        });
    }

    bool checkIndex(vector<int> vIndex, int k)
    {
        if(vIndex.size() <= 1)
            return false;

        std::sort(vIndex.begin(), vIndex.end());

        bool result = false;
        for(int i=0; i<vIndex.size()-1; i++)
        {
            if(vIndex[i+1] - vIndex[i] <= k)
            {
                result = true;
                break;
            }
        }
        return result;
    }
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return false;

        map<int, vector<int>> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }

        bool result = false;
        for(auto tmp: m)
        {
            result = checkIndex(tmp.second, k);
            if(result)
                break;
        }

        return result;
    }
};

int main()
{
    Solution test;
    vector<int> v = {1,2,3,1};
    cout << (test.containsNearbyDuplicate(v, 1) ? "T" : "F");

    return 0;
}