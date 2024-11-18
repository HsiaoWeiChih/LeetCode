#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> sortV(vector<int> v)
    {
        int size = v.size();
        for(int i=size-1; i>0; i--)
        {
            for(int j=0; j<=i-1; j++)
            {
                if(v[j] > v[j+1])
                {
                    int tmp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = tmp;
                }
            }
        }
        return v;
    }

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
                if(i>0 && tmpNums[i-1] == tmpNums[i])
                    continue;

                tmpCurrent.push_back(tmpNums[i]);
                tmpNums.erase(tmpNums.begin() + i);
                pickOne(result, tmpCurrent, tmpNums);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<int> sortedNums = sortV(nums);
        vector<vector<int>> result;
        for (int i = 0; i < sortedNums.size(); i++)
        {
            vector<int> tmp = sortedNums;
            vector<int> v;
            if(i>0 && tmp[i-1] == tmp[i])
                continue;
            
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
    vector<int> v = {3, 3, 0, 3};
    vector<vector<int>> result = test.permuteUnique(v);
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