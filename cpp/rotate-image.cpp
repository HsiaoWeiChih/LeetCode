#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        
        std::vector<int> tmp;

        for(int i=0; i<floor(n/2.0); i++) // 由外而內總共幾圈
        {
            cout << "i = " << i << endl;
            int num = n-(2*i); // 該圈有 n-(2*i) 個數字
            
            for(int k=0; k<num-1; k++)
            {
                cout << "=====================" << endl;
                int t = matrix[i][i+k]; // 上面存到 t
                cout << "上: " << matrix[i][i+k] << endl;
                
                matrix[i][i+k] = matrix[n-1-i-k][i]; // 左 -> 上
                cout << "左: " << matrix[n-1-i-k][i] << endl;
                
                matrix[n-1-i-k][i] = matrix[n-1-i][n-1-i-k]; // 下 -> 左
                cout << "下: " << matrix[n-1-i][n-1-i-k] << endl;
                
                matrix[n-1-i][n-1-i-k] = matrix[i+k][n-1-i]; // 右 -> 下
                cout << "右: " << matrix[i+k][n-1-i] << endl;
                cout << "=====================" << endl;
                
                matrix[i+k][n-1-i] = t; // 上 -> 右
                
            }
        }
    }
};