#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        
        int tag = 0;
        bool pos = true;
        int num = 0;
        int max = pow(2, 31) - 1;
        int min = -pow(2, 31);
        
        while((int)s[tag] == 32){
            tag++;
        }
        
        if((int)s[tag] == 43){
            pos = true;
            tag++;
        }
        else if((int)s[tag] == 45){
            pos = false;
            tag++;
        }
        
        while((int)s[tag] >= 48 && (int)s[tag] <= 57){
            if(num == 0 && pos)
                num = (int)s[tag]-48;
            else if(num == 0 && !pos)
                num = 0 - (int)s[tag] + 48;
            else{
                if(pos){
                    if((max - ((int)s[tag] - 48))/10 < num){
                        num = max;
                        break;
                    }
                    else{
                        num = num*10 -48 + (int)s[tag];
                    }                        
                }
                else{
                    if((min + ((int)s[tag] - 48))/10 > num){
                        num = min;
                        break;
                    }
                    else{
                        num = num*10 + 48 -(int)s[tag];
                    }
                }
            }
            
            tag++;
        }
        return num;
    }
};