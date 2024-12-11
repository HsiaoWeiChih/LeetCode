#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int result = q1.back();
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1 = q2;
        queue<int> q3;
        q2 = q3;
        return result;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack test;

    return 0;
}