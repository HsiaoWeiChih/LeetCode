#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;

        if(tmpA == nullptr || tmpB == nullptr)
        {
            return nullptr;
        }

        ListNode* result = nullptr;
        bool bFind = false;
        while(tmpA != nullptr)
        {
            while(tmpB != nullptr)
            {
                if(tmpA == tmpB)
                {
                    bFind = true;
                    result = tmpA;
                    break;
                }
                tmpB = tmpB->next;
            }
            if(bFind)
                break;
            tmpA = tmpA->next;
            tmpB = headB;
        }
        return result;
    }
};