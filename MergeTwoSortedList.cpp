 class Solution{
     public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
         if(!l1) return l2;
         if(!l2) return l1;
         ListNode *head = new ListNode(-1);
         ListNode *prev = head;
     
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
         prev = head->next;
         delete head;
         return prev;
        
     }
  };
