// problem link
// https://leetcode.com/problems/minimum-path-sum/description/
// top down approach
class Solution {
    int helper(vector<vector<int>> &grid,vector<vector<int>> &dp,int n,int m)
    {
        if(n == 0 && m == 0)
        {
            return grid[0][0];
        }
        if(n < 0 || m < 0)
        {
            return 1e9;
        }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        else
        {
            int left=helper(grid,dp,n,m-1);
            int up=helper(grid,dp,n-1,m);
            return dp[n][m]=min(grid[n][m] + up,grid[n][m] + left);
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0] = grid[0][0];
        return helper(grid,dp,n-1,m-1);
    }
};
// bottom up approach
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(i == 1 && j == 1)
                {
                    dp[1][1] = grid[0][0];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j] + grid[i-1][j-1],dp[i][j-1] + grid[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};