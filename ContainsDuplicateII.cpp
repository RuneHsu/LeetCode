// Source: https://leetcode.com/problems/contains-duplicate-ii/
// Date: 2016-03-22
/************************************************************************************
*Given an array of integers and an integer k, find out whether there are two distinct 
*indices i and j in the array such that nums[i] = nums[j] and the difference between i 
*and j is at most k.
**************************************************************************************/

class solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> num_set(nums.begin(),nums.end());
        if (num_set.size()==nums.size()) return false;
        int i,j;
        for (i=0;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++){
                if (nums[i]==nums[j] && abs(i-j)<=k) return true;
            }
        }
        return false;
    }
};

/*****************Another solution*************/
// Source: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/contains-duplicate-ii.cpp

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.find(nums[i]) == lookup.end()) {    // check the element existed or not
                lookup[nums[i]] = i;
            } else {
                // If the value occurs before, check the difference.
                if (i - lookup[nums[i]] <= k) {
                    return true;
                }
                // Update the index of the value.
                lookup[nums[i]] = i;
            }
        }
        return false;
    }
};
