#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        bool bResult = false;
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            if(bResult)
                break;
            if (matrix[i][0] == target)
            {
                bResult = true;
                break;
            }
            else if (matrix[i][0] < target)
            {
                for (int j = 1; j < matrix[0].size(); j++)
                {
                    if(matrix[i][j] == target)
                    {
                        bResult = true;
                        break;
                    }
                }
            }
            else
                continue;
        }
        return bResult;
    }
};