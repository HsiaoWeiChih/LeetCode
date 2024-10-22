#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        else
        {
            ListNode *dummyNode = new ListNode();
            ListNode *prevNode = dummyNode;
            ListNode *currNode = head;

            while (currNode && currNode->next)
            {
                prevNode->next = currNode->next; //2
                currNode->next = currNode->next->next; // 3
                prevNode->next->next = currNode; //1

                prevNode = currNode;
                currNode = currNode->next;
            }
            return dummyNode->next;
        }
    }
};