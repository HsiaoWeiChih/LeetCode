#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    enum direction {
        right, down, left, up 
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();     
        direction nowDir = direction(right);
        vector<int> result;
        pair<int, int> leftUp(0, 0);
        pair<int, int> rightDown(m-1, n-1);
        while(leftUp.first <= rightDown.first && leftUp.second <= rightDown.second)
        {
            if(nowDir == right)
            {
                result.insert(result.end(), matrix[leftUp.second].begin() + leftUp.first, matrix[leftUp.second].begin() + rightDown.first + 1);
                nowDir = down;
                leftUp.second++;
            }
            else if(nowDir == down)
            {
                for(int i=leftUp.second; i<=rightDown.second; i++)
                {
                    result.push_back(matrix[i][rightDown.first]);
                }
                nowDir = left;
                rightDown.first--;
            }
            else if(nowDir == left)
            {
                // for(int i=rightDown.first; i>=leftUp.first; i--)
                // {
                //     result.push_back(matrix[rightDown.second][i]);
                // }
                result.insert(result.end(), 
                    matrix[rightDown.second].rbegin() + (matrix[rightDown.second].size() - 1 - rightDown.first),
                    matrix[rightDown.second].rbegin() + (matrix[rightDown.second].size() - leftUp.first));
                nowDir = up;
                rightDown.second--;
            }
            else if(nowDir == up)
            {
                for(int i=rightDown.second; i>=leftUp.second; i--)
                {
                    result.push_back(matrix[i][leftUp.first]);
                }
                nowDir = right;
                leftUp.first++;
            }
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<vector<int>> v;
    // vector<int> v1 = {1,2,3,4,5};
    // vector<int> v2 = {6,7,8,9,10};
    // vector<int> v3 = {11,12,13,14,15};
    // vector<int> v4 = {16,17,18,19,20};
    // vector<int> v5 = {21,22,23,24,25};

    // (0, 0) ... (m-1, 0)   
    // ................
    // ................
    //(0, n-1) ... (m-1, n-1)


    vector<int> v1 = {1,2,3,4};
    vector<int> v2 = {5,6,7,8};
    vector<int> v3 = {9,10,11,12};
     v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    // v.push_back(v4);
    // v.push_back(v5);
    auto result = test.spiralOrder(v);

    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}