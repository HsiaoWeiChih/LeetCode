#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // 例如 aa a*
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // dp[i][j-2] -> 代表0個 ; 剩下為 1個~n個
                    // 1個~n個: 判斷 s的i-1和p的j 匹配的時候，s的第i個字母需和p的*前的字母相同(或.)
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main()
{
    Solution test;
    cout <<  (test.isMatch("aa", "a*") ? "T" : "F");
}