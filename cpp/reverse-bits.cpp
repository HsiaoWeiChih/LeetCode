#include <iostream>

using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t ans = 0;
            int tail = 0;
            for(int i=0; i<32; i++){
                tail = n%2;
                n /= 2;
                ans += tail*pow(2, 31-i);
            }
            return ans;
        }
    };