// Source: https://leetcode.com/problems/palindrome-number/
// Date: 2016-04-20
/********************************************************************************** 
* 
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* 
* Some hints:
* 
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
* 
*               
**********************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x!=0 && x%10==0)) return false;   // when x<0 && x is multiple of 10
        int rev_x=0;
        while (x>rev_x){                      // cut the num into 2 parts
            rev_x = rev_x*10 + x%10;
            x = x/10;
        }
        return (rev_x==x || x==rev_x/10);     // check the equal of them, pay attention to x has odd digits
    }
};

class Solution {
    public: 
        bool isPalindrome(int x) {
            if(x<0) return false;
            int d=1;
            for(;x>0; (x/d) >= 10,d = d*10);
           
            for (;x>0; x = (x%d)/10, d = d/100){       // x%d will delete the first digit then /10 will delete the last digit
                int left = x/d;
                int right = x%10;
                if (left != right) return false;
            }
            return true;
        }
};
