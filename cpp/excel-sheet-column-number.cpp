#include <iostream>
#include <cmath>

using namespace std;

class Solution {
private:
    int charToNumber(char c)
    {
        return c - 'A' + 1;
    }
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();
        int digit = size - 1;
        int result = 0;
        for(int i=0; i<size; i++)
        {
            if(i != size - 1)
            {
                int num = charToNumber(columnTitle[i]);
                result += num * pow(26, digit);
            }
            else
            {
                result += charToNumber(columnTitle[i]);
            }
            digit--;
        }
        return result;
    }
};

int main()
{
    Solution test;
    cout << test.titleToNumber("AB");
    
    return 0;
}