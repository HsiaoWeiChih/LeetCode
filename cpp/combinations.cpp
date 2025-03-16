#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void chooseOne(vector<vector<int>> &result, const int &n, const int &k, int currentMax, vector<int> current)
    {
        if (current.size() == k)
            result.push_back(current);
        else
        {
            for (int i = currentMax + 1; i <= n; i++)
            {
                vector<int> tmp = current;
                tmp.push_back(i);
                chooseOne(result, n, k, i, tmp);
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        for(int i=1; i<=n; i++)
        {
            vector<int> tmp;
            tmp.push_back(i);
            chooseOne(result, n, k, i, tmp);
        }
        return result;
    }
};
