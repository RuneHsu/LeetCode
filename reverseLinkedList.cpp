// Source: https://leetcode.com/problems/reverse-linked-list/
// Date: 2016-03-26
/*********************************************************************
* Reverse a singly linked list.
*********************************************************************/
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode *prev=NULL;
        ListNode *nex=NULL;
        while(head->next){
                nex = head->next;
                head->next = prev;
                prev = head;
                head = nex;
        }  // didn't reverse the tail yet
       head->next = prev;
    }
};
// can change the while condition such that don't need to pay attention the tail??

/************************** Another solution **********************************/
// Source: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/reverse-linked-list.cpp

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto *dummy_head = new ListNode(0);

        while (head) {
            auto *tmp = head->next;
            head->next = dummy_head->next;
            dummy_head->next = head;
            head = tmp;
        }

        return dummy_head->next;
    }
};

// Source: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/reverseLinkedList/reverseLinkedList.cpp
class Solution {
public:
    ListNode* reverseList_iteratively(ListNode* head) {
        ListNode *h=NULL, *p=NULL;
        while (head){
            p = head->next;
            head->next = h;
            h = head;
            head = p;
        }
        return h; // the trick is return the previous node
    }
    ListNode* reverseList_recursively(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *h = reverseList_recursively(head->next);
        head->next->next = head;      // cause every (except the last node has been reversed)
        head->next = NULL;
        return h;
        
    }
    ListNode* reverseList(ListNode* head) {
        return reverseList_iteratively(head);
        return reverseList_recursively(head);
    }
};
