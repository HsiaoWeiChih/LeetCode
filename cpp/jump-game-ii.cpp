#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
private:
    int minJump(int index, int length, vector<int>* v)
    {
        if (index + length >= v->size() - 1)
            return 1;
        else
        {
            int minJump = 0; // 0代表跳不過去
            for (int i = index + 1; i <= index + length && i < v->size() - 1; i++)
            {
                if ((*v)[i] >= 1)
                    minJump = (minJump > 0) ? min(minJump, (*v)[i] + 1) : (*v)[i] + 1;
            }
            return minJump;
        }
    }

public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        else
        {
            int index = nums.size() - 1;
            vector<int> vec(nums.size());
            for (int i = index - 1; i >= 0; i--)
            {
                cout << "i = " << i << endl;
                if (nums[i] == 0)
                    vec[i] = 0;
                else
                    vec[i] = minJump(i, nums[i], &vec);
            }
            cout << "vec[1] = " << vec[1] << endl;
            return vec[0];
        }
    }
};

int main()
{
    Solution test;
    vector<int> v = {1, 2, 3};
    cout << test.jump(v) << endl;

    return 0;
}