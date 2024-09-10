#include <iostream>

using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        int restNum = columnNumber;
        string result = "";
        while (restNum > 0)
        {
            int tmp = restNum % 26;
            if (tmp == 0)
            {
                result.insert(0, 1, 'Z');
                restNum -= 26;
            }
            else
            {
                char c = 'A' + tmp - 1;
                result.insert(0, 1, c);
                restNum -= tmp;
            }
            restNum = restNum / 26;
        }
        return result;
    }
};

int main()
{
    Solution test;

    cout << test.convertToTitle(701) << endl;

    return 0;
}