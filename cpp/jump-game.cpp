#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
    // 版本一 : 超出 time limit 從第一項開始遞迴找出最後一個值
    // private:
    //     void jump(vector<int>& nums, int index, bool& flag)
    //     {
    //         if(index == nums.size()-1)
    //             flag = true;

    //         if(!flag)
    //         {
    //             for(int i=index+1; i<nums.size() && i<=index+nums[index]; i++)
    //                 jump(nums, i, flag);
    //         }
    //     }
    // public:
    //     bool canJump(vector<int>& nums) {
    //         bool flag = false;
    //         jump(nums, 0, flag);
    //         return flag;
    //     }

    // 版本二
    // 由後往前找  如果n-1 能到達n  代表能到達 n-1 也會成功
private:
    bool jump(vector<int> &nums, int index, set<int>& setCanJump, int& minJumpNum)
    {
        bool bResult = false;
        if (index + nums[index] < minJumpNum)
            return bResult;
        else
        {
            for (int i = index + 1; i < nums.size() && i <= index + nums[index]; i++)
            {
                if (setCanJump.find(i) != setCanJump.end())
                {
                    minJumpNum = index;
                    bResult = true;
                    break;
                }
            }
            return bResult;
        }
    }

public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        set<int> setCanJump;
        setCanJump.insert(nums.size() - 1);
        int current = nums.size() - 2;
        int minJumpNum = nums.size() - 1;
        bool result = false;
        while (current >= 0)
        {
            cout << "current = " << current << endl;
            bool bJump = jump(nums, current, setCanJump, minJumpNum);
            cout << "bJump = " << (bJump ? "T" : "F") << endl;
            if (current == 0 && bJump)
            {
                result = true;
                break;
            }
            if(bJump)
                setCanJump.insert(current);

            current--;
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<int> v = {0};
    cout << (test.canJump(v) ? "T" : "F");

    return 0;
}