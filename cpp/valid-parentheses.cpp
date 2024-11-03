#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    char left_to_right(char c)
    {
        if(c == '{')
            return '}';
        else if(c == '[')
            return ']';
        else if(c == '(')
            return ')';
        else
            return 'N';
    }
    
    bool isValid(string s) {
        stack<char> s_stack;
    
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                s_stack.push(c);
            } else {
                if (s_stack.empty()) {
                    return false;
                }
                char top = s_stack.top();
                s_stack.pop();
                if (c != left_to_right(top)) {
                    return false;
                }
            }
        }
        return s_stack.empty();
    }
};