// recursion
class Solution {
public:
    int helper(vector<vector<int>> &obstacleGrid,int n,int m)
    {
        if(n == 0 && m == 0)
        {
            if(obstacleGrid[0][0] == 0)
            {
                return 1;
            }
            if(obstacleGrid[0][0] == 1)
            {
                return 0;
            }
        }
        if(n < 0 || m < 0)
        {
            return 0;
        }
        else
        {
            int up=0,left=0;
            if(n-1 >= 0 && obstacleGrid[n-1][m] == 0)
            {
                up = helper(obstacleGrid,n-1,m);
            }
            if(m - 1 >= 0 && obstacleGrid[n][m-1] == 0)
            {
                left = helper(obstacleGrid,n,m-1);
            }
            return up+left;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        return helper(obstacleGrid,n-1,m-1);
    }
};
// top down approach
class Solution {
public:
    int helper(vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp,int n,int m)
    {
        if(n == 0 && m == 0)
        {
            if(obstacleGrid[0][0] == 0)
            {
                return dp[n][m] = 1;
            }
            if(obstacleGrid[0][0] == 1)
            {
                return dp[n][m] = 0;
            }
        }
        if(n < 0 || m < 0)
        {
            return 0;
        }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        else
        {
            int up=0,left=0;
            if(n-1 >= 0 && obstacleGrid[n-1][m] == 0)
            {
                up = helper(obstacleGrid,dp,n-1,m);
            }
            if(m - 1 >= 0 && obstacleGrid[n][m-1] == 0)
            {
                left = helper(obstacleGrid,dp,n,m-1);
            }
            return dp[n][m] = up+left;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(obstacleGrid,dp,n-1,m-1);
    }
};  
// bottom up approach
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[1][1] = 1;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(i == 1 && j == 1)
                {
                    dp[1][1] = 1;
                }
                else if(obstacleGrid[i-1][j-1] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};