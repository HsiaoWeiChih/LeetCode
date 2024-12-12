#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    void sortVec(vector<vector<int>>& v)
    {
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b)
             { return a[0] < b[0]; });
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sortVec(intervals);

        vector<vector<int>> result;
        int iSize = intervals.size();
        int start = 0;
        int end = 0;

        int endNum = 0;
        while(start < iSize)
        {
            // 下一號需 merge
            endNum = intervals[start][1];
            while(end < iSize-1 && endNum >= intervals[end+1][0])
            {
                endNum = endNum > intervals[end+1][1] ? endNum : intervals[end+1][1];
                end++;
            }
            cout << "start = " << start << endl;
            cout << "end = " << end << endl;
            vector<int> tmp = {intervals[start][0], endNum};
            result.push_back(tmp);

            start = end+1;
            end = start;
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> v = {{1,10},{2,3},{4,5},{6,7},{8,9}};

    Solution test;
    auto vv = test.merge(v);

    for(int i=0; i<v.size(); i++)
    {
        cout << vv[i][0] << " " << vv[i][1] << endl;
    }

    return 0;
}