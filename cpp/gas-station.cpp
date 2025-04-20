#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int size = gas.size();
        vector<int> startIndex;
        int allGas = 0;
        int allCost = 0;
        for(int i=0; i<size; i++)
        {
            allGas += gas[i];
            allCost += cost[i];
            if(gas[i] > 0 && gas[i] >= cost[i])
                startIndex.push_back(i); // 可開始的起點
        }

        int result = -1;
        if(allGas < allCost)
            return result;
        for(int i=0; i<startIndex.size(); i++)
        {
            int realIndex;
            int tank = 0;
            bool success = true;
            for(int j=startIndex[i]; j<startIndex[i]+size; j++)
            {
                realIndex = j % size;  // 繞過一圈
                tank += gas[realIndex];
                tank -= cost[realIndex];
                if(tank < 0)
                {
                    success = false;
                    break;
                }
            }
            if(success)
            {
                result = startIndex[i];
                break;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    Solution test;
    test.canCompleteCircuit(gas, cost);
    return 0;
}