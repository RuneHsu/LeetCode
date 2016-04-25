// Source: https://leetcode.com/problems/merge-sorted-array/
// Date: 2016-04-25

/*******************************************************************************************
* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*
* Note:
* You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold 
* additional elements from nums2. The number of elements initialized in nums1 and nums2 are m 
* and n respectively.
*********************************************************************************************/
// ref: https://leetcode.com/discuss/8233/this-is-my-ac-code-may-help-you

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(j >= 0){
            if (nums1[i] < nums2[j]|| i<0){     // check the nums backforward, largest---->smallest, also consider if n is                                         larger than m
                nums1[k--] = nums2[j--];         // find the largest one and put it into the tail, then decrement the index
            } else {
                nums1[k--] = nums1[i--];
            }
        }
    }
};
