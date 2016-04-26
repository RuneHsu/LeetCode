// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Date: 2016-04-26

/*********************************************************************************
* Given a linked list, remove the nth node from the end of list and return its head.
*
* For example,
*
* Given linked list: 1->2->3->4->5, and n = 2.
*
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
* Try to do this in one pass.
***********************************************************************************/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        
        ListNode newList(0);
        newList.next = head;
        
        ListNode *count = head;
        ListNode *cur = &newList;
        
        while (count!=NULL){
            count = count->next;
            length++;
        }
        
        int rev_n = length - n;
        for(int i=0; i<length; i++){
            if (i == rev_n){
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }
        return newList.next;
    }
};


// ref: https://leetcode.com/discuss/16936/my-short-c-solution

class Solution{
    public: 
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode **t1 = &head;       // use to delete the node when the node is found
        ListNode *t2 = head;         // use to find the node
        
        for(int i=1; i<n; i++){
            t2 = t2->next;          // move forward n nodes, so remaining (length-n) nodes
        }
        
        while(t2->next != NULL) {     // if (t2->next == NULL), means, for t1, it has moved (length-n) steps
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }
};
