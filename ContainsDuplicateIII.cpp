// Source: https://leetcode.com/problems/contains-duplicate-iii/
// Date: 2016-03-22
/********************************************************************
*Given an array of integers, find out whether there are two distinct 
*indices i and j in the array such that the difference between nums[i] 
*and nums[j] is at most t and the difference between i and j is at most k.
*********************************************************************/

// Solution from: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/contains-duplicate-iii.cpp
// Time:  O(nlogk)
// Space: O(k)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0) {      
            return false;
        }
        
        queue<int64_t> window;      // use to contain the order of nums
        multiset<int64_t> bst;      // use to contain the content of nums, all the elements in set are sorted in a specific order
        for (int i = 0; i < nums.size(); ++i) {
            // Only keep at most k elements. Erase the oldest element
            if (bst.size() > k) {
                int num = window.front();             // extract the oldest element  
                window.pop();                         // pop out it
                bst.erase(bst.find(num));             // erase it
            }
            // Every search costs time: O(logn).
            const auto it = bst.lower_bound(nums[i] - t);         // find whether contains element... 
            if (it == bst.cend() || (*it - nums[i]) > t) {        // that the differece wrt nums[i] is less than t
                // Not found.
                window.emplace(nums[i]);                          // if not found, inset the nums[i] into the queue and multiset
                bst.emplace(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};

/******************* Another solution **************************/
// Solution from: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/containsDuplicate/ContainsDuplicate.III.cpp

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k <= 0) return false;
        int low = 0;        // use a counter to record the range
        //maintain a sliding window 
        set<long long> window;     // didn't use queue because it dosen't contain lower_bound
        for (int i=0; i<nums.size(); i++){
            //make sure window size <= k
            if (i - low > k) {
                window.erase(nums[low]);           // don't need to worry about the duplicate, if it happens return true.
                low++;
            }
            
            // lower_bound() is the key, 
            // it returns an iterator pointing to the first element >= val 
            auto it = window.lower_bound((long long)nums[i] - (long long)t );    // cause the it may be 0 due to lower_bound(negVal)?
            if (it != window.end() && abs((long long)nums[i] - *it) <= (long long)t) { // why still need the later condition?
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};

// Most important thing is to use the lower_bound of set data type.
