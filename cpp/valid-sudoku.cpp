#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int row_check[9][9] = {0};
        int col_check[9][9] = {0};
        int sqr_check[9][9] = {0};
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                if(board[i][j] == '.')
                    continue;
                
                int num = 0;
                
                num = board[i][j]-'1';
                
                if(row_check[i][num] == 0)
                    row_check[i][num] = 1;
                else
                    return false;
                
                if(col_check[j][num] == 0)
                    col_check[j][num] = 1;
                else
                    return false;
                
                int sqr_num = 0;
                sqr_num = 3*(i/3) + j/3;
                
                if(sqr_check[sqr_num][num] == 0)
                    sqr_check[sqr_num][num] = 1;
                else
                    return false;
            }
        }
        return true;
        
    }
};