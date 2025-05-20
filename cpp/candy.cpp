#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void sortRating(vector<pair<int, int>> &v)
    {
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (v[j].second > v[j+1].second)
                    swap(v[j], v[j+1]);
            }
        }
    }

public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();
        vector<pair<int, int>> vr; // index , rate
        for (int i = 0; i < size; i++)
        {
            vr.push_back({i, ratings[i]});
        }

        sortRating(vr);

        vector<int> result(size, 0);

        for (int i = 0; i < size; i++)
        {
            int index = vr[i].first;
            if (index == 0) // 邊界旁邊只有一個需要比較
            {
                if (ratings.size() > 1)
                    result[index] = ratings[index] > ratings[index+1] ? result[index + 1] + 1 : 1;
                else
                    result[index] = 1;
            }
            else if (index == size - 1) // 邊界旁邊只有一個需要比較
            {
                result[index] = ratings[index] > ratings[index - 1] ? result[index - 1] + 1 : 1;
            }
            else if (result[index - 1] == 0 && result[index + 1] == 0) // 前後都為 0 代表還沒放糖果
            {
                result[index] = 1;
            }
            else if (result[index - 1] != 0 && result[index + 1] != 0) // 前後都不為 0 代表都已經放糖果
            {
                if(ratings[index] > ratings[index - 1] && ratings[index] > ratings[index + 1])
                    result[index] = max(result[index - 1], result[index + 1]) + 1;
                else if(ratings[index] > ratings[index - 1])
                    result[index] = result[index-1] + 1;
                else if(ratings[index] > ratings[index + 1])
                    result[index] = result[index+1] + 1;
                else
                    result[index] = 1;
            }
            else if (result[index - 1] != 0) // 只有前面不為 0 至少要大於等於前面的糖果數量
            {
                result[index] = ratings[index] > ratings[index - 1] ? result[index - 1] + 1 : 1;
            }
            else if (result[index + 1] != 0) // 只有後面不為 0 至少要大於等於後面的糖果數量
            {
                result[index] = ratings[index] > ratings[index + 1] ? result[index + 1] + 1 : 1;
            }
        }

        int totalCandy = 0;
        for (int i = 0; i < size; i++)
            totalCandy += result[i];

        return totalCandy;
    }
};

int main()
{
    Solution test;
    vector<int> v{1,2,87,87,87,2,1};
    test.candy(v); 
    return 0;
}