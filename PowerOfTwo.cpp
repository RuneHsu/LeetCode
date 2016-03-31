// Source: https://leetcode.com/problems/power-of-two/
// Date: 2016-03-31
/********************************************************************************** 
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 *               
 *               
 **********************************************************************************/
 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n == 0) 
        return false;
        
        while(n){
            if (n == 1)
            return true;
            
            if (n%2!=0) return false;
            n /= 2;
        }
        
        return true;
    }
};

// More efficient solution
// the trick is 2^n can just have one '1' in bits. 
// 1--01, 2--10, 4--100, 8--1000

class Solution{
    public:
    bool isPowerOfTwo(int n){
     int cnt = 0;
     for(;n>0;n>>=1){
         if(n & 1){
             cnt++;
         }
         if (cnt>1) return false;
     }
     return cnt == 1;
    }
};


// Trick is: (2^n-1) is 1111..., so n & (n-1) == 0
class Solution{
    public:
    bool isPowerOfTwo(int n){
        return n <= 0 ? false : (n & (n-1)) == 0;
    }
};
