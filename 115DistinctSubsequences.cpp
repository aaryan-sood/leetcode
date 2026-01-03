// problem link
// https://leetcode.com/problems/distinct-subsequences/submissions/1873262001/
// memoization approach
class Solution {
public:
    int helper(vector<vector<int>> &dp, string &s, string &t, int i, int j){

        if(j < 0){
            return 1;
        }
        if(i < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = helper(dp, s, t, i - 1, j - 1) + helper(dp, s, t, i - 1, j);
        }
        else{
            return dp[i][j] = helper(dp, s, t, i - 1, j);
        }

    }
    int numDistinct(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;
        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
        return helper(dp, s, t, i, j);
    }
};

// tabulation approach
class Solution {
public:

    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n + 1,vector<double>(m + 1, 0));

        for(int i = 0;i <= n;i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};