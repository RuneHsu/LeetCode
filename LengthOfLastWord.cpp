// Source: https://leetcode.com/problems/length-of-last-word/
// Date: 2016-04-30

/***********************************************************************
* Given a string s consists of upper/lower-case alphabets and empty space 
* characters ' ', return the length of last word in the string.
*
* If the last word does not exist, return 0.
*
* Note: A word is defined as a character sequence consists of non-space 
* characters only.
* 
* For example, 
* Given s = "Hello World",
* return 5.
*************************************************************************/
class Solution {
    public:
 int lengthOfLastWord(const char* s) {
        int len = 0;
        while (*s) {
            if (*s++ != ' ')               // calculate the word length from the beginning
                ++len;
            else if (*s && *s != ' ')     // if word still be found in the following space, clear len and recal
                len = 0;

        }
        return len;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int count = 0;
        int i = s.size()-1;

        for(; i>=0; i--){
            
            if (s[i]!=' '){
                count++;
            } 
            
            if (s[i] == ' ' && count) {
                return count;
            }
    
        }
        
        return count;
    }
};


