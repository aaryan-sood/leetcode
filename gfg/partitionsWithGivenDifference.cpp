// problem link
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
class Solution {
    public:
      int helper(vector<int> &newArr,vector<vector<int>> &dp,int sum1,int target,int index,int m)
      {
          if(sum1 == target)
          {
              return 1;
          }
          if(sum1 > target || index >= m)
          {
              return 0;
          }
          if(dp[sum1][index] != -1)
          {
              return dp[sum1][index];
          }
          else
          {
              int include = helper(newArr,dp,sum1+newArr[index],target,index + 1,m);
              int exclude = helper(newArr,dp,sum1,target,index + 1,m);
              return dp[sum1][index]=include + exclude;
          }
      }
      int countPartitions(vector<int>& arr, int d) {
          // Code here
          vector<int> newArr;
          int count = 0;
          int n=arr.size();
          int sum = 0;
          for(int i=0;i<n;i++)
          {
              sum += arr[i];
          }
          for(int i=0;i<n;i++)
          {
              if(arr[i] == 0)
              {
                  count++;
              }
              else
              {
                  newArr.push_back(arr[i]);
              }
          }
          if((sum + d) % 2 != 0)
          {
              return 0;
          }
          
          int target = (sum + d)/2; 
          int m = newArr.size();
          
          vector<vector<int>> dp(target+1,vector<int>(m,-1));
          
          int ans = helper(newArr,dp,0,target,0,m);
          
          return (1 << count) * ans;
      }
  };