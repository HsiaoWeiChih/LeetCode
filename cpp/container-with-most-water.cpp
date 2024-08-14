#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water = 0;
        while (i < j)
        {
            water = max(water, min(height[i], height[j])* (j-i));
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        return water;
    }
};

int main()
{
    Solution test;
    int arr[] = {1,8,6,2,5,4,8,3,7};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    cout << test.maxArea(vec) << endl;
    return 0;
}