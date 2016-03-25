// Source: https://leetcode.com/problems/majority-element/
// Date: 2016-03-25
/****************************************************************************************************************************
*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
*
*You may assume that the array is non-empty and the majority element always exist in the array.
*****************************************************************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count,i,MajNum;
        if (nums.size()==1){
            return nums[0];
        }
        MajNum = nums[0];
        count = 1;
        for (i=1; i<nums.size();i++){
            if (nums[i]==MajNum){
                count++;
                if (count>floor(nums.size()/2)){
                    return MajNum;
                } 
            }else{
                    MajNum = nums[i];
                    count = 1;
            }
        }
    }
};


/************** Another solution (C version) ***************/
// Source: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/majority-element.cpp
// Ref: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
int majorityElement(int* nums, int numsSize) {
    int cnt, ans,i;
    cnt = 1;
    ans = nums[0];
    for(i=0; i< numsSize;i++){
        if(nums[i]==ans){
            cnt++;
        } else{
            cnt--;
            if (cnt == 0){
                ans = nums[i];
                cnt = 1;
            }
        }
    }
    return ans;
}
