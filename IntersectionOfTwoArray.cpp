// Date: 2016-06-18
// ref: https://leetcode.com/problems/intersection-of-two-arrays/

/*****************************************************************
* Given two arrays, write a function to compute their intersection.
*
* Example:
* Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*
* Note:
* Each element in the result must be unique.
* The result can be in any order.
******************************************************************/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> val(nums1.begin(),nums1.end());
        vector<int> result;
        
        for(int i = 0; i < nums2.size(); i++)
            if (val.count(nums2[i])){
                result.push_back(nums2[i]);
                val.erase(nums2[i]);
            }
        return result;
    }
};
