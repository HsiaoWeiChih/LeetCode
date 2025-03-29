#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        bool result = false;
        int limitX = board.size() - 1;
        int limitY = board[0].size() - 1;

        function<bool(int, int, int)> nextChar = [&](int x, int y, int current)
        {
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
            cout << "current = " << current << endl;
            if(current == word.size())
                return true;
            
            if(x < 0 || x > limitX || y < 0 || y > limitY || board[x][y] != word[current])
                return false;

            char tmp = board[x][y];
            board[x][y] = '\0';

            if(nextChar(x+1, y, current+1) || nextChar(x-1, y, current+1)
                || nextChar(x, y+1, current+1) || nextChar(x, y-1, current+1))
                return true;

            board[x][y] = tmp;
            return false;
        };

        for(int i=0; i<=limitX; i++)
            for(int j=0; j<=limitY; j++)
                if(nextChar(i, j, 0))
                    return true;

        return false;
    }
};

int main()
{
    std::vector<std::vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    Solution test;
    cout << (test.exist(board, "SEE") ? "T" : "F");

    return 0;
}