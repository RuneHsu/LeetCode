// Date: 2016-06-18
// ref: https://leetcode.com/problems/add-binary/

/*******************************************************************
* Given two binary strings, return their sum (also a binary string).
*
* For example,
* a = "11"
* b = "1"
* Return "100".
*********************************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int c = 0;  // carrier
        int  i = a.size()-1, j = b.size()-1;
        
        while (i >= 0 || j >= 0 || c == 1)    // either a or b has value, or c still carried a value
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            result = (char)( c % 2 + '0') + result;
            c /= 2;
        }
        return result;
    
    }
};
