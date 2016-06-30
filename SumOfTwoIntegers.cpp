// Date: 30-06-2016
// ref: https://leetcode.com/problems/sum-of-two-integers/

/*********************************************************
* Calculate the sum of two integers a and b, but you are 
* not allowed to use the operator + and -.
*
* Example:
* Given a = 1 and b = 2, return 3.
********************************************************/
// a use as accumulator and b as record of carry
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        
        while (b != 0)
        {
            sum = a ^ b;  // calculate sum of a and b without consider carry
            b = (a & b) << 1;   // calculate the carry, (a&b) calculate whether 
                                // at one bit generates a carry or not and shift it to right as carry;
            a = sum; // assign sum to a
        }
        return sum;
    }
};
