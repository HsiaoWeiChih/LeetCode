#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    enum direction {
        right, down, left, up 
    };
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        direction nowDir = direction(right);
        pair<int, int> p(0, -1);
        for(int i=1; i<=n*n; i++)
        {            
            if(nowDir == direction::right) // 這一輪是向右
            {
                p.second++;
                // 判斷下一輪的方向
                if(p.second+1 <= n-1 && matrix[p.first][p.second+1] == 0)
                    nowDir = direction::right;
                else
                    nowDir = direction::down;
            } 
            else if(nowDir == direction::down)
            {
                p.first++;
                // 判斷下一輪的方向
                if(p.first+1 <= n-1 && matrix[p.first+1][p.second] == 0)
                    nowDir = direction::down;
                else
                    nowDir = direction::left;
            }
            else if(nowDir == direction::left)
            {
                p.second--;
                // 判斷下一輪的方向
                if(p.second-1 >= 0 && matrix[p.first][p.second-1] == 0)
                    nowDir = direction::left;
                else
                    nowDir = direction::up;
            }
            else
            {
                p.first--;
                // 判斷下一輪的方向
                if(p.first-1 >= 0 && matrix[p.first-1][p.second] == 0)
                    nowDir = direction::up;
                else
                    nowDir = direction::right;
            }

            cout << "p.first = " << p.first << endl;
            cout << "p.second = " << p.second << endl;
            cout << "i = " << i << endl;
            matrix[p.first][p.second] = i;
        }
        return matrix;
    }
};

int main()
{
    Solution test;
    auto v = test.generateMatrix(3);
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}