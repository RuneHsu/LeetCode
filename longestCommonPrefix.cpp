// Source: https://leetcode.com/problems/longest-common-prefix/
// Date: 2016-05-07

/***********************************************************
* Write a function to find the longest common prefix string 
* amongst an array of strings.
************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size()==0) return prefix;
        
        for(int k = 0; k < strs[0].size(); k++){       // use the first word as foundation to check the remainning words
                                                      // whether have the same element at each position
            int i = 1;
            for(; i<strs.size() && strs[i].size()>k; i++){   // make sure won't exceed the length of vector and the word
                if (strs[i][k]!=strs[0][k]){              // if not match, return
                    return prefix;
                }
            }
            if (i == strs.size()) prefix += strs[0][k];      // if all the word have the same element, add it into the prefix
        }
        
        return prefix;
         
    }
};

class TrieNode{
public:
    bool val;
    TrieNode* next[52];
    int sons;
    TrieNode() :val(false), sons(0)
    {
        for (int i = 0; i < 52; i++)
            next[i] = nullptr;
    }
};
class Trie{
private:
    TrieNode* putst(string& s, TrieNode * node, int loc, TrieNode *father)
    {
        if (s.length() == 0)
        {
            node->val = true;
            node->sons++;
            return node;
        }
        if (node == nullptr)
        {
            node = new TrieNode();
            if (father != nullptr)
                father->sons++;
        }
        if (loc == s.length())
        {
            node->val = true;
            return node;
        }
        if (s[loc] >= 'a')
            node->next[s[loc] - 'a'] = putst(s, node->next[s[loc] - 'a'], loc + 1, node);
        else           
            node->next[s[loc] - 'A' + 26] = putst(s, node->next[s[loc] - 'A' + 26], loc + 1, node);
        return node;
    }
public:
    TrieNode *root;
    void insert(string & str){ putst(str, root, 0, nullptr); }
    Trie(){ root = new TrieNode(); }
};
class Solution {
private:
    string findPre(TrieNode * node)
    {
        if (node == nullptr || (node != nullptr&&node->sons > 1))
            return string("");
        int i = 0;
        for (i = 0; i < 52; i++)
        {
            if (node->next[i] != nullptr)
                break;
        }
        if (i == 52)
            return string("");
        char temp1 = ((i>25) ? ('A' + i) : ('a' + i));
        string temp;
        temp.insert(temp.begin(), temp1);
        if (node->val)
        {
            return string("");
        }
        else
        {
            return temp + findPre(node->next[i]);
        }
    }
    public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie a;
        for (auto& str : strs)
            a.insert(str);
        return findPre(a.root);
    }
};
