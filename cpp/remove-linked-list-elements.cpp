#include <iostream>

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        
        // find new head
        ListNode* newHead = nullptr;
        while (head != nullptr)
        {
            if(head->val == val)
                head = head->next;
            else
            {
                newHead = head;
                break;
            }
        }
        
        ListNode* p = newHead;
        while(p != nullptr && p->next != nullptr)
        {
            if(p->next->val == val)
            {
                p->next = p->next->next;
                continue;
            }
            p = p->next;
        }
        return newHead;
    }
};

int main()
{
    ListNode* p1 = new ListNode(7);
    ListNode* p2 = new ListNode(7);
    ListNode* p3 = new ListNode(7);
    ListNode* p4 = new ListNode(7);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;

    Solution test;
    test.removeElements(p1, 7);

    return 0;
}