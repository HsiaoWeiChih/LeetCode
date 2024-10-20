#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> genPare(string s, int leftRest, int rightRest)
    {
        vector<string> result;
        if(leftRest == 0 && rightRest == 0)
        {
            result.push_back(s);
        }
        else if(leftRest == 0 && rightRest != 0)
        {
            vector<string> tmp = genPare(s+")", leftRest, rightRest-1);
            result.insert(result.begin(), tmp.begin(), tmp.end());
        }
        else if(leftRest == rightRest)
        {
            vector<string> tmp = genPare(s+"(", leftRest-1, rightRest);
            result.insert(result.begin(), tmp.begin(), tmp.end());
        }
        else
        {
            vector<string> tmpLeft = genPare(s+"(", leftRest-1, rightRest);
            vector<string> tmpRight = genPare(s+")", leftRest, rightRest-1);
            result.insert(result.begin(), tmpLeft.begin(), tmpLeft.end());
            result.insert(result.begin(), tmpRight.begin(), tmpRight.end());
        }
        return result;
    }
public:
    vector<string> generateParenthesis(int n) {
        return genPare("", n, n);
    }
};

int main()
{
    Solution test;
    vector<string> tmp = test.generateParenthesis(3);
    cout << "-------------result-------------\n";
    for(int i=0; i<tmp.size(); i++)
    {
        cout << tmp[i] << endl;
    }
    
    return 0;
}