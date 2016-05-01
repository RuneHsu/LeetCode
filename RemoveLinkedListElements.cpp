// Source: https://leetcode.com/problems/remove-linked-list-elements/
// Date: 2016-05-01

/***********************************************************************
* Remove all elements from a linked list of integers that have value val.
*
* Example
* Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
* Return: 1 --> 2 --> 3 --> 4 --> 5
************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode newList(0);
        newList.next = head;
        ListNode *cur = &newList;
       
        while(cur){
            if (cur->next && cur->next->val == val ){
                cur->next = (cur->next)->next; 
            } else {
                cur = cur->next;
            }
        }
        return newList.next;
    }
};
class Solution {
    public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        head->next = removeElements(head->next,val);
        return head->val == val ? head->next: head;
    }
};
class Solution {
    public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **cur = &head;
        while(*cur != nullptr) {
            if ((*cur)->val == val){
                *cur = (*cur)->next;
            } else {
                cur = &(*cur)->next;
            }
        }
        return head;
    }
};
