// Date: 2016-06-18
// ref: https://leetcode.com/problems/intersection-of-two-arrays-ii/
/******************************************************************
* Given two arrays, write a function to compute their intersection.
*
* Example:
* Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
* 
* Note:
* Each element in the result should appear as many times as it shows 
* in both arrays.
* The result can be in any order.
* Follow up:
* What if the given array is already sorted? How would you optimize
* your algorithm?
* What if nums1's size is small compared to nums2's size? Which 
* algorithm is better?
* What if elements of nums2 are stored on disk, and the memory is 
*limited such that you cannot load all elements into the memory at once?
*********************************************************************/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> val1;
       vector<int> result;
       for(int i = 0; i < nums1.size() ; i++){
          val1[nums1[i]]++;
       }
      
      // slower
    //   for(auto i : nums1){
    //       val1[i]++;
    //   }
       
       for (int i = 0; i< nums2.size(); i++){
           if (--val1[nums2[i]] >= 0){
               result.push_back(nums2[i]);
           }
       }
       return result;
    }
};

// It is neccessary to have a look about this 
// ref: https://leetcode.com/discuss/103787/table-solution-pointers-solution-with-time-space-complexity
// and pay attention to the space complexity
