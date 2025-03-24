#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int total = 0;
        /*std::stringstream ss;
        std::string ret;
        ss << n;
        ss >> ret;*/

        // string s = n.to_string();
        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
                total++;
            n >>= 1;
        }
        return total;
    }
};