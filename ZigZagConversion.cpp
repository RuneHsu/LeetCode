// Date: 27-06-2016
// ref: https://leetcode.com/problems/zigzag-conversion/

/************************************************************
* The string "PAYPALISHIRING" is written in a zigzag pattern
* on a given number of rows like this: (you may want to 
* display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this 
* conversion given a number of rows:
*
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**************************************************************/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        int len = s.size();
        int step = 0;
        int row = 0;
        string *result = new string[numRows];
        for (int i = 0; i < len; i++){
            result[row].push_back(s.at(i));            // put the character into each row of result;
            
            if (row == 0)
                step = 1;         // if reach the top, then decrease the row untill it reach the bottom
            else if (row == numRows - 1)
                step = -1;        // reach the bottom, reverse the trend
                
            row += step;
        }
        s.clear();     
        for (int i = 0; i < numRows; i++){
            s.append(result[i]);
        }
        delete[] result;
        return s;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows==1)
            return s;
        int step1,step2;
        int len=s.size();
        for(int i=0;i<numRows;++i){
            step1=(numRows-i-1)*2;
            step2=(i)*2;
            int pos=i;
            if(pos<len)
                result+=s.at(pos);
            while(1){
                pos+=step1;
                if(pos>=len)
                    break;
                if(step1)
                    result+=s.at(pos);
                pos+=step2;
                if(pos>=len)
                    break;
                if(step2)
                    result+=s.at(pos);
            }
        }
        return result;
    }
};

// According to https://segmentfault.com/a/1190000005751185
class Solution{
    
    public:
    
    void fill(string &str, int start, int initialDistance, int magic, string s){
        while (start < s.size()){
            if (initialDistance == 0)
                initialDistance = magic;
            str.insert(str.end(),s[start]);
            start += initialDistance;
            initialDistance = magic - initialDistance;
        }
    }
    
    string convert(string s, int numRows){
        if (numRows <= 1)
        return s;
        
        string str = "";
        int magic = numRows*2 - 2;
        int initialDistance = magic;
        
        for (int i = 0; i < numRows; i++){
            fill(str, i, initialDistance, magic, s);
            initialDistance = initialDistance - 2;
        }

        return str;
    }
};
