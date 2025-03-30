#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> m_nums;

public:
    Solution(vector<int> &nums)
    {
        this->m_nums = nums;
        srand(time(NULL)); // 在建構子中設置亂數種子
    }

    vector<int> reset()
    {
        return m_nums;
    }

    vector<int> shuffle()
    {
        vector<int> result;

        vector<int> randNums = randomNum(this->m_nums.size());
        for (int i = 0; i < this->m_nums.size(); i++)
        {
            result.push_back(this->m_nums[randNums[i]]);
        }
        return result;
    }

    vector<int> randomNum(int n)
    {
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int num = rand() % n; // rand()%(最大值-最小值+1)+ 最小值 值放進陣列
            bool bSame = false;

            for (int j = 0; j < i; j++) // 跑我之前已經產生的結果
            {
                if (v[j] == num) // 比較值是否已經存在
                {
                    i--;
                    bSame = true;
                    break;
                }
            }
            if (!bSame)
                v.push_back(num);
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */