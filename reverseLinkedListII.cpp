// Source: https://leetcode.com/problems/reverse-linked-list-ii/
// Date: 2016-03-26
/***************************************************************
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
*
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
*
* return 1->4->3->2->5->NULL.
*
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
****************************************************************/
// 插入法
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m<1 || m>=n || !head) return head;
     ListNode newhead(0);   // another way to define it is: ListNode *newhead = new ListNode(0), but if you forget to delete it at end...
                            // it may lead to leak
     newhead.next = head;
     ListNode *prev = &newhead;
     
     for(int i=0; i<m-1; i++){
         prev = prev->next;
     }
     
     ListNode* pstart = prev->next;
     
     for(int i=0; i<n-m; i++){
         ListNode *p = pstart->next;
         pstart->next = p->next;
         p->next = prev->next;
         prev->next = p;
     }
    
     return newhead.next;
    }
};

// 反转法
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(m<1 || m>=n || !head) return head;
    ListNode *newhead = new ListNode(0);
    newhead->next = head;
    head = newhead;
    for(int i=0; i<m-1; i++){
    head = head->next;
    }
    ListNode *prev = head->next;
    ListNode *cur = prev->next;
    for(int i=0; i<n-m; i++){              // do a simple reverse of the linked list
    ListNode *temp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = temp;
    }
    head->next->next = cur;               // why the order cannot be reverse???
    head->next = prev;
    head = newhead->next;
    delete newhead;
    return head;
  }
};
    
    
