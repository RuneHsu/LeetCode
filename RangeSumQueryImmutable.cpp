// Date: 2016-06-20
// ref: https://leetcode.com/problems/range-sum-query-immutable/

/******************************************************************
* Given an integer array nums, find the sum of the elements between
* indices i and j (i ≤ j), inclusive.
*
* Example:
* Given nums = [-2, 0, 3, -5, 2, -1]
*
* sumRange(0, 2) -> 1
* sumRange(2, 5) -> -1
* sumRange(0, 5) -> -3
* Note:
* You may assume that the array does not change.
* There are many calls to sumRange function.
********************************************************************/

class NumArray {
private: 
vector<int> sum;
public:
    
    NumArray(vector<int> &nums) {
       
        for(int i = 0; i < nums.size(); i++){
            if (i == 0)  
            sum.push_back(nums[i]);
            else
            sum.push_back(sum.back() + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sum[j];
        return sum[j] - sum[i-1];
    }
};


// This version is faster than the previous one

class NumArray {
    public:
    NumArray(vector<int> &nums): psum(nums.size()+1, 0){     
        // because of move forward 1 step, don't need consider i == 0 at the below
        partial_sum(nums.begin(), nums.end(), (psum.begin()+1));
    }
    int sumRange(int i, int j){
        return psum[j+1] - psum[i];
    }
    
    private:
    vector<int> psum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
