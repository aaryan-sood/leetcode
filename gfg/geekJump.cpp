// problem link
// https://www.geeksforgeeks.org/problems/geek-jump/1
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,0);
        dp[1] = abs(height[1] - height[0]);
        for(int i=2;i<n;i++)
        {
            dp[i] = min(dp[i-1] + abs(height[i-1] - height[i]),dp[i-2] + abs(height[i-2] + height[i]));
        }
        return dp[n-1];
    }
}