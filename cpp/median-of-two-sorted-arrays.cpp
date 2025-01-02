#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 + size2 == 1)
        {
            return size1 > 0 ? nums1[0] : nums2[0];
        }
        bool bOdd = (size1 + size2) % 2 == 1;

        double result;
        if(bOdd)
        {
            int index1 = 0;
            int index2 = 0;
            vector<int> tmp;
            while((index1 + index2 + 1) < (size1+ size2 + 1)/2)
            {
                if(index1 >= size1)
                {
                    tmp.push_back(nums2[index2]);
                    index2++;
                }  
                else if(index2 >= size2)
                {
                    tmp.push_back(nums1[index1]);
                    index1++;
                }
                else if(nums1[index1] < nums2[index2])
                {
                    tmp.push_back(nums1[index1]);
                    index1++;
                }
                else
                {
                    tmp.push_back(nums2[index2]);
                    index2++;
                }
            }

            result = tmp[(size1+size2)/2];
        }
        else
        {
            int index1 = 0;
            int index2 = 0;
            vector<int> tmp;
            while(index1 < size1 || index2 < size2)
            {
                if(index1 >= size1)
                {
                    tmp.push_back(nums2[index2]);
                    index2++;
                }
                else if(index2 >= size2)
                {
                    tmp.push_back(nums1[index1]);
                    index1++;
                }
                else if(nums1[index1] < nums2[index2])
                {
                    tmp.push_back(nums1[index1]);
                    index1++;
                }
                else
                {
                    tmp.push_back(nums2[index2]);
                    index2++;
                }
            }
            result = (tmp[(size1+size2)/2] + tmp[(size1+size2)/2 - 1])/2.0;
        }
        return result;
    }
};

int main()
{
    vector<int> v1 = {1,2};
    vector<int> v2 = {3,4,5,6,7,8};
    Solution test;
    cout << "test = " << test.findMedianSortedArrays(v1, v2) << endl;

    return 0;
}