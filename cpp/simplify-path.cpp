#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    string findNextFolder(string path, int &current)
    {
        int index = current;
        while (path[index] == '/')
            index++;

        current = index;
        if (current >= path.size())
            return "";

        while (path[index] != '/' && index < path.size())
            index++;

        string f = path.substr(current, index - current);
        current = index;
        return f;
    }

public:
    string simplifyPath(string path)
    {
        vector<string> folders;
        int index = 0;
        while (index < path.size())
        {
            string f = findNextFolder(path, index);
            if (f == "" || f == ".")
                continue;
            else if (f == "..")
            {
                if (folders.size() > 0)
                    folders.pop_back();
            }
            else
                folders.push_back(f);
        }

        string result;
        if (folders.size() == 0)
            result = "/";
        else
        {
            for (int i = 0; i < folders.size(); i++)
            {
                result += "/" + folders[i];
            }
        }

        return result;
    }
};

int main()
{
    Solution test;
    auto s = test.simplifyPath("/../");
    cout << s << endl;
    return 0;
}