// Source: https://leetcode.com/problems/valid-parentheses/
// Date: 2016-04-28
/*****************************************************************
* Given a string containing just the characters '(', ')', '{', '}', 
* '[' and ']', determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" 
* are all valid but "(]" and "([)]" are not.
******************************************************************/

class Solution {
    public:
    bool isValid(string s) {
    stack<char> st;
    for(char c : s){
        if(c == '('|| c == '{' || c == '['){
            st.push(c);
        }else{
            if(st.empty()) return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            if(c == ')' && st.top() != '(') return false;
            st.pop();
        }
    }
    return st.empty();
    }
};
