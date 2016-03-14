// Source:https://leetcode.com/problems/move-zeroes/
// Date: 2016-03-14

/******************************
*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements
*For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
*
*Note:
*1. You must do this in-place without making a copy of the array.
*2. Minimize the total number of operations.
****************************************************/

/*************A stupy but intuitive version*******************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i,j,length,count=0;
        length = nums.size();
        for (i=0;i<length;i++){    
            if (nums[i] == 0){    // if an element is zero
                count = 1;
                for (j=i+1;j<length-1;j++){ // find the first non-zero number in the following elements
                    
                    if (nums[j] == 0){    
                        count++;            // calculate the number of succesive zeros
                    } else break;
                }
                for (j=i;j<length-count;j++){
                    nums[j] = nums[j+count];
                }
                for (j=1;j<=count;j++){
                    nums[length-j] = 0;
                }
            }
        }
    }
};
