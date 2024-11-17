#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void pickOne(vector<vector<int>> &result, vector<int> current, vector<int> restNums)
    {
        if (restNums.size() == 0)
            result.push_back(current);
        else
        {
            for (int i = 0; i < restNums.size(); i++)
            {
                vector<int> tmpNums = restNums;
                vector<int> tmpCurrent = current;
                tmpCurrent.push_back(tmpNums[i]);
                tmpNums.erase(tmpNums.begin() + i);
                pickOne(result, tmpCurrent, tmpNums);
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> tmp = nums;
            vector<int> v;
            v.push_back(tmp[i]);
            tmp.erase(tmp.begin() + i);
            vector<vector<int>> singleResult;
            pickOne(singleResult, v, tmp);
            result.insert(result.end(), singleResult.begin(), singleResult.end());
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> result = test.permute(v);
    for (int i = 0; i < result.size(); i++)
    {
        vector<int> tmp = result[i];
        for(int j=0; j<tmp.size(); j++)
        {
            cout << tmp[j] << " ";
        }
        cout << endl;
    }
    return 0;
}