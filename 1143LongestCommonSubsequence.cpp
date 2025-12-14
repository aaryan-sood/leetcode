// 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
public:

    int helper(vector<vector<int>> &dp, string &text1, string &text2, int index1, int index2){
        
        if(index1 < 0 || index2 < 0){
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        else{
            
            if(text1[index1] == text2[index2]){
                return dp[index1][index2] =  1 + helper(dp, text1, text2, index1 - 1, index2 -1);
            }
            return dp[index1][index2] =  max(helper(dp, text1, text2, index1 - 1, index2), helper(dp, text1, text2, index1, index2 - 1));
        }
    
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int index1 = text1.size() - 1;
        int index2 = text2.size() - 1;

        // dp matrix of size index1 *index2(0...index - 1,0...index2 - 1)
        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, -1));
        return helper(dp, text1, text2, index1, index2);

    }
};