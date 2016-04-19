// Source: https://leetcode.com/problems/power-of-four/
// Date: 2016-04-19
/***************************************************************************************
*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
*
*Example:
*Given num = 16, return true. Given num = 5, return false.
*
*Follow up: Could you solve it without loops/recursion?
******************************************************************************************/

//Using the concept of power of two
class Solution {
public:
    bool isPowerOfFour(int num) {
      //  method 1: 
      //return ( num> 0 && (num&(num-1)) == 0 && (num-1)%3==0);
      // method: 2
     return (num>0 && (num&(num-1)) ==0 && (num & 0b01010101010101010101010101010101) == num);
     // method 3:
     return (num>0 && int(log10(num)/log10(4))-log10(num)/log10(4)==0);
     // method 4:
     //while(num>0 && (num%4==0)){
     //   num /= 4;
     //}
     // return num == 1;
    }
};
