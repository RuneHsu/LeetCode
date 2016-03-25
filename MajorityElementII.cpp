// Source: 
// Date: 2016-03-25
/********************************************************************************
*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*The algorithm should run in linear time and in O(1) space.
*********************************************************************************/


class Solution {
public:
     vector<int> majorityElement(vector<int>& nums) {
     unordered_map<int,int> count;
     vector<int> result;
     int n = nums.size();
     for (auto it: nums){
         count[it]++;
         if(count[it]>n/3){
             result.push_back(it);
             count[it] = -n;  // make sure this element won't be counted again
         }
     }
     return result;
  }
}

// At most has 2 majority elements
class Solution{
public:
  int cnt01,cnt02,ans01,ans02,n;
    n = nums.size();
    cnt01 = 0;
    cnt02 = 0;
    ans01 = 0;
    ans02 = 0;
    if(nums.size()<=1) return nums;
    for (auto it:nums){
        if (cnt01 == 0 && ans02 != it){
            ans01 = it;
            cnt01++;
        } else if(ans01 == it){
            cnt01++;
        } else if(cnt02 == 0){
            ans02 = it;
            cnt02++;
        } else if(ans02 == it){
            cnt02++;
        } else {
            cnt01--;
            cnt02--;
        }
    }
    cnt01 = 0;
    cnt02 = 0;
    for (auto it:nums){
        if (it==ans01) cnt01++;
        else if (it==ans02) cnt02++;
    }
    vector<int> result;
    if(cnt01>n/3) result.push_back(ans01);
    if(cnt02>n/3) result.push_back(ans02);
    return result;
  }
}



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k = 3;
        const int n = nums.size();
        unordered_map<int, int> hash;

        for (const auto& i : nums) {
            ++hash[i];
            // Detecting k items in hash, at least one of them must have exactly
            // one in it. We will discard those k items by one for each.
            // This action keeps the same mojority numbers in the remaining numbers.
            // Because if x / n  > 1 / k is true, then (x - 1) / (n - k) > 1 / k is also true.    don't understand this part!!!
            if (hash.size() == k) {
                auto it = hash.begin();
                while (it != hash.end()) {
                    if (--(it->second) == 0) {
                        hash.erase(it++);
                    } else {
                        ++it;
                    }
                }
            }
        }

        // Resets hash for the following counting.
        for (auto& it : hash) {
            it.second = 0;
        }

        // Counts the occurrence of each candidate integer.
        for (const auto& i : nums) {
            auto it = hash.find(i);
            if (it != hash.end()) {
                ++it->second;
            }
        }
        
        // Selects the integer which occurs > [n / k] times.
        vector<int> ret;
        for (const pair<int, int>& it : hash) {
            if (it.second > n / k) {
                ret.emplace_back(it.first);
            }
        }
        return ret;
    }
};
