class Solution {
public:

    int helper(vector<int> &coins,vector<vector<int>> &dp, int amount, int i, int n){
        if(amount == 0){
            return  dp[i][amount]=0;
        }
        if(i < 0 || amount < 0){
            return INT_MAX - 1;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        else{
            int withoutCoin, withCoin = INT_MAX - 1;
            withoutCoin = helper(coins,dp, amount, i - 1, n);
            if(amount >= coins[i]){
                withCoin = 1 + helper(coins,dp, amount - coins[i], i, n);
            }
            return dp[i][amount] = min(withCoin, withoutCoin);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        helper(coins,dp, amount, n-1, n);
        int ans = dp[n-1][amount];
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};