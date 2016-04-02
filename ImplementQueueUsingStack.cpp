// Source: https://leetcode.com/problems/implement-queue-using-stacks/
// Date: 2016-04-02
/********************************************************************************** 
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * peek() -- Get the front element.
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to top, 
 * peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a 
 * stack by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations 
 * will be called on an empty queue).
 *               
 **********************************************************************************/
// The trick is using an extra stack to store the reversed stack(so it can has the same form as queue) 

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);       // still store the data using stack form
    }

    // Removes the element from in front of queue.
    void pop(void) {
       transfer(s1, s2);            // using reversed stack to pop out
       s2.pop(); 
       transfer(s2, s1);            // convert back to normal stack
    }

    // Get the front element.
    int peek(void) {
        transfer(s1, s2);
        int res = s2.top();
        transfer(s2, s1);
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
    private: 
    stack<int> s1, s2;
    void transfer(stack<int>& s1, stack<int>& s2){            // s1 is the stack, s2 is the reversed stack
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
};
