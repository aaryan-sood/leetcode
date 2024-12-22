//problem link
// https://leetcode.com/problems/house-robber/description/
// top down approach
class Solution {
public:
    int helper(vector<int> &nums,vector<int> &dp,int n)
    {
        if(n == 0 || n == 1)
        {
            if(n == 0)
            return nums[0];
            else
            return max(nums[0],nums[1]);
        }
        else if(dp[n] != -1)
        {
            return dp[n];
        }
        else
        {
            int ans;
            ans=max(helper(nums,dp,n-1),helper(nums,dp,n-2) + nums[n]);
            dp[n]=ans;
            return ans;
        }
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1 || n == 2)
        {
            if(n == 1)
            return nums[0];
            else
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n,-1);
        helper(nums,dp,n-1);
        return dp[n-1];
    }
};
// bottom down approach
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1 || n == 2)
        {
            if(n == 1)
            return nums[0];
            else
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};