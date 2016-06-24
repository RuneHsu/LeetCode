// Date: 24-06-2016
// ref: https://leetcode.com/problems/min-stack/

/*************************************************
* Design a stack that supports push, pop, top, and
* retrieving the minimum element in constant time.
*
* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.
* Example:
* MinStack minStack = new MinStack();
* minStack.push(-2);
* minStack.push(0);
* minStack.push(-3);
* minStack.getMin();   --> Returns -3.
* minStack.pop();
* minStack.top();      --> Returns 0.
* minStack.getMin();   --> Returns -2.
***************************************************/

class MinStack {
    private:
        stack<int> val;
        stack<int> min;
    public:
    /** initialize your data structure here. */
    void push(int x) {
        val.push(x);
        if (min.empty() || min.top() >= x)
            min.push(x);
    }
    
    void pop() {
        if (val.top() == getMin()){
            min.pop();
        }
        val.pop();
    }
    
    int top() {
        return val.top();
    }
    
    int getMin() {
        return min.top();
    }
};


// my stupid version 

//class MinStack {
//private:
//    vector<int> val;
//    // vector ;
//public:
//    /** initialize your data structure here. */
//    
//    // MinStack() {
//    //     vector<int> val;
//    // }
//    
//    void push(int x) {
//        val.push_back(x);
//        //        if (minimum > x)
//        //            minimum = x;
//        //        else
//        //
//    }
//    
//    void pop() {
//        if (!val.empty()){
//            val.pop_back();
//        }
//    }
//    
//    int top() {
//        if (!val.empty()){
//            int top = val.size() - 1;
//            return val.at(top);
//        }
//        return 0;
//    }
//    
//    int getMin() {
//        int min = INT_MAX;
//        if (!val.empty()){
//            for (int i = 0; i < val.size(); i++){
//                if (min > val.at(i))
//                    min = val.at(i);
//            }
//            return min;
//        }
//        return min;
//    }
//    
//    void size(){
//        for (int i = 0; i < val.size(); i++){
//            cout << val.at(i) << " ";
//        }
//        cout << endl;
//    }
//};
