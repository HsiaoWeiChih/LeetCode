#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // 記錄所有
        set<int> colZero;
        set<int> rowZero;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    colZero.emplace(i);
                    rowZero.emplace(j);
                }
            }
        }
        // 設為0
        for(auto iter: colZero)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                matrix[iter][j] = 0;
            }
        }
        for(auto iter: rowZero)
        {
            for(int i=0; i<matrix.size(); i++)
            {
                matrix[i][iter] = 0;
            }
        }
    }
};
