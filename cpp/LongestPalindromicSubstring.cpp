#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
private:
    string expand_from_center(string str, int left, int right) {
        bool flag = false;
        while(left >= 0 && right < str.size() && str[left] == str[right]) {
            left--;
            right++;
            flag = true;
        }
        return flag ? str.substr(left+1, right-left-1) : "";
    }
public: 
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        else {
            int iMax = 1;
            string maxStr = s.substr(0, 1);

            for(int i=0; i<s.size()-1; i++) {
                string odd = expand_from_center(s, i, i);
                string even = expand_from_center(s, i, i+1);

                if(odd.size() > maxStr.size()) {
                    maxStr = odd;
                }
                if(even.size() > maxStr.size()) {
                    maxStr = even;
                }
            }
            return maxStr;
        }
    }
};

int main() {
    Solution test;
    string s = test.longestPalindrome("babad");
    cout << s << endl;

    return 0;
}