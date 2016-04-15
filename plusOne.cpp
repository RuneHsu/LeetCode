// Source: https://leetcode.com/problems/plus-one/
// Date: 2016-04-15
/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
*               
**********************************************************************************/
// ref: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/plus-one.cpp

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (auto i=digits.rbegin(); i!=digits.rend(); i++){
            *i = *i+carry;
            carry = *i/10;
            *i = *i%10;
        }
        
        if (carry == 1){
            digits.emplace(digits.begin(),carry);
        }
        return digits;
    }
};
