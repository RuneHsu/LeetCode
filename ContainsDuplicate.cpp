// Source: https://leetcode.com/problems/contains-duplicate/
// Date: 2016-03-22
/**********************************************************************************
*Given an array of integers, find if the array contains any duplicates. 
*Your function should return true if any value appears at least twice in the array, 
*and it should return false if every element is distinct.
***********************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        sort(nums.begin(),nums.end());
        int i,preNum,dupNum=0;
        preNum = nums[0];
        for(i=1;i<nums.size();i++){
            if (nums[i]==preNum){
                dupNum++;
                break;
            } else{
                preNum = nums[i];
            }
        }
        if(dupNum){
            return true;
        } else{
            return false;
        }
    }
};

/***************Other solution*********************/
// Source: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/contains-duplicate.cpp

class solution{
public:
   bool containsDuplicate(vector<int>& nums){
    sort(nums.begin(),nums.end());
    unordered_set<int> num_set(nums.begin(),nums.end());      // unordered_set unique the nums
    return (num_set.size() != nums.size());
  }
}

class solution{
public:
  bool containsDuplicate(vector<int>& nums){
    sort(nums.begin(),nums.end());
    return unique(nums.begin(),nums.end()) != nums.end();
  }
}
