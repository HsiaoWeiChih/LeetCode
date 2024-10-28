#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> sortVec(vector<int> v)
    {
        int vSize = v.size();
        int temp;
        for (int i = 0; i < vSize - 1; i++)
        {
            for (int j = i + 1; j < vSize; j++)
            {
                if (v[i] > v[j])
                {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
        return v;
    }

    void comVec(vector<vector<int>>& result, vector<int> &candidates, vector<int> curr, int currIndex, int total, int target)
    {
        if (total == target)
            result.push_back(curr);
        else if(total < target)
        {
            for (int i = currIndex; i < candidates.size(); i++)
            {
                if (i > currIndex && candidates[i] == candidates[i - 1])
                    continue;
                curr.push_back(candidates[i]);
                comVec(result, candidates, curr, i + 1, total + candidates[i], target);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> sortV = sortVec(candidates);
        vector<int> v;
        vector<vector<int>> result;
        comVec(result, sortV, v, 0, 0, target);
        return result;
    }
};

int main()
{
    vector<int> v = {10,1,2,7,6,1,5};
    Solution test;
    auto result = test.combinationSum2(v, 8);

    for(int i=0; i<result.size(); i++)
    {
        vector<int> temp = result[i];
        for(int j=0; j<temp.size(); j++)
        {
            cout << temp[j] << " ";
        }
        cout << endl;
    }

    return 0;
}