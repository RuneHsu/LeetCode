// Sourse: https://leetcode.com/problems/reverse-vowels-of-a-string/
// Date: 2016-04-24
/*************************************************************************************
* Write a function that takes a string as input and reverse only the vowels of a string.
*
* Example 1:
* Given s = "hello", return "holle".
*
* Example 2:
* Given s = "leetcode", return "leotcede".
****************************************************************************************/
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aiueoAIUEO";
        int found,found2, j = s.length()-1;
        
        for (int i=0; i<s.length();){
            
             found = vowels.find(s[i]);
             if (found!=-1){
                 for (; j>i;){
                   found2 = vowels.find(s[j]);
                   if (found2!=-1){
                     swap(s[i],s[j]); 
                     j--;
                     break;
                   }
                   j--;
                 }
             }
             if (i==j) break;
             i++;
            }
    return s;
    }
};
