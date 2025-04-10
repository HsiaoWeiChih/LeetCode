#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int result = 0;
        sort(citations.begin(), citations.end());
        int iSize = citations.size();
        int cnt = 0;
        for(int i=iSize-1; i>=0; i--)
        {
            cnt++;
            result = max(min(cnt, citations[i]), result);
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<int> v = {3,0,6,1,5};
    test.hIndex(v);
    return 0;
}