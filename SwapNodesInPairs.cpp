// Source: https://leetcode.com/problems/swap-nodes-in-pairs/
// Date: 2016-04-01

/********************************************************************************** 
* 
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
* 
*               
**********************************************************************************/

class Solution{
public:
    ListNode* swapPairs(ListNode* head){
      ListNode dummy = ListNode(0);
      dummy.next = head;
      ListNode *cur = &dummy;
      while(cur->next && cur->next->next){
      ListNode *next_one = cur->next;
      ListNode *next_two = next_one->next;
      ListNode *next_three = next_two->next;
      
      cur->next = next_two;
      next_one->next = next_three;
      next_two->next = next_one;
      cur = next_one;
      }
      return dummy.next;
    }
  };
  
  /************************* Other solutions ***********************/
  // ref: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/swapNodesInPairs/swapNodesInPairs.cpp
  class Solution {
  public:
    Solution(){
        srand(time(NULL));
    }
    /*
     * Here we have two ways to solve this problem:
     * 1) keep the list's nodes no change. only swap the data in the list node.
     * 2) swap the list node physically.
     */
    ListNode *swapPairs(ListNode *head) {
        if(random()%2){
            return swapPairs1(head);
        }
        return swapPairs2(head);
    }
    /*just swap the node's value instead of node*/
    ListNode *swapPairs1(ListNode *head) {
        for (ListNode *p = head; p && p->next; p = p->next->next) {        //why can swap the value,'not modify the value??'
            int n = p->val;
            p->val = p->next->val;
            p->next->val = n;
        }
        return head;
    }
    /*swap the list nodes physically*/ 
    ListNode *swapPairs2(ListNode *head) {
        ListNode *h = NULL;
        //using `*p` to traverse the linked list
        for (ListNode *p = head; p && p->next; p = p->next) {
            //`n` is `p`'s next node, and swap `p` and `n` physcially
            ListNode *n = p->next;
            p->next = n->next;
            n->next = p;
            //using `h` as `p`'s previous node
            if (h){
                h->next = n;
            }
            h=p;
            
            //determin the really 'head' pointer
            if (head == p){
                head = n;
            }
        }
        
        return head;
    }
};

/************************* recursion way *******************/
class Solution{
public:
  ListNode swapPairs(ListNode *head){
  if(!head || !head->next) return head;
  ListNode *nextPairs = head->next->next;
  ListNode *newHead = head->next;
  head->next->next = head;
  head->next = swapPairs(nextPairs);
  return newHead;
  }
};
