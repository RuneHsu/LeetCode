// Source: https://leetcode.com/problems/reverse-string/
// Date: 2016-04-24
/******************************************************************************
* Write a function that takes a string as input and returns the string reversed.
*
* Example:
* Given s = "hello", return "olleh".
********************************************************************************/

class Solution {
public:
    string reverseString(string s) {
        string rev_s = "";
        for (const auto&i: s){
            rev_s.insert(rev_s.begin(),i);
        }
        return rev_s;
    }
};
