#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode headNode(-1);
        ListNode* mergeList = &headNode;

        ListNode* list3 = mergeList;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {            
                list3->next = list1;
                list1 = list1->next;
            }
            else
            {
                list3->next = list2;
                list2 = list2->next;
            }
            list3 = list3->next;
        }
        
        if(list1 == NULL)
        {
            list3->next = list2;
        }
        else
        {
            list3->next = list1;
        }
        list3 = list3->next;
               
        return mergeList->next;
    }
};