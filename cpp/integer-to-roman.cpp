#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string thousandToRoman(int num) {
        string s = "";
        for(int i=0; i<(num/1000); i++)
            s += "M";
        return s;
    }

    string hundredToRoman(int num) {
        string s = "";
        if(num == 900) s = "CM";
        else if (num == 400) s = "CD";
        else if (num >= 500) {
            s = "D";
            for(int i=0; i<(num % 500)/100; i++)
                s += "C";
        } else {
            for(int i=0; i<num/100; i++)
                s += "C";
        }
        return s;
    }

    string tenToRoman(int num) {
        string s = "";
        if(num == 90) s = "XC";
        else if (num == 40) s = "XL";
        else if (num >= 50) {
            s = "L";
            for(int i=0; i<(num % 50)/10; i++)
                s += "X";
        } else {
            for(int i=0; i<num/10; i++)
                s += "X";
        }
        return s;
    }

    string singleDigitToRoman(int num) {
        string s = "";
        if(num == 9) s = "IX";
        else if (num == 4) s = "IV";
        else if (num >= 5) {
            s = "V";
            for(int i=0; i<(num % 5); i++)
                s += "I";
        } else {
            for(int i=0; i<num/10; i++)
                s += "I";
        }
        return s;
    }
public:
    string intToRoman(int num) {
        string result = "";
        // 千
        int thousands = num - (num % 1000);
        if(thousands > 0)
            result += thousandToRoman(thousands);
        // 百
        int hundreds = num - thousands - (num % 100);
        if(hundreds > 0)
            result += hundredToRoman(hundreds);
        // 十
        int tens = num - thousands - hundreds - (num % 10);
        if(tens > 0)
            result += tenToRoman(tens);
        // 個位數
        int singleDigits = num - thousands - hundreds - tens;
        if(singleDigits > 0)
            result += singleDigitToRoman(singleDigits);

        return result;
    }
};

int main()
{
    Solution test;
    cout << test.intToRoman(1994);
    
    return 0;
}