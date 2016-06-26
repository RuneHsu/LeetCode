// Date: 26-06-2016
// ref: https://leetcode.com/problems/compare-version-numbers/

/**************************************************************
* Compare two version numbers version1 and version2.
* If version1 > version2 return 1, if version1 < version2 
* return -1, otherwise return 0.
*
* You may assume that the version strings are non-empty and 
* contain only digits and the . character.
* The . character does not represent a decimal point and is used
* to separate number sequences.
* For instance, 2.5 is not "two and a half" or "half way to version 
* three", it is the fifth second-level revision of the second 
* first-level revision.
*
* Here is an example of version numbers ordering:
*
* 0.1 < 1.1 < 1.2 < 13.37
**************************************************************/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0,j = 0;
        int n1 = version1.size(), n2 = version2.size();
        int num1 = 0, num2 = 0;
        
        while (i < n1 || j < n2){
            while ( i < n1 && version1[i] != '.'){
                num1 = num1*10 + (version1[i] - '0');     // extract the number of version into num1
                i++;
            }
            
            while (j < n2 && version2[j] != '.'){
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            
            num1 = 0;                   
            num2 = 0; 
            i++;                   // skip the '.'
            j++;
        }
        return 0;
    }
};

class Solution{
    public:
    int compareVersion(string version1, string version2)
{
    int iLength1 = version1.size(), iLength2 = version2.size();
    string sVersion1, sVersion2;
    int iStart1 = 0, iStart2 = 0, iPoint1 = 0, iPoint2 = 0, iVersion1, iVersion2;
    while(iStart1 < iLength1 || iStart2 < iLength2)
    {
        if(iStart1 >= iLength1)
            iVersion1 = 0;
        else
        {
            iPoint1 = version1.find_first_of('.', iStart1);
            if(-1 == iPoint1)
                iPoint1 = iLength1;
            sVersion1.assign(version1, iStart1, iPoint1 - iStart1);
            iVersion1 = stoi(sVersion1);
        }
        if(iStart2 >= iLength2)
            iVersion2 = 0;
        else
        {
            iPoint2 = version2.find_first_of('.', iStart2);
            if(-1 == iPoint2)
                iPoint2 = iLength2;
            sVersion2.assign(version2, iStart2, iPoint2 - iStart2);
            iVersion2 = stoi(sVersion2);
        }
        if(iVersion1 > iVersion2)
            return 1;
        else if(iVersion1 < iVersion2)
            return -1;
        else
        {
            iStart1 = iPoint1 + 1;
            iStart2 = iPoint2 + 1;
        }
    }
    return 0;
}
};
class Solution{
    public:
    int compareVersion(string version1, string version2) {
    for(auto& w : version1) if (w == '.') w=' ';
    for(auto& w : version2) if (w == '.') w=' ';
    istringstream s1(version1), s2(version2);
    while(1) {
        int n1,n2;
        if (not(s1 >> n1) ) n1 = 0;
        if (not(s2 >> n2) ) n2 = 0;
        if (not s1 and not s2) return 0;
        if (n1<n2) return -1;
        if (n1>n2) return 1;
    }
}
};

