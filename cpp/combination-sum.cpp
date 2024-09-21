#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> combinationRest(vector<int> candidates, vector<int> accumulation, int target, int index)
    {
        vector<vector<int>> result;
        for (; index < candidates.size(); index++)
        {
            if (candidates[index] == target)
            {
                vector<int> tmp = accumulation;
                tmp.push_back(candidates[index]);
                result.push_back(tmp);
            }
            else if (candidates[index] < target)
            {
                vector<int> tmp = accumulation;
                tmp.push_back(candidates[index]);
                vector<vector<int>> tmpResult = combinationRest(candidates, tmp, target - candidates[index], index);
                if(tmpResult.size() > 0)
                    result.insert(result.end(), tmpResult.begin(), tmpResult.end());
            }
        }
        return result;
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        
        if (target == 0)
            return result;
        else
        {
            vector<int> tmp;
            result = combinationRest(candidates, tmp, target, 0);
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<int> tmp = {2, 3, 6, 7};
    vector<vector<int>> result = test.combinationSum(tmp, 7);

    for(int i=0; i<result.size(); i++)
    {
        vector<int> iter = result[i];
        for(int j=0; j<iter.size(); j++)
        {
            cout << iter[j] << " ";
        }
        cout << endl << "======================" << endl;
    }
}