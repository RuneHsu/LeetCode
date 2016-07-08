// Date: 08-07-2016
// ref: https://leetcode.com/problems/single-number/

/*********************************************************
* Given an array of integers, every element appears twice
* except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity.
* Could you implement it without using extra memory?
**********************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> res;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
                res[nums[i]]++;
        }
        
        for (auto i = res.begin(); i != res.end(); i++)
        {
            if (i->second == 1)
                {
                  result =  i->first;
                  break;
                }
        }
        return result;
    }
};


class Solution{
public:
    int singleNumber(vector<int>& nums){
    int res = 0; 
    for (int i = 0; i < nums.size(); i++)
        res ^= nums[i];                     // x ^ 0 = x, x ^ x = 0;
    return res;
    }
};
