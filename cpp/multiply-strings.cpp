#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int charToInt(char s)
    {
        if(s == '0') return 0;
        else if(s == '1') return 1;
        else if(s == '2') return 2;
        else if(s == '3') return 3;
        else if(s == '4') return 4;
        else if(s == '5') return 5;
        else if(s == '6') return 6;
        else if(s == '7') return 7;
        else if(s == '8') return 8;
        else return 9;
    }

    string digitToStr(int num)
    {
        if(num == 0) return "0";
        else if(num == 1) return "1";
        else if(num == 2) return "2";
        else if(num == 3) return "3";
        else if(num == 4) return "4";
        else if(num == 5) return "5";
        else if(num == 6) return "6";
        else if(num == 7) return "7";
        else if(num == 8) return "8";
        else return "9";
    }

    void checkAllnumber(vector<int>& v)
    {
        for(int i=v.size()-1; i>=0; i--)
        {
            while(v[i] >= 10)
            {
                int temp = v[i] % 10;;
                v[i-1] += v[i] / 10;
                v[i] = temp;
            }
        }
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size(), len2 = num2.size();
        vector<int> result(len1 + len2 + 2, 0);

        int dig1 = 0;
        for(int i=len1-1; i>=0; i--)
        {
            int dig2 = 0;
            for(int j=len2-1; j>=0; j--)
            {
                int n1 = charToInt(num1[i]);
                int n2 = charToInt(num2[j]);
                int n3 = n1 * n2;
                    
                result[len1+len2+2-1-dig1-dig2] += n3;
                dig2++;
            }
            dig1++;
        }

        checkAllnumber(result);

        bool zeroFirst = true;
        string str = "";
        for(int i=0; i<result.size(); i++)
        {
            if(result[i] == 0 && zeroFirst)
                continue;
            else
            {
                zeroFirst = false;
                str += digitToStr(result[i]);
            }
        }

        return str;
    }
};

int main()
{
    Solution test;
    cout << test.multiply("6913259244", "71103343");

    return 0;
}