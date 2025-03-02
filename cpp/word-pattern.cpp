#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution
{
private:
    string findNextWord(string s, int& index)
    {
        if(index >= s.size())
            return " ";
        
        while(index < s.size() && s[index] == ' ')
            index++;
        int current = index;
        while(index < s.size() && s[index] != ' ')
        {
            index++;
        }
        string result = s.substr(current, index-current);
        return result;
    }
public:
    bool wordPattern(string pattern, string s)
    {
        int index = 0;
        int pIndex = 0;
        map<char, string> mapPattern;
        set<string> setWords;
        while(index < s.size() && pIndex < pattern.size())
        {
            auto tmp = findNextWord(s, index);
            if(tmp == " ")
                continue;
            char p = pattern[pIndex];
            if(mapPattern.find(p) != mapPattern.end() && setWords.find(tmp) != setWords.end())
            {
                // 皆已存在
                if(mapPattern[p] != tmp)
                    return false;
            }
            else if(mapPattern.find(p) == mapPattern.end() && setWords.find(tmp) == setWords.end())
            {
                // 尚未出現過
                mapPattern.emplace(p, tmp);
                setWords.emplace(tmp);
            }
            else
            {
                cout << "p = " << p << endl;
                cout << "tmp = " << tmp << endl;
                cout << "mapPattern.size() =" << mapPattern.size() << endl;
                cout << "setWords.size() = " << setWords.size() << endl;
                for(auto iter : mapPattern)
                {
                    cout << iter.first << " " << iter.second << endl;
                }
                for(auto iter : setWords)
                {
                    cout << iter << endl;
                }
                // mapPattern or setWords 其中一個已出現過
                return false;
            }
            pIndex++;
        }
        if(index >= s.size() && pIndex >= pattern.size())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution test;
    cout << "Solution = " << (test.wordPattern("aaa", "aa aa aa aa") ? "T" : "F") << endl;
    return 0;
}