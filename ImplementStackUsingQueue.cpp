// Source: https://leetcode.com/problems/implement-stack-using-queues/
// Date: 2016-04-02
/********************************************************************************** 
 * 
 * Implement the following operations of a stack using queues.
 * 
 * push(x) -- Push element x onto stack.
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * top() -- Get the top element.
 * 
 * empty() -- Return whether the stack is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a queue -- which means only push to back, 
 * peek/pop from front, size, and is empty operations are valid.
 *
 * Depending on your language, queue may not be supported natively. You may simulate 
 * a queue by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a queue.
 *
 * You may assume that all operations are valid (for example, no pop or top operations 
 * will be called on an empty stack).
 * 
 * Update (2015-06-11):
 * The class name of the Java function had been updated to MyStack instead of Stack.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and all test cases.
 *               
 **********************************************************************************/
 // As Queue is FIFO, it is useless to reverse it as stack(the result is the same after reverse)
 // front access the oldest item, back access the newest item.
 class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
       s1.push(x); 
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!s1.empty()){
            int len = s1.size()-1;
            while(len-- > 0){                             // make it as LIFO
                s1.push(s1.front());                      // won't affect next operation??
                s1.pop();
            }
            s1.pop();
        }
    }

    // Get the top element.
    int top() {
       return s1.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return s1.empty();
    }
    private: 
    queue<int> s1; 
};
