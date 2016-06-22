// Date: 22-06-2016
// ref: https://leetcode.com/problems/two-sum/

/**********************************************
* Given an array of integers, return indices of 
* the two numbers such that they add up to a 
* specific target.
*
* You may assume that each input would have 
* exactly one solution.
*
* Example:
* Given nums = [2, 7, 11, 15], target = 9,
*
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // key is the number and value is its index
        unordered_map<int, int> hash;
        vector<int> result;
        
        for (int i = 0; i<nums.size(); i++){
            int numberToFind = target - nums[i];
            
            if (hash.find(numberToFind) != hash.end()){        // once find the match
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;                                 // exactly one solution
            }
            
            hash[nums[i]] = i;                                 // if not find, put it into hash table
        }
        
        return result;
    }
};

// more efficiency
class Solution{
    public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> tmp = numbers;
        sort(tmp.begin(), tmp.end());
    int l = 0, r = (int) tmp.size() - 1;
    
    // find the values
    while (l < r) {  
        int mid = tmp[l] + tmp[r];
        if (mid == target)  
            break;
        if (mid < target) 
            ++l; 
        else 
            --r;
    }
    // match to the original indices
    int index1 = 0, index2 = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        if (numbers[i] == tmp[l]) 
        { 
            index1 = i; 
            break; 
            
        }
    }
    for (int i = (int)tmp.size() - 1; i >= 0; --i) {
        if (numbers[i] == tmp[r]) 
        { 
            index2 = i; 
            break; 
            
        }
    }

        if (index1 > index2) 
        { 
            index1 ^= index2; 
            index2 ^= index1; 
            index1 ^= index2;  
        }
        vector<int> result {index1 , index2 };
        return result;
}
};
