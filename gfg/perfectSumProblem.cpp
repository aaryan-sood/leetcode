// problem link
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
class Solution {
  public:
    int helper(vector<int> &arr, vector<vector<int>> &dp, int target, int i) {
        if (target == 0) {
            return 1; 
        }
        if (i < 0 || target < 0) {
            return 0; 
        }
        if (dp[target][i] != -1) {
            return dp[target][i]; 
        }
        int taken = helper(arr, dp, target - arr[i], i - 1);
        int notTaken = helper(arr, dp, target, i - 1);
        
        dp[target][i] = taken + notTaken;
        return dp[target][i];
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        if (n == 0) return 0;
        
        int zeroCount = 0;
        for (int x : arr) {
            if (x == 0) zeroCount++;
        }
        
        vector<int> filteredArr;
        for (int x : arr) {
            if (x != 0) filteredArr.push_back(x);
        }

        int m = filteredArr.size();
        vector<vector<int>> dp(target + 1, vector<int>(m, -1));
        
        int result = helper(filteredArr, dp, target, m - 1);

        // Multiply result by 2^zeroCount to account for all combinations of zeros
        return result * (1 << zeroCount);
    }
};