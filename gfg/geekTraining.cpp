// problem link
// https://www.geeksforgeeks.org/problems/geeks-training/1
// top down approach
class Solution {
  public:
  int helper(vector<vector<int>> &arr,vector<vector<int>> &dp,int n,int last)
  {
      if(n == 0)
      {
          int ans=INT_MIN;
          for(int i=0;i<3;i++)
          {
              if(i != last)
              {
                  ans=max(ans,arr[0][i]);
              }
          }
          dp[0][last] = ans;
          return ans;
      }
      else if(dp[n][last] != -1)
      {
          return dp[n][last];
      }
      else
      {
          int points = INT_MIN;
          for(int i=0;i<3;i++)
          {
              if(i != last)
              { 
                 points=max(points,arr[n][i] + helper(arr,dp,n-1,i));
              }
          }
          dp[n][last] = points;
          return dp[n][last];
      }
  }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return helper(arr,dp,n-1,3);
    }
};
// bottom up approach
