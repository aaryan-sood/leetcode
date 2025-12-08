class Solution {
public:

    int helper(vector<int> &nums, vector<vector<int>> &dp, long int sum, int index, int curr, int target, int n){
        if(index == n){
            return dp[index][curr + sum] = target == curr ? 1 : 0;
        }
       if(dp[index][curr + sum] != -1){
            return dp[index][curr + sum];
       }
       else{
            int addition = helper(nums, dp, sum, index + 1, curr + nums[index], target, n);
            int subraction = helper(nums, dp, sum, index + 1, curr - nums[index], target, n);
            return dp[index][curr + sum] = addition + subraction;
       }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long int sum = 0;
        int n = nums.size();

        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
        }

        vector<vector<int>> dp(n + 1,vector<int>(2 * sum + 1, -1));
        return helper(nums, dp, sum, 0, 0, target, n);
    }
};