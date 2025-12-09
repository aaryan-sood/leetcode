class Solution {
public:

    int helper(vector<int> &coins, vector<vector<int>> &dp, int amount, int index, int n){
        if(amount == 0){
            return 1;
        }
        if(amount < 0 || index >= n){
            return 0;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        
        int withCoin = 0, withoutCoin;
        if(amount >= coins[index]){
            withCoin = helper(coins, dp, amount - coins[index], index , n);
        }
        withoutCoin = helper(coins, dp, amount, index + 1, n);
        return dp[index][amount] = withCoin + withoutCoin;
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));

        return helper(coins, dp, amount, 0, n);
    }
};