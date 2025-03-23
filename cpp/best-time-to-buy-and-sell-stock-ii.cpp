#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            
            int pf = 0;
            int min = 0;
            int max = 0;
            
            bool tag = false;
            
            for(int i=0; i<prices.size(); i++)
            {
                if(prices[i] < max)
                {
                    pf += (max - min);
                    max = 0;
                    min = 0;
                    tag = false;
                }
                
                if(prices[i] <= min || !tag)
                {
                    min = prices[i];
                    tag = true;
                    continue;
                }
                else if(prices[i] >= max)
                {
                    max = prices[i];
                }
                
                if(i == prices.size()-1)
                    pf += (max - min);
            }
            return pf;
            
        }
    };