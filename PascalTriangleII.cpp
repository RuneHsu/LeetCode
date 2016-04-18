// Source: https://leetcode.com/submissions/detail/59346121/
// Date: 2016-04-18
/********************************************************************************** 
* 
* Given an index k, return the kth row of the Pascal's triangle.
* 
* For example, given k = 3,
* Return [1,3,3,1].
* 
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
* 
*               
**********************************************************************************/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> result(rowIndex+1);
        
        for (int i=0; i<result.size(); i++){
            int prev_result = result[0] = 1;
            for(int j=1; j<=i; j++){
                int tmp = result[j];                     // T[i][j] = T[i-1][j-1]+T[i-1][j], tmp is recording the T[i-1][j]
                result[j] += prev_result;                // prev_result is recording the T[i-1][j-1]
                prev_result = tmp;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> result(rowIndex+1);
        result[0] = 1;
        
        for (int i=1; i<result.size(); i++){
            for(int j=i; j>=1; j--){
                                                          // Backforward, result[j] = result[j]+reslut[j-1],
                result[j] += result[j-1];                
                
            }
        }
        return result;
    }
};

// Combination way
/****************************************************************************************************
* 1) At Nth row, each k-th element is determined by a well-known formula: C(n, k) = n! / (k!*(n-k)!). 
* comb(k,p) = k! /( p! *(k-p)!) = comb(k,k-p)
*
* if p < k-p
*
* comb(k,p) = comb(k,p-1) * (k-p+1) / p
*
* 2) A row in Pascal triangle is always symmetric
***************************************************************************************************/
class Solution{
    public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        result[0] = result[rowIndex] = 1;
        for (int i=1; i<((rowIndex+2)/2); i++){
            result[i] = result[rowIndex-i] = (unsigned long)result[i-1]*(unsigned long)(rowIndex-i+1)/i;
        }
        return result;
    }
};
