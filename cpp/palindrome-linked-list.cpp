#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            vector<int> vec;
            
            ListNode* ptr = head;
            bool bLoop = true;
            while(bLoop)
            {
                vec.push_back(ptr->val);
                if(ptr->next != nullptr)
                {
                    bLoop = true;
                    ptr = ptr->next;
                }
                else
                    bLoop = false;
            }
            
            int iLoop = vec.size();
            bool bResult = true;
            ptr = head;
            for(int i=iLoop-1; i>=0; i--)
            {
                if(vec[i] == ptr->val)
                    ptr = ptr->next;
                else
                {
                    bResult = false;
                    break;
                }
            }
            return bResult;
        }
    };