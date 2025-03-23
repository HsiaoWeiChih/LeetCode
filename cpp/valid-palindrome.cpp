#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            
            vector<int> vi;
            for(int i=0; i<s.size(); i++){
                if(s[i] >= 97 && s[i] <= 122){
                    vi.push_back((int)s[i]);
                }
                else if(s[i] >= 65 && s[i] <= 90){
                    vi.push_back((int)s[i] + 32);
                }
                else if(s[i] >= 48 && s[i] <= 57){
                    vi.push_back((int)s[i]-48);
                }
                else
                    continue;
            }
            
            for(int i=0; i<floor(vi.size()/2.0); i++){
                if(vi[i] != vi[vi.size()-1-i])
                    return false;
            }
            return true;
        
        }
    };