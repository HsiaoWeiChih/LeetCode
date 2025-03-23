#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int mm = m;
        int nn = n;

        for (int i = m + n - 1; i >= 0; i--)
        {
            if (nn == 0)
                break;
            if (mm == 0)
            {
                nums1[i] = nums2[nn - 1];
                nn--;
            }
            if (mm != 0 && nn != 0)
            {
                if (nums1[mm - 1] <= nums2[nn - 1])
                {
                    nums1[i] = nums2[nn - 1];
                    nn--;
                }
                else
                {
                    nums1[i] = nums1[mm - 1];
                    mm--;
                }
            }
        }
    }
};