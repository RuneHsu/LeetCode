// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Date: 2016-04-14
/***************************************************************************************
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
* Design an algorithm to find the maximum profit. You may complete as many transactions 
* as you like (ie, buy one and sell one share of the stock multiple times) with the 
* following restrictions:
*
* You may not engage in multiple transactions at the same time (ie, you must sell the 
* stock before you buy again).
* After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
* Example:
*
* prices = [1, 2, 3, 0, 2]
* maxProfit = 3
* transactions = [buy, sell, cooldown, buy, sell]
*
***************************************************************************************/
// ref: https://leetcode.com/discuss/71354/share-my-thinking-process
class Solution{
public:
  int maxProfit(vector<int>& prices){
  int buy(INT_MIN), sell(0), pre_sell(0), pre_buy;
  
  for(const auto&i: prices){
   pre_buy = buy;
   buy = max(pre_buy, pre_sell-i);
   
   pre_sell = sell;
   sell = max(pre_sell, pre_buy+i);
   }
   return sell;
  }
};
