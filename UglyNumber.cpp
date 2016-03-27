// Source: https://leetcode.com/problems/ugly-number/
// Date: 2016-03-27
/*****************************************************************
* Write a program to check whether a given number is an ugly number.
*
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
* For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
*
* Note that 1 is typically treated as an ugly number.
********************************************************************/
// stupid recursive way
class Solution {
public:
    bool isUgly(int num) {
        if (num == 1) return true;
        if (num == 0) return false;
        if (num%2==0){
            return isUgly(num/2);
        } else if(num%3==0){
            return isUgly(num/3);
        } else if(num%5==0){
            return isUgly(num/5);
        } else{
            return false;
        }
        
    }
};

//Non-recursive way
class Solution{
public:
    bool isUgly(int num){
    if (num == 1) return ture;
    if (num == 0) return false;
    while (num%2==0) num /= 2;
    while (num%3==0) num /= 3;
    while (num%5==0) num /= 5;
    return num==1;
  }
}

class Solution{
public:
    bool isUgly(int num){
    if (num==0) return false;
    for(const auto&i: {2,3,5}){
        while(num%i==0){
        num /= i;
      }
    }
    return num==1;
  }
}
