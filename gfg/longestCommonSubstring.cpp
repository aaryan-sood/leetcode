class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int index1 = s1.size();
        int index2 = s2.size();
        int ans = 0;
        vector<vector<int>> dp(index1 + 1,vector<int>(index2 + 1, 0));
        
        for(int i = 1;i <= index1;i++){
            
            for(int j = 1;j <= index2;j++){
                
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};