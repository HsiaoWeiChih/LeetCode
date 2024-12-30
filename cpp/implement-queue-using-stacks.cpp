#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> mStack;
public:
    MyQueue() {

    }
    
    void push(int x) {
        mStack.push(x);
    }
    
    int pop() {
        stack<int> tmpStack;
        while(mStack.size() > 1)
        {
            tmpStack.push(mStack.top());
            mStack.pop();
        }
        int firstNum = mStack.size() == 1 ? mStack.top() : NULL;
        mStack.pop();
        while(tmpStack.size() > 0)
        {
            mStack.push(tmpStack.top());
            tmpStack.pop();
        }
        return firstNum;
    }
    
    int peek() {
        stack<int> tmpStack = mStack;
        while(tmpStack.size() > 1)
        {
            tmpStack.pop();
        }
        return tmpStack.top();
    }
    
    bool empty() {
        return mStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */