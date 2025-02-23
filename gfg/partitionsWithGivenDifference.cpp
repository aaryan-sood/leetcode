// problem link
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
class Solution {
    public:
      int helper(int sum,vector<int> &temp,vector<vector<int>> &dp,int target,int i,int n)
      {
          if(sum == target)
          {
              return 1;
          }
          if(sum > target || i < 0)
          {
              return 0;
          }
          if(dp[sum][i] != -1)
          {
              return dp[sum][i];
          }
          else
          {
              int left = helper(sum,temp,dp,target,i-1,n);
              int taken = helper(sum+temp[i],temp,dp,target,i-1,n);
              return dp[target][i]=left + taken;
          }
      }
      int countPartitions(vector<int>& arr, int d) {
          // Code here
          int zeroCount = 0;
          vector<int> temp;
          int sum = 0;
          int n=arr.size();
          for(int i= 0;i<n;i++)
          {
              if(arr[i] == 0)
              {
                  zeroCount++;
              }
              else
              {
                  sum+=arr[i];
                  temp.push_back(arr[i]);
              }
          }
          if((sum + d) % 2 != 0)
          {
              return 0;
          }
              int target = (sum + d)/2;
              int m = temp.size();
              
              vector<vector<int>> dp(target+1,vector<int>(m,-1));
              int ans = helper(0,temp,dp,target,m-1,m);
              
              return (1 << zeroCount) * ans;
          
          
          
      }
  };