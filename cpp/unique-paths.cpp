#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // C(m-1+n-1, n-1) C m+n-2 取 n-1
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};

int main()
{
    Solution test;
    cout << "test = " << test.uniquePaths(3, 7) << endl;

    return 0;
}