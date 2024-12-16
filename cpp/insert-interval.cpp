#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void sortVec(vector<vector<int>>& v)
    {
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b)
             { return a[0] < b[0]; });
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

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
    vector<vector<int>> v1 = {{1,3},{6,9}};
    vector<int> v2 = {2,5};

    Solution test;
    auto result = test.insert(v1, v2);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }

    return 0;
}