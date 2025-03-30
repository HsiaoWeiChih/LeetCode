#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int arr[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            arr[(int)s[i] - 97]++;
        }

        int index = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (arr[(int)s[i] - 97] == 1)
            {
                index = i;
                break;
            }
        }

        return index;
    }
};