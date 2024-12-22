// problem link
// https://www.geeksforgeeks.org/problems/minimal-cost/1
class Solution {
  public:
    int helper(vector<int> &arr,vector<int> &dp,int n,int k)
    {
        if(n == 0)
        {
            return 0;
        }
        else if(dp[n] != -1)
        {
            return dp[n];
        }
        else
        {
            int ans=INT_MAX;
            for(int i=1;i<k+1;i++)
            {
                if(n - i >= 0)
                ans=min(ans,helper(arr,dp,n-i,k));
            }
            dp[n] = ans;
            return ans;
        }
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int> dp(arr.size(),-1);
        int n=arr.size();
        dp[0] = 0;
        helper(arr,dp,n-1,k);
        return dp[n-1];
    }
};
// bottom up approach
lass Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        if(n == 1)
        {
            return 0;
        }
        vector<int> dp(n,-1);
        dp[0] = 0;
        dp[1] = abs(arr[1] - arr[0]);
        
        for(int i=2;i<n;i++)
        {
            int ans=INT_MAX;
            for(int j=1;j<k+1;j++)
            {
                if(i - j >= 0)
                ans=min(ans,dp[i-j] + abs(arr[i] - arr[i-j]));
            }
            dp[i] = ans;
        }
        return dp[n-1];
    }
};