// Source: https://leetcode.com/problems/happy-number/
// Date: 2016-03-30
/********************************************************************************** 
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with any positive integer, 
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 
 * (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this 
 * process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 **********************************************************************************/

class Solution {
public:
    bool isHappy(int n) {
      set<int> record;   // record the numbers that has appear
      vector<int> sqVal;   // record the squares of digits
      bool loop = false;
     
     while(n != 1 ){
      record.insert(n);
      while( n!= 0 ){                  
          sqVal.push_back(pow(n%10, 2));
          n /= 10;
      }
      
      while(sqVal.size()>0){
          n += sqVal.back();
          sqVal.pop_back();
      }
      auto it = record.find(n);
      if (it != record.end()) {
          loop = true;
          return false;
      }
    }
    return true;
    }
};
