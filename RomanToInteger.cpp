// Source: https://leetcode.com/problems/roman-to-integer/
// Date: 2016-03-28
/***************************************************************
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * **************************************************************/
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
       int res = 0;
       vector<int> val;
       for(const auto&i: s){
         if (i == 'M')  val.push_back(1000);
         if (i == 'D')  val.push_back(500);
         if (i == 'C')  val.push_back(100);
         if (i == 'L')  val.push_back(50);
         if (i == 'X')  val.push_back(10);
         if (i == 'V')  val.push_back(5);
         if (i == 'I')  val.push_back(1);
       }
       int i = 0;
       while ( i<val.size()){
           if(val[i+1]>val[i] && i!= val.size()-1){
               res += (val[i+1]-val[i]);
               i += 2;
           } else {
               res += val[i];
               i++;
           }
       }
       return res;
    }
};
