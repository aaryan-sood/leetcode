// unbounded knapsack
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int helper(vector<int> &wt, vector<int> &val, vector<vector<int>> &dp, int index, int currWt)
  {

    if (index == 0)
    {
      return dp[0][currWt] = (currWt / wt[index]) * val[index];
    }
    if(currWt == 0)
    {
        return dp[index][0] = 0;
    }
    if (dp[index][currWt] != -1)
    {
      return dp[index][currWt];
    }
    else
    {
      int notTaken = 0 + helper(wt,val,dp,index - 1,currWt);
      int repeated = INT_MIN;
      if(currWt - wt[index] >= 0)
      {
        repeated = val[index] + helper(wt,val,dp,index,currWt - wt[index]);
      } 
      return dp[index][currWt] = max(notTaken,repeated);
    }
  }
  int knapSack(vector<int> &val, vector<int> &wt, int capacity)
  {
    // code here
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return helper(wt, val, dp, n - 1, capacity);
  }
};