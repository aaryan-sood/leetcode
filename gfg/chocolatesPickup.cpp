// problem link
// https://www.geeksforgeeks.org/problems/chocolates-pickup/1
class Solution {
  public:
    int helper(vector<vector<int>> &grid,vector<vector<vector<int>>> &dp,int i,int j,int j1,int n,int m)
    {
        if(i == n-1 && j >= 0 && j < m && j1 >= 0 && j1 < m)
        {
            if(j == j1)
            {
                return dp[i][j][j1] = grid[i][j];
            }
            else
            {
                return dp[i][j][j1] = grid[i][j] + grid[i][j1];
            }
        }
        if(j < 0 || j1 < 0 || j >=m || j1 >= m)
        {
            return -1e9;
        }
        if(dp[i][j][j1] != -1)
        {
            return dp[i][j][j1];
        }
        else
        {
            vector<int> dx={-1,0,1};
            int ans=INT_MIN;
            for(int k=0;k<dx.size();k++)
            {
                for(int w=0;w<dx.size();w++)
                {
                    int new_j=j+dx[k];
                    int new_j1=j1+dx[w];
                    if(j == j1)
                    {
                        ans=max(ans,grid[i][j] + helper(grid,dp,i+1,new_j,new_j1,n,m));
                    }
                    else
                    {
                        ans = max(ans,grid[i][j] + grid[i][j1] + helper(grid,dp,i+1,new_j,new_j1,n,m));

                    }
                }
            }
            return dp[i][j][j1]=ans;
        }
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(grid,dp,0,0,m-1,n,m);
        
    }
};