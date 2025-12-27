// prolem link: https://leetcode.com/problems/longest-palindromic-subsequence/
// brute force approach using recursion
class Solution {
public:

    bool isPalindrome(string s){
        int start = 0,end = s.size() - 1;
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int helper(string s,string temp, int index, int n){
        if(index >= n){
            bool validPalindrome = isPalindrome(temp);
            if(validPalindrome){
                return temp.size();
            }
            else{
                return 0;
            }
        }
        else{
            int includes = helper(s,temp + s[index], index + 1, n);
            int notIncludes = helper(s, temp, index + 1, n);
            return max(includes, notIncludes);
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        return helper(s, "", 0, n);
    }
};
// another way to solver using lcs approach
class Solution {
public:

    int helper(vector<vector<int>> &dp, string &s1, string &s2, int index1, int index2){
        if(index1 < 0 || index2 < 0){
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        else{
            if(s1[index1] == s2[index2]){
                return dp[index1][index2] = 1 + helper(dp, s1, s2, index1 - 1, index2 - 1);
            }
            else{
                return dp[index1][index2] = max(helper(dp, s1, s2, index1 - 1, index2), helper(dp, s1, s2, index1, index2 - 1));
            }
        }
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        int index1 = s1.size() - 1;
        int index2 = s.size() - 1;

        vector<vector<int>> dp(index1 + 1,vector<int>(index2 + 1, -1));
        return helper(dp, s1, s, index1, index2);  
    }
};
//another way tabulation approach
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());

        int index1 = s1.size();
        int index2 = s.size();

        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, 0));

        for(int i = 1;i <= index1;i++){

            for(int j = 1;j <= index2;j++){
                if(s1[i - 1] == s[j - 1]){

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                }
            }
        }
        return dp[index1][index2];
    }
};