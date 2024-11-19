#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> tSet;
        for(int i=0; i<s.length(); i++)
        {
            if(m.size() > 0 && m.find(s[i]) != m.end() && m[s[i]] == t[i])
                continue;
            else if(m.size() > 0 && m.find(s[i]) != m.end() && m[s[i]] != t[i])
                return false;
            else if(tSet.size() > 0 && tSet.find(t[i]) != tSet.end())
                return false;
            else
            {
                m.emplace(s[i], t[i]);
                tSet.insert(t[i]);
            }   
        }
        return true;
    }
};

int main()
{
    Solution test;
    cout << (test.isIsomorphic("badc", "baba") ? "T" : "F");
    
    return 0;
}