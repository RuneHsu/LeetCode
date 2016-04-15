// Source: https://leetcode.com/problems/remove-element/
// Date: 2016-04-15
/********************************************************************************** 
* 
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
* 
*               
**********************************************************************************/
// my own stupid solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int count = 0,begin = 0;
        bool start = true;
        for(int i=0; i<size; i++){
            if (nums[i]==val ){
                if (start){
                    start = false;
                    begin = i;
                    count++;
                } else{
                    count++;
                }
            }
        }
        if(count!=0){
        for(int i=0; i<count; i++){
            for(int j=begin; j<size; j++){
                nums[j] = nums[j+1];
            }
        }
        for(int i=0; i<count; i++){
         nums[size-1-i] = 0;
        }
        }
        return size-count;
    }
};

// normal solution
class Solution{
    public:
    int removeElement(vector<int>& nums, int val) {
        int pos=0;                       // another pointer to index the position when found the value
        for(int i=0; i<nums.size(); i++){
            if (nums[i]!=val){
                nums[pos++] = nums[i];            // when the element is not the value, keep increase it
            }
        }
        return pos;
    }
};
