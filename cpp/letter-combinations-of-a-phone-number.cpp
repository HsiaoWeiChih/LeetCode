#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    const vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string &digits, vector<string> &combinations, string current, int index)
    {
        if (index == digits.size())
        {
            combinations.push_back(current);
            return;
        }

        // 取得對應的字母組合
        string letters = phone[digits[index] - '2']; // 將 '2'-'9' 轉成 0-7 的索引
        for (char letter : letters)
        {
            backtrack(digits, combinations, current + letter, index + 1);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> vecResult;
        if (digits.empty())
            return vecResult;

        backtrack(digits, vecResult, "", 0);
        return vecResult;
    }
};

int main()
{
    Solution test;
    vector<string> tmp = test.letterCombinations("23");

    for (int i = 0; i < tmp.size(); i++)
    {
        cout << tmp[i] << endl;
    }

    return 0;
}