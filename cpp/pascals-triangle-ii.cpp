#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex == 0)
            result.push_back(1);
        else if(rowIndex == 1)
        {
            result.insert(result.begin(), 2, 1);
        }
        else
        {
            vector<int> tmp = getRow(rowIndex - 1);
            for(int i=0; i<=tmp.size(); i++)
            {
                if(i==0 || i==tmp.size())
                    result.push_back(1);
                else
                    result.push_back(tmp[i-1] + tmp[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution test;
    test.getRow(3);

    return 0;
}