// Source: https://leetcode.com/problems/excel-sheet-column-number/
// Date: 2016-03-21
/**********************************************************************
*Given a column title as appear in an Excel sheet, return its corresponding column number.
*
*For example:
*
*    A -> 1
*    B -> 2
*    C -> 3
*    ...
*    Z -> 26
*    AA -> 27
*    AB -> 28 
***********************************************************************/

class solution{
public:
  int TitleToNumber(string s){
    int i,colNum=0;
    for(const auto&c: s){
      colNum = colNum*26 + (tolower(c)-'a'+1);
    }
    return colNum;
  }
}


// related question
// Source: https://leetcode.com/problems/excel-sheet-column-title/
// Date: 2016-03-21
/**************************************************************************
*Given a positive integer, return its corresponding column title as appear in an Excel sheet.
*
*For example:
*
*   1 -> A
*    2 -> B
*    3 -> C
*    ...
*    26 -> Z
*    27 -> AA
*    28 -> AB 
*****************************************************************************/

class solution{
pubic:
 string convertToTitle(int n){
 string Title="";
    while(n>0){
      Title = (char)(65+(n-1)%26) + Title;  // the ascii value of 'A' is 65, 'a' is 97
      n = (n-1)/26;
    }
    return Title;
  }
}


/********************another nice solution*****************/
// From: https://helloacm.com/cc-coding-exercise-excel-sheet-column-number-and-title-conversion/

class Solution {
public:
    int titleToNumber(string s) {
        int r = 0;
        for (int i = 0; i < s.length(); i ++) {
            r = r * 26 + s[i] - 64;
        }
        return r;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string r = "";
        while (n > 0) {
            r = (char)(65 + (n - 1) % 26) + r;
            n = (n - 1) / 26;
        }
        return r;
    }
};

