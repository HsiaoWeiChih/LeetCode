#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> result;
        while (true)
        {
            if (numbers[left] + numbers[right] == target)
            {
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }
            else if(numbers[left] + numbers[right] < target)
                left++;
            else
                right--;
        }
        return result;

        // over time limit
        // vector<int> result;
        // for(int i=0; i<numbers.size(); i++)
        // {
        //     for(int j=i+1; j<numbers.size(); j++)
        //     {
        //         if(numbers[i] + numbers[j] > target)
        //             break;
        //         else
        //         {
        //             if(numbers[i] + numbers[j] == target)
        //             {
        //                 result.push_back(i+1);
        //                 result.push_back(j+1);
        //                 break;
        //             }
        //         }
        //     }
        //     if(result.size() > 0)
        //         break;
        // }
        // return result;
    }
};