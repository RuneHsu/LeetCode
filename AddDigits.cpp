// Source : https://leetcode.com/problems/add-digits/
// Date: 2015-03-11

/********************************************************************************** 
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 * Follow up:
 * 	Could you do it without any loop/recursion in O(1) runtime?
 *
 **********************************************************************************/
 
 class solution{
 public:
    int addDigits(int num){
      switch(random()%5 + 1){
      case 1: return addDigits01(num);
      case 2: return addDigits02(num);
      case 3: return addDigits03(num);
      case 4: return addDigits04(num);
      case 5: return addDigits05(num);
      default: return addDigits05(num);
      }
      
      // need to be finished
    }
}
