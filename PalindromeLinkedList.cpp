// Source: https://leetcode.com/problems/palindrome-linked-list/
// Date: 2016-05-08

/***********************************************************
* Given a singly linked list, determine if it is a palindrome.
*
* Follow up:
* Could you do it in O(n) time and O(1) space?
************************************************************/

class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p){
        if (p == NULL) return true;
        bool isPal = check(p->next) & (temp->val == p->val);      // p recursion to the end of the list, compare with temp
        temp = temp->next; 
        return isPal;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};
