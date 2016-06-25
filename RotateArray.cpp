// Date: 25-06-2016
// ref: https://leetcode.com/problems/rotate-array/

/*******************************************************
* Rotate an array of n elements to the right by k steps.
*
* For example, with n = 7 and k = 3, the array 
* [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*
* Note:
* Try to come up as many solutions as you can, there 
* are at least 3 different ways to solve this problem.
*******************************************************/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
        return;
        
        int n = nums.size();
        vector<int> numscopy;
        for (int i = 0; i < n; i++){
            numscopy.push_back(nums[i]);
        }
        
        for (int i = 0; i < n; i++){
            nums[(i+k)%n] = numscopy[i];
        }
    }
};

// more solution ref: https://leetcode.com/discuss/27387/summary-of-c-solutions
