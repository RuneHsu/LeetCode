// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Date: 2016-04-13

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete as many transactions 
* as you like (ie, buy one and sell one share of the stock multiple times). However, 
* you may not engage in multiple transactions at the same time (ie, you must sell the 
* stock before you buy again).
*               
**********************************************************************************/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        
        bool up = false, down = false;
        int begin = 0, end = 0, profit = 0;
        
        for (int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1] && up == false){ // trending is going up, find the bottom of trending \/
                up = true;
                down = false;
                begin = i-1;
            }
            if(prices[i]<prices[i-1] && down == false){ // trending is going down, find the peak of trending /\***
                end = i-1;
                down = true;
                up = false;
                profit += (prices[end]-prices[begin]);
            }
            
            
           
        }
        
         // edge case
        if (begin<prices.size() && up == true){
                end = prices.size()-1;
                profit += (prices[end]-prices[begin]);
        }
        return profit;
    }
  };
