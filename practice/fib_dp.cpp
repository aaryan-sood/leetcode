#include<bits/stdc++.h>
using namespace std ;
// top down approach
int findFib(vector<int> &dp,int n)
{
    if(n <= 1)
    {
        return n;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] =  findFib(dp,n - 1) + findFib(dp,n - 2);
        return dp[n];
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    // findFib(dp,n);
    // bottom up approach
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n+1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // more optimised approach
    int prev = 1,second_prev = 0;
    int ans;
    for (int i = 2; i < n+1; i++)
    {
        ans=prev + second_prev;
        second_prev = prev;
        prev = ans;

    }
    cout<<ans<<endl;
    cout<<dp[n]<<endl;
    return 0;
}