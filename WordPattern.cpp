// Source: https://leetcode.com/problems/word-pattern/
// Date: 2016-04-30

/*********************************************************************
* Given a pattern and a string str, find if str follows the same pattern.
*
* Here follow means a full match, such that there is a bijection between 
* a letter in pattern and a non-empty word in str.
*
* Examples:
* pattern = "abba", str = "dog cat cat dog" should return true.
* pattern = "abba", str = "dog cat cat fish" should return false.
* pattern = "aaaa", str = "dog cat cat dog" should return false.
* pattern = "abba", str = "dog dog dog dog" should return false.
* Notes:
* You may assume pattern contains only lowercase letters, and str contains 
* lowercase letters separated by a single space.
*************************************************************************/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for(string word; in >> word; i++){
          if (i == n || p2i[pattern[i]] != w2i[word]){    // Because i can actually become n, and then without that check, I'd access pattern[n], possibly even pattern[n+1] and more, which is invalid and thus dangerous. Might even crash.
              return false;
          }  
          p2i[pattern[i]] = w2i[word] = i+1;               // avoid the map default value 0, the important thing is to check if it is the same as previous existed word
        }
         return i == n;
    }
};

class Solution {
    public:
    bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
                s2c[vs[i]] = pattern[i]; 
                c2s[pattern[i]] = vs[i]; 
                continue; 
            }
            if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }
};
class Solution {
    public:

bool wordPattern(string pattern, string str) 
{
    istringstream ss(str);
    string word;
    unordered_map<char, string> bmap;
    unordered_map<string, char>rbmap;

    for (char c : pattern)
    {
        if (! (getline(ss, word, ' ')))
            return false;
        if ( bmap.emplace(c,word).first->second != word)
            return false;
        if (rbmap.emplace(word,c).first->second != c)
            return false;
    }
    return ! getline(ss, word, ' ');   
}
};
