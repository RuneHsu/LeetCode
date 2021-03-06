// Date: 23-06-2016
// ref: https://leetcode.com/problems/valid-palindrome/

/*****************************************************
* Given a string, determine if it is a palindrome, 
* considering only alphanumeric characters and 
* ignoring cases.
*
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
*
* Note:
* Have you consider that the string might be empty? 
* This is a good question to ask during an interview.
*
* For the purpose of this problem, we define empty 
* string as valid palindrome.
*****************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        
        int head = 0, tail = s.size() - 1;
        
            for (; head < tail; head++,tail-- ){
                while (!isalnum(s.at(head)) && head < tail){
                    ++head;
                }
                while (!isalnum(s.at(tail)) && tail > head)
                {
                    --tail;
                }
                if (toupper(s.at(head)) != toupper(s.at(tail)) )
                {
                    return false;
                }
            }
      return true;
    }
};
