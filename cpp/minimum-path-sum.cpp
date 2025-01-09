#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0)
                {
                    if(j==0)
                        dp[i][j] = grid[i][j];
                    else
                    {
                        dp[i][j] = dp[i][j-1] + grid[i][j];
                    }
                }
                else
                {
                    if(j==0)
                        dp[i][j] = dp[i-1][j] + grid[i][j];
                    else
                    {
                        dp[i][j] = (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + grid[i][j];
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main()
{
    vector<vector<int>> v = {{1,2},{5,6},{1,1}};
    Solution test;
    cout << "test = " << test.minPathSum(v) << endl;

    return 0;
}