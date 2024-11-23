#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        map<string, vector<string>> map;
        for (string& str : strs)
        {
            string word = str;
            sort(word.begin(), word.end());
            map[word].push_back(str);
        }

        for(auto iter : map)
            result.push_back(iter.second);
        return result;
    }
};

int main()
{
    map<int, vector<int>> map;
    for(int i=0; i<10; i++)
    {
        vector<int> v;
        for(int j=0; j<i+1; j++)
            v.push_back(j);
        
        map.emplace(i, v);
    }

    for(auto iter : map)
    {
        for(int i=0; i<iter.second.size(); i++)
            cout << iter.second[i] << " ";
        cout << endl;
    }
    return 0;
}
