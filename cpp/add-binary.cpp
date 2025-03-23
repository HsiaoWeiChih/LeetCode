#include <iostream>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            int overdig = 0;
            
            if(a.size() > b.size())
                swap(a, b);
            
            int lena = a.size();
            int lenb = b.size();
            
            for(int i=1; i<=lenb; i++)
            {
                if(i<=lena)
                {
                    overdig += (a[lena-i]-'0') + (b[lenb-i]- '0');
                }
                else
                {
                    overdig += b[lenb-i] - '0';
                }
                b[lenb-i] = overdig%2 + '0';
                overdig /= 2;
                
            }
            
            if(overdig == 1)
            {
                b.insert(0, 1, '1');
            }
            
            return b;
        }
    };