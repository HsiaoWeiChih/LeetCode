#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
            
        vector<vector<long long>> dp(m, std::vector<long long>(n));

        // 邊邊 往下
        for(int i=0; i<m; i++)
        {
            if(i==0)
                dp[i][0] = 1;
            else
            {
                dp[i][0] = obstacleGrid[i][0] != 1 ? dp[i-1][0] : 0;
            }
        }
         // 邊邊 往右
        for(int j=0; j<n; j++)
        {
            if(j==0)
                dp[0][j] = 1;
            else
            {
                dp[0][j] = obstacleGrid[0][j] != 1 ? dp[0][j-1] : 0;
            }
        }

        // 中間
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                dp[i][j] = obstacleGrid[i][j] != 1 ? dp[i-1][j] + dp[i][j-1] : 0;
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    vector<vector<int>> v = {{0,1,0}, {0,1,0}, {0,0,0}};
    Solution test;
    cout << "test = " << test.uniquePathsWithObstacles(v) << endl;

    return 0;
}