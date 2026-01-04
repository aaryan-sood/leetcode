// problem link
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:

    int helper(vector<vector<int>> &dp, vector<int> & prices, int index, int buy){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        else{

            if(buy){

                int bought = -prices[index] + helper(dp, prices, index + 1, 0);
                int notBought = helper(dp, prices, index + 1, 1);
                return dp[index][buy] = max(bought, notBought);

            }
            else{

                int sold = prices[index] + helper(dp, prices, index + 1, 1);
                int notSold = helper(dp, prices, index + 1, 0);
                return dp[index][buy] = max(sold, notSold);
            }
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return helper(dp, prices, 0, 1);
    }
};