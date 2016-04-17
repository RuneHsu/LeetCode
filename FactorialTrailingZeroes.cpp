// Source: https://leetcode.com/problems/factorial-trailing-zeroes/
// Date: 2016-04-17
/********************************************************************************** 
 * 
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in polynomial time complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
// ref: http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/

class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
        for(long i=5; n/i>0 && i<=INT_MAX; i*=5){
            result += (n/i);
        }
        return result;
    }
};
