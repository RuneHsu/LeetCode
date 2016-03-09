/* Given a singly linked list, group all odd nodes together 
* followed by the even nodes. Please note here we are talking 
* about the node number and not the value in the nodes.*/

/* C version */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head) return head;
    struct ListNode *p = head, *q = head;
    while(q){
        q = q->next;
        if(!q || !q->next) break;
        struct ListNode *next_p = p->next, *next_q = q->next;
        q->next = next_p->next;
        p->next = next_q;
        next_q->next = next_p;
        p = p->next;
    }
    return head;
}

// exeed the time limited
/****************************************************************/
// another c version

struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head) return head;
    struct ListNode *headp = head;
    struct ListNode *p = head->next;
    struct ListNode *pNext = NULL;
    while(p && (pNext = p->next)){
        p->next = pNext->next;
        pNext->next = headp->next;
        headp->next = pNext;
        
        
        p = p->next;
        headp = headp->next;
    }
    return head;
}

/* executed well*/

/* C++ version */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
		ListNode *p = head, *q = head;
		while (q) {
			q = q->next;
			if (!q || !q->next) break;
			ListNode *next_p = p->next, *next_q = q->next;
			q->next = next_q->next;
			p->next = next_q;
			next_q->next = next_p;
			p = p->next;
		}
		return head;
    }
};

// C++ version is fine. What the difference between the C and C++??
