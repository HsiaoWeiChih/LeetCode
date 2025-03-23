#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            
            int size = digits.size();
            
            if(digits[0] == 0)
            {
                digits[0]++;
                return digits;
            }
            
            if(digits[0] == 9 && size == 1)
            {
                digits[0] = 1;
                digits.push_back(0);
                return digits;
            }
            
            int c = ++digits[size-1];
    
            while(c == 10)
            {
                digits[size-1] = 0;
                c = ++digits[size-2];
                size--;
                if(size == 1 && c == 10)
                {
                    digits[0] = 1;
                    for(int i=1; i<digits.size(); i++)
                    {
                        digits[i] = 0;
                    }
                    digits.push_back(0);
                    c = 0;
                }
            }
            
            return digits;
        }
    };