// Source: https://leetcode.com/problems/isomorphic-strings/
// Date: 2016-04-27

/*************************************************************************
* Given two strings s and t, determine if they are isomorphic.
*
* Two strings are isomorphic if the characters in s can be replaced to get t.
*
* All occurrences of a character must be replaced with another character while 
* preserving the order of characters. No two characters may map to the same 
* character but a character may map to itself.
*
* For example,
* Given "egg", "add", return true.
*
* Given "foo", "bar", return false.
*
* Given "paper", "title", return true.
*
* Note:
* You may assume both s and t have the same length.
***********************************************************/
// the most important thing is to check the previous duplicate letter whether in the same position
// ref: https://leetcode.com/discuss/33854/my-6-lines-solution

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.size()!=t.size()) return false;
        
        vector<int> smap(256,-1);            // initialize to be -1 to avoid misjudge when s == t == NULL
        vector<int> tmap(256,-1);
    
        for(int i=0; i<s.size(); i++){      
            
            if(smap[s[i]] != tmap[t[i]]) return false;            // make a hashtable and check if the previous duplicated     
                                                                  // character is in the same position
            smap[s[i]] = tmap[t[i]] = i;
        }
        return true;
    }
};
