// Source: https://leetcode.com/problems/valid-anagram/
// Date: 2016-03-20
/*********************************************************
*Given two strings s and t, write a function to determine if t is an anagram of s.
*
*For example,
*s = "anagram", t = "nagaram", return true.
*s = "rat", t = "car", return false.
************************************************************/


class solution{
public:
  bool isAnagram(string s, sting t){
  if (s.size() != t.size()) return false;
  
  unordered_map <char,int> count;
  for (const auto&c: s){
    ++count[tolower(c)];
  }
    
  for (const auto&c: t){
    --count[tolower(c)];
    if (count[tolower(c)] < 0) return false;   // why < 0 instead of != 0??
  }
  
  return true;
  }
}

class solution2{
public: 
  bool isAnagram(string s, string t){
  if (s.size() != t.size()) return false;
  
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  
  return s==t ? true: false;
  }
  }
