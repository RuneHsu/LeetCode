// Source: https://leetcode.com/problems/merge-two-sorted-lists/
// Date: 2016-03-28
/***************************************************************
 *  Merge two sorted linked lists and return it as a new list. 
 *  The new list should be made by splicing together the nodes of the first two lists.
********************************************************************/

class Solution{
     public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
         if(!l1) return l2;
         if(!l2) return l1;
         ListNode newList(0);
         newList.next = l1;
         ListNode *prev = &newList;
     
         while(l1 && l2){
             if(l1->val < l2->val){
                 prev->next = l1;
                 l1 = l1->next;
             } else{
                 prev->next = l2;
                 l2 = l2->next;
             }
             prev = prev->next;
         }
         if(l2 != NULL){
             prev->next = l2;
         } 
         if(l1 != NULL){
             prev->next = l1;
         }
        
         return newList.next;
        
     }
  };
  
   class Solution{
     public: 
     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
         ListNode *head = NULL;                      // in order to check head==NULL situation
         ListNode **prev = &head;
         
         while(l1 && l2){
             if(l1->val < l2->val){
                 *prev = l1;
                 l1 = l1->next;
             } else{
                 *prev = l2;
                 l2 = l2->next;
             }
             prev = &(*prev)->next;
         }
         * prev = (l1 != NULL ? l1:l2);
         return head;
     }
 };
 
 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1,*p2 = l2;
        static ListNode newList(0);
        
        newList.next = p1;
        ListNode *prev = &newList;
        
        while(p1 && p2){          
            if(p1->val < p2->val){    // the pointer didn't change to next one, it still ponts to l1
                prev = p1;
                p1 = p1->next;   
            } else{
                prev->next = p2;          // the pointer change to next node then made the pointer points to l1
                p2 = p2->next;
                prev = prev->next;
                prev->next = p1;
            }
        }
        if(p2) {              // so in case of l1 is short, connect the rest of l2
            prev->next = p2;
        }
        return newList.next;
    }
};
