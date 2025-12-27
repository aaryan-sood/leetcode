// problem link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        
        int n = t.size();
        int m = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1;i <= n; i++){

            for(int j = 1; j <= m;j++){

                if(t[i - 1] == s[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return n - dp[n][m];
    }
};