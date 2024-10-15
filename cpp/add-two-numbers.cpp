#include <iostream>
#include <math.h>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head = new ListNode();
        ListNode *l3 = head;
        
        //ListNode **head = NULL;
        //ListNode *l3;
        
        int dig = 0;
        int sum = 0;
        int count = 1;
        while(l1 != NULL || l2 != NULL || dig>0)
        {
            if(l1 == NULL && l2 == NULL)
            {
                sum = dig;
            }
            else if(l1 == NULL)
            {
                sum = l2->val + dig;
                l2 = l2->next;
            }
            else if(l2 == NULL)
            {
                sum = l1->val + dig;
                l1 = l1->next;
            }
            else
            {
                sum = l1->val + l2->val + dig;
                l1 = l1->next;
                l2 = l2->next;
            }
            dig = sum/10;
            l3->next = new ListNode(sum%10);
            l3 = l3->next; 
            
            
        }
        
        return head->next;
        
    }
};