/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    if (!head) return head;
    
    double value,duplicatedVal;
    bool duplicated = false;
    struct ListNode *p = head;
    struct ListNode *pNext = NULL;
    
    while (p && (pNext = p->next)) {
        value = p->val;
        
        duplicated = true;
        
        while(duplicated && (pNext!=NULL)){
            duplicatedVal = pNext->val;
            if (duplicatedVal == value){
                
                if (pNext->next != NULL){
                    pNext = pNext->next;
                 }else{
                     pNext = NULL;
                     p->next = pNext;
                     break;
                 }
            } else{
                duplicated = false;
            }
        }
        p->next = pNext;
        p = p->next;
    }
    return head;
}

//continue...
