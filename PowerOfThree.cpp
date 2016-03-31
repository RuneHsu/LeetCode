// Source: https://leetcode.com/problems/power-of-three/
// Date: 2016-03-31
/*************************************************************************************** 
 *
 * Given an integer, write a function to determine if it is a power of three.
 * 
 *     Follow up:
 *     Could you do it without using any loop / recursion?
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/
 
 class Solution {
public:
    bool isPowerOfThree(int n) {
        double logRes = log10(n)/log10(3);        // didn't get it
        return (logRes - int(logRes) == 0);
    }
};

class Solution{
    public:
    int const Max3PowerInt = 1162261467; // 3^31-1, max is 2^32
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > Max3PowerInt) return false;
        return Max3PowerInt % n == 0;
        
    }
};
