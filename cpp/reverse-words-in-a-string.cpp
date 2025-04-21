#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int index = -1;
        vector<string> v;
        int length = s.length();
        for(int i=0; i<s.length(); i++)
        {
            if(i == s.length() - 1)
            {
                if(index != -1 && s[i] != ' ')
                    v.push_back(s.substr(index, i+1-index));
                else if(index != -1 && s[i] == ' ')
                    v.push_back(s.substr(index, i-index));
                else if(s[i] != ' ')
                    v.push_back(s.substr(i, 1));
            }
            else if(s[i] != ' ' && index == -1)
            {
                index = i;
            }
            else if(s[i] != ' ' && index != -1)
            {
                continue;
            }
            else if(s[i] == ' ' && index != -1)
            {
                v.push_back(s.substr(index, i-index));
                index = -1;
            }
        }

        string result = "";
        for(int i=v.size() - 1; i>=0; i--)
        {
            result = i == 0 ? result + v[i] : result + v[i] + " ";
        }
        return result;
    }
};

int main()
{
    Solution test;
    cout << test.reverseWords("t ") << endl;
    return 0;
}