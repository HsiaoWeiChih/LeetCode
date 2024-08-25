#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* singleRotate(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        else if(head->next->next == nullptr)
        {
            ListNode* lastPtr = head->next;
            lastPtr->next = head;
            head->next = nullptr;
            return lastPtr;
        }
        else
        {
            ListNode* last2Ptr = head->next;
            ListNode* lastPtr = head->next->next;
            while(lastPtr->next != nullptr)
            {
                last2Ptr = lastPtr;
                lastPtr = lastPtr->next;
            }
            last2Ptr->next = nullptr;
            lastPtr->next = head;
            return lastPtr;
        }
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tmp = head;
        if(tmp == nullptr || tmp->next == nullptr)
        {
            return head;
        }
        else
        {
            int count = 1;
            while(tmp->next != nullptr)
            {
                tmp = tmp->next;
                count++;
            }

            int loop = k % count;
            for(int i=0; i<loop; i++)
            {
                head = singleRotate(head);
            }
            return head;
        }
    }
};

int main()
{
    Solution test;

    return 0;
}