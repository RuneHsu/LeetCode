// Source: https://leetcode.com/problems/count-and-say/
// Date: 2016-05-01

/****************************************************************************
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...
*
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* Given an integer n, generate the nth sequence.
*
* Note: The sequence of integers will be represented as a string.
******************************************************************************/
// An interesting proof that count can not larger than 4: https://leetcode.com/discuss/6762/how-to-proof-the-count-is-always-less-than-10
class Solution {
public:
    string countAndSay(int n) {
        if (n==0) return "";
        string res = "1";
        
        while(--n) {
            string cur;
            for (int i=0; i<res.size(); i++){
                int count = 1;
                while (i+1 < res.size() && res[i]==res[i+1] ){   // calculate the times this number appearance until next diff number
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];                   // read as Counted Number
            }
            res = cur;               // update the previous digits
        }
        return res;
    }
};
