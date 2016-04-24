// Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Date: 2016-04-24
/********************************************************************************************
* Write a program to find the node at which the intersection of two singly linked lists begins.
*
*
* For example, the following two linked lists:
*
* A:          a1 → a2
*                   ↘
*                     c1 → c2 → c3
*                    ↗            
* B:     b1 → b2 → b3
* begin to intersect at node c1.
*
*
* Notes:
*
* If the two linked lists have no intersection at all, return null.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.
*********************************************************************************************/
// ref: https://leetcode.com/discuss/17278/accepted-shortest-explaining-algorithm-comments-improvements

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode *ptrA = headA, *ptrB = headB;
       
       if (ptrA == NULL || ptrB == NULL) return NULL;
       
       while(ptrA != NULL && ptrB != NULL && ptrA != ptrB){
           ptrA = ptrA->next;
           ptrB = ptrB->next;
           
           // Any time they collide or reach end together without colliding 
           // then return any one of the pointers.
           
           if (ptrA == ptrB){
               return ptrA;
           }
           
           // If one of them reaches the end earlier then reuse it 
           // by moving it to the beginning of other list.
           // Once both of them go through reassigning, 
           // they will be equidistant from the collision point.
           
           if (ptrA == NULL) ptrA = headB;
           if (ptrB == NULL) ptrB = headA;
       }
       return ptrA;
    }
};
