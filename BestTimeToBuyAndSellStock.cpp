// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Date: 2016-04-13
/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
* design an algorithm to find the maximum profit.
*               
**********************************************************************************/
// ref: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/bestTimeToBuyAndSellStock/bestTimeToBuyAndSellStock.cpp
class Solution {
public:
    //
    // This solution is O(1) space dynamic programming 
    //
    // We can make sure the max profit at least be ZERO. So,
    //    1) we have two pointers (begin & end ) 
    //    2) if prices[end] - prices[begin] >  0, then move the "end" pointer to next
    //    3) if prices[end] - prices[begin] <= 0, then move the "begin" pointer to current posstion.
    //    4) tracking the max profit
    //
    // Notes:
    //    Some people think find the highest-price & lowest-price, this is wrong. 
    //    Because the highest-price must be after lowest-price
    //
    int maxProfit(vector<int> &prices) {
        
        int max=0, begin=0, end=0, delta=0;
        
        for (int i=0; i<prices.size(); i++) {
            
            end = i;
            
            delta = prices[end] - prices[begin];
            
            if (delta <= 0){
                begin = i;
            }
            
            if ( delta > max ){
                max = delta;
            }
            
        }
               return max;
        
    }
};


// Another solution
class Solution{
    public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()){
            return 0;
        }
        
        int hold = numeric_limits<int>::min();
        int release = numeric_limits<int>::min();
        
        for(const auto&i: prices){
            hold = max(hold,-i);   // hold will be i that has the smallest value
            release = max(release,i+hold);       // release record the profit for buy on hold and sell on i
        }
        return release;
    }
};

// Intuitive solution
class Solution{
    public:

int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}
};
