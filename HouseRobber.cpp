// Source: https://leetcode.com/problems/house-robber/
// Date: 2016-04-01
/********************************************************************************** 
 * 
 * You are a professional robber planning to rob houses along a street. Each house has 
 * a certain amount of money stashed, the only constraint stopping you from robbing 
 * each of them is that adjacent houses have security system connected and it will 
 * automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house, 
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 *               
 **********************************************************************************/
 
 /*
 * Dynamic Programming
 *
 * We can easy find the recurive fomular:
 *
 *     dp[n] = max( 
 *                    dp[n-1],   // the previous house has been robbed. 
 *                    dp[n-2] + money[n]  // the previous house has NOT been robbed.
 *                )
 */
 
 class Solution {
public:
    int rob(vector<int>& nums) {
      int n1 = 0;   // dp[i-1]
      int n2 = 0;   // dp[i-2]
     
      for (int i = 0; i< nums.size(); i++){
          int current = max(n1, n2 + nums[i]);   
          n2 = n1;
          n1 = current;
      }
      return n1;
    }
};


// Thought: Can use greedy algorithm, that sort the money in descending way. Then pick the maximum by checking the order...
// of it is adjacent to the previous picked. But in this way, we need record the order when we sort the money and need compare
// with the picked ones, quite time consuming.
