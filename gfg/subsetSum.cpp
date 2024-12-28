// problem link
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
class Solution {
  public:
    bool helper(vector<int> &arr,vector<vector<int>> &dp,int i,int target,int n)
    {
        if(target == 0)
        {
            return true;
        }
        if(target < 0 || i >= n)
        {
            return false;
        }
        if(dp[target][i] != -1)
        {
            return dp[target][i];
        }   
        else
        {
            bool include=false;
            if(target >= arr[i])
            include = helper(arr,dp,i+1,target-arr[i],n);
            bool exclude =helper(arr,dp,i+1,target,n);
            return dp[target][i]=include || exclude;
        }
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(target+1,vector<int>(n,-1));
        
        // filling up the values in the first row
        for(int i=0;i<dp[0].size();i++)
        {
            dp[0][i] = 1;
        }
        
        // filling up the values in the first column
        for(int i=1;i<dp.size();i++)
        {
            if(i == arr[0])
            {
                dp[i][0] = 1;
            }
            else
            {
                dp[i][0] = 0;
            }
        }
        
        // filling up the rest of the matrix
        for(int i = 1;i < dp.size(); i++)
        {
            for(int j = 1; j < dp[0].size(); j++)
            {
                
                if(dp[i][j-1] == 1)
                {
                    dp[i][j] = 1;
                }
                else if(i - arr[j] < 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i][j-1] || dp[i - arr[j]][j-1];
                }
            }
        }
        return dp[target][n-1];
        // return helper(arr,dp,0,target,n);
    }
};