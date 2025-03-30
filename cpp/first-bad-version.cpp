#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
private:
    bool isBadVersion(int n)
    {
        return true;
    }
public:
    int firstBadVersion(int n)
    {
        int start = 0; // -> false
        int end = n;   // -> true
        if (n == 1 && isBadVersion(n))
            return n;
        else
        {
            while (end - start > 1)
            {
                int mid = std::floor((end - start) / 2.0) + start;
                bool res = isBadVersion(mid);
                if (res)
                    end = mid;
                else
                    start = mid;
            }
        }
        return end;
    }
};