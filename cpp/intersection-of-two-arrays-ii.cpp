#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;

        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            // result.push_back(3);
            if (nums1[i] == nums2[j])
            {
                result.push_back(nums1.at(i));
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                // result.push_back(3);
                i++;
            }
            else
            {
                j++;
            }
        }
        return result;
    }
};