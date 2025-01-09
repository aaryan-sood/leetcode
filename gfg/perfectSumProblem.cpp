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
        int n=arr.size();
        
        if(n == 0) return 0;
        
        int zeroCount = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
            {
                zeroCount++;
            }
        }
        
        vector<int> filterArr;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] != 0)
            {
                filterArr.push_back(arr[i]);
            }
        }
        
        int m=filterArr.size();
        if(m == 0)
        {
            return (1 << zeroCount);
        }
        vector<vector<int>> dp(target + 1,vector<int>(m,-1));
        
        // number of subsets which sum to 0
        for(int i = 0;i<dp[0].size();i++)
        {
            dp[0][i] = 1;
        }
        
        // number of subsets which sum to 0 to target with first element
        for(int i=1;i<dp.size();i++)
        {
            if(filterArr[0] == i)
            {
                dp[i][0] = 1;
            }
            else
            {
                dp[i][0] = 0;
            }
        }
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                int exclude = dp[i][j-1];
                int include = 0;
                if(i - filterArr[j] >= 0)
                {
                    include = dp[i - filterArr[j]][j-1];
                }
                dp[i][j] = include + exclude;
                
            }
        }
        
        
        return dp[target][m-1] * (1 << zeroCount);
    }
};
