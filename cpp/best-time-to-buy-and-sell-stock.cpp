#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            
            int p1, p2;
            p1 = p2 = 0;
            
            if(prices.size() <= 1)
                return 0;
            
            p1 = prices[0];
            for(int i=1; i<prices.size(); i++){
                p2 = prices[i];
                if(p1 < p2){
                    profit = p2-p1 > profit ? p2-p1 : profit;
                }
                else if(p1 >= p2){
                    p1 = p2;
                }
            }
            return profit;
        }
    };