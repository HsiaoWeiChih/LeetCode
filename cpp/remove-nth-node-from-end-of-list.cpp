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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1){
            return NULL;
        }
        else if(head->next == NULL && n == 0){
            return head;
        }            
        ListNode* ptr1;
        ListNode* ptr2;
        
        ptr1 = head;
        ptr2 = head;
        
        if(n == 1){
            ptr1 = head;
            while((ptr1->next)->next != NULL){
                ptr1 = ptr1->next;
            }
            ptr1->next = NULL;
            return head;
        }
        
        for(int i=1; i<n; i++){
            ptr2 = ptr2->next;
        }
        
        while(ptr2->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr1->val = (ptr1->next)->val;
        ptr1->next = (ptr1->next)->next;
        
        return head;
    }
};