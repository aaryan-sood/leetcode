// problem link
// https://leetcode.com/problems/shortest-common-supersequence/description/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int index1 = str1.length();
        int index2 = str2.length();

        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, 0));

        for(int i = 1; i <= index1; i++){

            for(int j = 1;j <= index2; j++){

                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = index1, j = index2;
        string ans;
        while(i > 0 && j > 0){

            if(str1[i - 1] == str2[j - 1]){
                ans += str1[i - 1];
                i--;
                j--;
            }
            else{
                if(dp[i - 1][j] > dp[i][j - 1]){
                    ans += str1[i - 1];
                    i--;
                }
                else{
                    ans += str2[j - 1];
                    j--;
                }
            }
        }
        while(i != 0){
            ans += str1[i - 1];
            i--;
        }
        while(j != 0){
            ans += str2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};