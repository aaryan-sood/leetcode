// problem link
// https://leetcode.com/problems/unique-paths/description/
class Solution {
public:
    int helper(vector<vector<int>> &dp,int m,int n)
    {
        if(m == 1 && n == 1)
        {
            dp[1][1] =1;
            return 1;
        }
        else if(m <= 0 || n <= 0)
        {
            if(m >= 0 && n>= 0)
            {
                dp[m][n]= 0;
            }
            return 0;
        }
        else if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        else
        {
            int ans=helper(dp,m-1,n) + helper(dp,m,n-1);
            dp[m][n] = ans;
            return ans;
        }
    }
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1)
        {
            return 1;
        }
       vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       return helper(dp,m,n);
    }
};
//bottom up approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[1][1] = 1;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i == 1 && j == 1)
                {
                    dp[1][1] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};